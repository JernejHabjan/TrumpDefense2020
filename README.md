[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/JernejHabjan/TrumpDefense2020/blob/master/LICENSE)
# Trump Defense 2020

**Author**: 
*Jernej Habjan*

**Title**:
- Učenje realno-časovne strateške igre z uporabo globokega spodbujevalnega učenja
- Teaching of real-time strategy game using deep reinforcement learning

#Navigation
- [Quick overview](#quick-overview)
    - [Features](#features)
- [Startup Guide](#startup-guide)
    - [Visual Studio](#visual-studio)
    - [Anaconda](#anaconda)
    - [Unreal Engine](#unreal-engine)
    - [PyTorch](#pytorch)
    - [TensorFlow GPU](#tensorflow-gpu)
- [Publishing](#publishing)
    - [Dedicated server](#dedicated-server)
        - [Build dedicated server and client game](#build-dedicated-server-and-client-game)
        - [Port forwarding and firewall](#port-forwarding-and-firewall)
        - [Check server availability](#check-server-availability)
- [Sources](#sources)
    - [Plugins used](#plugins-used)
    - [Repositories used](#repositories-used)
    - [Video tutorials followed](#video-tutorials-followed)
- [License](#license)

# Quick overview
Visual representation of RTS game, supported by deep reinforcement learning algorithm Alpha Zero written in python.

### Features:
- Keyboard, mouse camera movement
- Minimap with optional Fog of War
- Unit creation
- Building placement
- Resource mining
- Attacking
- Unit control (control groups)
- Support for online play
- Day-night cycle

# Startup Guide
## Visual Studio
install Visual Studio
- install "Windows 8.1 sdk"
- install "Windows 10 sdk (10.0.15063.0)"


## Unreal Engine
- install unreal engine from Epic Launcher or download source from [GitHub](https://github.com/EpicGames/UnrealEngine/)
- install VaRest plugin for engine
- install Kantan Charts plugin for engine
- if source code engine has been downloaded, you have to copy plugins that are downloaded in Epic Launcher engine and paste them in source code one in Plugins folder
## Python
### Python 3.6
- Download and install python 3.6 for plugin UnrealEnginePython in
>C:\Program Files\Python36
- Add it to environmental path
### Anaconda
Install anaconda with python 3.6 -- make sure its 64 bit if using 64 bit windows
- Install it in:
>C:\ProgramData\Anaconda3
- add this path under environmental variables folder

### PyTorch
Install Python dev environment
https://developer.nvidia.com/how-to-cuda-python

type this in anaconda prompt with admin rights
```
conda update conda
conda install numba
conda install cudatoolkit
conda install -c peterjc123 pytorch cuda90 
```



### TensorFlow and CUDA
Install cuda:
- From programs disk install these files in this order:
- cuda_9.0.176_win10
- cuda_9.0.176.1_windows
- cuda_9.0.176.2_windows
- cuda_9.0.176.3_windows
- Extract this folder and add it to Cuda path to corresponding folders:
    - cudnn-9.0-windows10-x64-v7.1

vertify cuda installation:
- nvcc --version

- make sure its added to env variables:
```
- C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0\bin
- C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0\libnvvp
```
#### TensorFlow Gpu
- Todo - check if i can only import whole conda environment from below tutorial
- Install tensorflow in pycharm and not from conda cmd (launch it in admin)
- Interpreter-> check "Use conda package manager button" on the right,
- add package -> tensorflow-gpu, tensorflow, tensorboard, keras 2.13 - version is important!




### Graphviz and pydot:
```
conda install graphviz
conda install pydot
```
Download Graphviz executable from [Here](https://graphviz.gitlab.io/_pages/Download/Download_windows.html)

Add path to environmental variables and !important! restart Pycharm
```
C:\Program Files (x86)\Graphviz2.38\bin
```

## Conda export
to export form conda cmd
```cmd
conda list --explicit > requirements.txt
```
to install on other machine
```
conda create --name myenv --file requirements.txt
activate myenv
```
Requirements are in _Files folder as requirements.txt

# Publishing
## Setup
- If source engine is not on disk
    - download [source](https://github.com/EpicGames/UnrealEngine/releases)
    - run Setup.bat
    - run GenerateProjectFiles.bat
- Switch project version to source engine
- Generate solution
- Open UE4 solution
	- Development editor - win64 build to see if there are any errors
    - close solution
## Client game
- Open project normally in editor using source engine code as version
    - package project normally in win64
## Dedicated server
### Build dedicated server
- Regenerate visual studio project
- Open solution
    - build using development server option to build dedicated server
    - close solution
- Copy files "Server" from TD2020/Binaries/WIn64/ (all 4) to Publish/TD2020/Binaries/Win64/
- Create shortcut of server and add at the end -log with prefix space
### Port forwarding and firewall

Fix port forwarding on your router
- Ue4
    - ip - ip of computer (local)
    - 27015 - internal port
    - 27015 - external port
    - protocol both

- Steam
    - ip - ip of computer (local)
    - 7777 - internal port
    - 7777 - external port
    - protocol both
	
Windows firewall
    - navigate to advanced settings-inbound rules - new rule - port
    - make 4 combinations - udp and tcp for both ue4 and steam
### Check server availability
- Steam - View -Servers- Lan and internet
- If server is visible on lan but not on internet - check port forwarding - TODO - HAVEN'T SOLVED THIS YET
    - https://youtu.be/iMNjp5L7_oA - check comments here for solving issue with displaying on steam internet
- Open game using:
```
open 127.0.0.1:7777
```
#### *Optional* Build using Unreal Frontend

It's located in
>UE4EngineSourceCode/engine/binaries/win64/UnrealFrontend.exe
- if you don't have it - visual studio - class view - unreal frontend - right click and build, and then you can access it
- open UnrealFrontend.exe
- add custom Launch profile:
    - Project - browse to your project and select Uproject File
- Do you wish to build -try without , but if errors - yes - in development 
 
- Cook - by the book 
    - windows server
    - select en at the bottom
- Cooked maps show all - check all
- package - don't
- deploy - don't
- rename it on top:

- close this and click on newly created "launch profile"
- if errors when launching, Run it as build, or not...
## Add .dll libraries
Add python36.dll (64 - bit) to 
>YourProject/Publish/WindowsNoEditor/TD2020/Binaries/Win64/

# Sources:
## Plugins used
- [Kantan charts](https://www.unrealengine.com/marketplace/kantan-charts)
- [VaRest](https://www.unrealengine.com/marketplace/varest-plugin)
- [Advanced Sessions plugin](https://forums.unrealengine.com/community/community-content-tools-and-tutorials/41043-advanced-sessions-plugin) - Downloaded for 4.18
## Repositories used
- [UnrealEnginePython](https://github.com/20tab/UnrealEnginePython) - using source code to package project (with binary, project cannot be packaged) - Source code used on 2018.06.07
- [SimpleRTS](https://github.com/npruehs/ue4-rts)
- [alpha-zero-general](https://github.com/suragnair/alpha-zero-general)
- [AppliedDataSciencePartners / DeepReinforcementLearning](https://github.com/AppliedDataSciencePartners/DeepReinforcementLearning)
- [jdori / DeepReinforcementLearning]()https://github.com/jdori/DeepReinforcementLearning) - fixed DeepReinforcementLearning repository from AppliedDataSciencePartners for python 3

## Video tutorials followed
- [Unreal Engine](https://www.youtube.com/user/UnrealDevelopmentKit),
- [pally qle](https://www.youtube.com/channel/UCIEqFMmWhxF4yA4gowhFjNA),
- [3 Prong Gaming](https://www.youtube.com/user/ShortBusTrip).


# License
```
MIT License

Copyright (c) 2018 Jernej Habjan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```