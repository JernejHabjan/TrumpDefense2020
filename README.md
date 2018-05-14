# TrumpDefense2020

Author: Jernej Habjan

Plugins used: 

- Kantan charts https://www.unrealengine.com/marketplace/kantan-charts
- VaRest https://www.unrealengine.com/marketplace/varest-plugin


Repositories forked:
- UnrealEnginePython - using source code to package project (with binary, project cannot be packaged) https://github.com/20tab/UnrealEnginePython
- SimpleRTS https://github.com/npruehs/ue4-rts
- alpha zero general https://github.com/suragnair/alpha-zero-general
- applied data Deep reinforcement learning https://github.com/AppliedDataSciencePartners/DeepReinforcementLearning
- fixed applied data Deep reinforcement learning python 3 https://github.com/jdori/DeepReinforcementLearning

Followed video tutorials by Unreal Engine, Pally qle, 3 Prong Gaming


Title:
- Učenje realno-časovne strateške igre z uporabo globokega spodbujevalnega učenja
- Teaching of real-time strategy game using deep reinforcement learning

Visual representation of RTS game, supported by deep reinforcement learning algorithm Alpha Zero written in python.

Features:
- Keyboard, mouse camera movement
- Minimap with Fog of War
- Unit creation
- Building placement
- Resource mining
- Attacking
- Unit control (control groups)
- Support for online play

#Content


#Install Guide
##install visual studio
- instal "Windows 8.1 sdk"
- instal "Windows 10 sdk (10.0.15063.0)"

##install anaconda with python 3.6 -- make sure its 64 bit if using 64 bit windows
- Install it in:
- C:\ProgramData\Anaconda3
- add this path under enviromental variables folder

##install unreal engine
- install vaRest plugin for engine
- install katan charts plugin for engine



## PyInstaller

cmd run as admin
pip install pyinstaller

Go to your program’s directory and run:
pyinstaller yourprogram.py
This will generate the bundle in a subdirectory called dist.

## Install python dev enviroment
 	https://developer.nvidia.com/how-to-cuda-python
	
	potegn anaconda
	z admin rights:
	pol v command od anaconde -> conda update conda
		conda install numba
		conda install cudatoolkit
	
		conda install -c peterjc123 pytorch cuda90 
		
### TensorFlow GPU
good tutorial http://www.python36.com/install-tensorflow-gpu-windows/


pip install --ignore-installed --upgrade tensorflow-gpu 
 cuda 9.0 https://developer.nvidia.com/cuda-90-download-archive?target_os=Windows&target_arch=x86_64&target_version=10&target_type=exenetwork

 
 add it to enviromental variables:
 C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\bin
 C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\lib\x64
 
 
 then download this this ->
https://developer.nvidia.com/rdp/cudnn-download
in pol extractaš file, pa jih daš v corresponding folderje v ->  C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\





