#!/bin/bash



echo Deleting Junk
echo .
echo ..
echo ...
rm -rf ./saved/
rm -rf ./build/
rm -rf ./intermediate/
rm -rf ./binaries/
rm -rf ./DerivedDataCache/
rm -rf ./Debug/
rm -rf ./.vs/
rm -rf ./.git/



rm -rf ./Plugins/UnrealEnginePython/binaries/
rm -rf ./Plugins/UnrealEnginePython/tutorials/
rm -rf ./Plugins/UnrealEnginePython/intermediate/
rm -rf ./Plugins/UnrealEnginePython/screenshots/



find . -name "*.log" -exec rm {} \;
find . -name "*.sln" -exec rm {} \;
find . -name "*nul" -exec rm {} \;
find . -name ".gitignore" -exec rm {} \;
find . -name "*.VC.db" -exec rm {} \;
find . -name "*.opensdf" -exec rm {} \;
find . -name "*.opendb" -exec rm {} \;
find . -name "*.suo" -exec rm {} \;
find . -name "*.sdf" -exec rm {} \;
find . -name "*.xcodeproj" -exec rm {} \;
find . -name "*.xcworkspace" -exec rm {} \;




echo Project at minimum size
echo Goodbye
