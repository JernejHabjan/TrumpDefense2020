[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/JernejHabjan/TrumpDefense2020/blob/master/LICENSE)
# Trump Defense 2020

**Author**: 
*Jernej Habjan*

**Title**:
- Učenje realno-časovne strateške igre z uporabo globokega spodbujevalnega učenja
- Teaching of real-time strategy game using deep reinforcement learning

#Navigation
- [Quick overview](quick-overview)
    - [Features](features)
- [Startup Guide](startup-guide)
    - [Visual Studio](visual-studio)
    - [Anaconda](anaconda)
    - [Unreal Engine](unreal-engine)
    - [PyInstaller](pyinstaller)
    - [PyTorch](pytorch)
    - [TensorFlow GPU](tensorflow-gpu)
- [Sources](sources)
- [License](license)

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

#Startup Guide
##Visual Studio
install Visual Studio
- install "Windows 8.1 sdk"
- install "Windows 10 sdk (10.0.15063.0)"

##Anaconda
Install anaconda with python 3.6 -- make sure its 64 bit if using 64 bit windows
- Install it in:
>C:\ProgramData\Anaconda3
- add this path under environmental variables folder

##Unreal Engine
install unreal engine
- install VaRest plugin for engine
- install Kantan Charts plugin for engine

##PyInstaller

cmd run as admin
```
pip install pyinstaller
```
Go to your program’s directory and run:
```
pyinstaller yourprogram.py
```
This will generate the bundle in a subdirectory called dist.

## PyTorch
Install Python dev environment
https://developer.nvidia.com/how-to-cuda-python

Download Anaconda

type this in anaconda prompt with admin rights
```
conda update conda
conda install numba
conda install cudatoolkit
conda install -c peterjc123 pytorch cuda90 
```
	
		
### TensorFlow GPU
good tutorial 
http://www.python36.com/install-tensorflow-gpu-windows/

```
pip install --ignore-installed --upgrade tensorflow-gpu cuda 9.0 
 https://developer.nvidia.com/cuda-90-download-archive?target_os=Windows&target_arch=x86_64&target_version=10&target_type=exenetwork
```
 
add it to environmental variables:
```
C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\bin
C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\lib\x64
``` 
 
- then download this:
https://developer.nvidia.com/rdp/cudnn-download

-extract file, add it in corresponding folder in 
>C:\Program Files\NVIDIA GPU Computing Toolkit\Cuda\v9.0\



#Sources:
Plugins used: 
- [Kantan charts](https://www.unrealengine.com/marketplace/kantan-charts)
- [VaRest](https://www.unrealengine.com/marketplace/varest-plugin)

Repositories used:
- [UnrealEnginePython](https://github.com/20tab/UnrealEnginePython) - using source code to package project (with binary, project cannot be packaged)
- [SimpleRTS](https://github.com/npruehs/ue4-rts)
- [alpha-zero-general](https://github.com/suragnair/alpha-zero-general)
- [AppliedDataSciencePartners / DeepReinforcementLearning](https://github.com/AppliedDataSciencePartners/DeepReinforcementLearning)
- [jdori / DeepReinforcementLearning]()https://github.com/jdori/DeepReinforcementLearning) - fixed DeepReinforcementLearning repository from AppliedDataSciencePartners for python 3

Video tutorials followed:
- [Unreal Engine](https://www.youtube.com/user/UnrealDevelopmentKit),
- [pally qle](https://www.youtube.com/channel/UCIEqFMmWhxF4yA4gowhFjNA),
- [3 Prong Gaming](https://www.youtube.com/user/ShortBusTrip).


#License
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