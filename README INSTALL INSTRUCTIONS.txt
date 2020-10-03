1. download td2020
2. download python 3.6 and install it for all users 64 bit.
3. initialize alphazero repo (git submodule)
4. initialize rts repo (git submodule)
    - Add this code to RTSPlayerController.cpp:
    void ARTSPlayerController::BeginPlay()
    {
        Super::BeginPlay();
        if (!PlayerResourcesComponent) {
            return;
        }  
5. Fix Plugin symlink - go to TrumpDefense2020 folder and open cmd:
    git config core.symlinks true
    Then delete RealTimeStrategy in TrumpDefense2020/TD2020/Plugins if file (it should be folder) and check it out again
    If that fails use this command in TD2020/Plugins folder:
        mklink /D "RealTimeStrategy" "..\..\ue4-rts\Source\RTSProject\Plugins\RealTimeStrategy" (open cmd as admin)
6. Install UE4 4.25.3
    Tensorflow not supported in this version yet
        https://github.com/getnamo/tensorflow-ue4/issues/56
        But when enabled: 
            5. download release https://github.com/getnamo/tensorflow-ue4/releases/tag/0.13.0 and folder 'Plugins' add it to TrumpDefense2020/TD2020
        - reenable CmpTensorflow component in Py folder in plugins - check for
            "REENABLE THIS WHEN PARENT IS TENSORFLOW COMPONENT"
7. Use VS 2019 with "Game development with C++"
8. run