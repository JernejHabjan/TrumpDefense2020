1. download td2020
2. download python 3.6 and install it for all users 64 bit.
3. initialize alphazero repo (git submodule)
FOR UE4 4.21
    4. Install UE4 4.21.2
    IF NEEDED TENSORFLOW:
        5. download release https://github.com/getnamo/tensorflow-ue4/releases/tag/0.11.0 and folder 'Plugins' add it to TrumpDefense2020/TD2020
        - reenable CmpTensorflow component in Py folder in plugins - check for
            "REENABLE THIS WHEN PARENT IS TEMSORFLOW COMPONENT"
    - Add rts plugin:
        (latest 4.21 plugin)
        https://github.com/npruehs/ue4-rts/commit/fdcb8ae4b3810b5a9c4dbae00084404815845797
        - Add this code to RTSPlayerController.cpp:
            void ARTSPlayerController::BeginPlay()
            {
                Super::BeginPlay();
                if (!PlayerResourcesComponent || !PlayerResourcesComponent->IsValidLowLevel()) {
                    return;
                }
FOR UE4 4.22
    4. Install UE4 4.22.3
    IF NEEDED TENSORFLOW:
        5. download release https://github.com/getnamo/tensorflow-ue4/releases/tag/0.13.0 and folder 'Plugins' add it to TrumpDefense2020/TD2020
        - reenable CmpTensorflow component in Py folder in plugins - check for
            "REENABLE THIS WHEN PARENT IS TEMSORFLOW COMPONENT"
    6. use ue4-rts plugin:
        (latest 4.22 plugin)
        https://github.com/npruehs/ue4-rts/commit/6dfa12de6ee60f50b97741105012e8b7b83c3762
        - Add this code to RTSPlayerController.cpp:
            void ARTSPlayerController::BeginPlay()
            {
                Super::BeginPlay();
                if (!PlayerResourcesComponent || !PlayerResourcesComponent->IsValidLowLevel()) {
                    return;
                }
7. Use VS 2019 with "Game development with C++"
8. run