#!/bin/bash



echo Deleting Junk
echo .
echo ..
echo ...
rm -rf ./TD2020/saved/Autosaves/
rm -rf ./TD2020/saved/Backup/
rm -rf ./TD2020/saved/Collections/
rm -rf ./TD2020/saved/Logs/
rm -rf ./TD2020/saved/StagedBuilds/
rm -rf ./TD2020/saved/Crashes/
rm -rf ./TD2020/saved/Cooked/
rm -rf ./TD2020/saved/Config/CrashReportClient/
     
rm -rf ./TD2020/Content/Developers/
rm -rf ./TD2020/Content/Collections/
       
rm -rf ./TD2020/build/
rm -rf ./TD2020/intermediate/
rm -rf ./TD2020/binaries/
rm -rf ./TD2020/DerivedDataCache/
rm -rf ./TD2020/Debug/
rm -rf ./TD2020/.vs/
rm -rf ./TD2020/.git/
  
rm -rf ./TD2020/Plugins/UnrealEnginePython/binaries/
rm -rf ./TD2020/Plugins/UnrealEnginePython/tutorials/
rm -rf ./TD2020/Plugins/UnrealEnginePython/intermediate/
rm -rf ./TD2020/Plugins/UnrealEnginePython/screenshots/
   
rm -rf ./TD2020/Plugins/RTSPlugin/binaries/
rm -rf ./TD2020/Plugins/RTSPlugin/tutorials/
rm -rf ./TD2020/Plugins/RTSPlugin/intermediate/
rm -rf ./TD2020/Plugins/RTSPlugin/screenshots/

rm -rf ./venv/

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

echo ...
echo ..
echo .



echo Project at minimum size
echo Goodbye
sleep 1