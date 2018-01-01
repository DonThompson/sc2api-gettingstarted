# sc2api-gettingstarted

## Purpose
This guide & sample code will walk you through getting everything you need to build your own sc2 bot using the Blizzard API, run that bot against local in-game Starcraft 2 AIs, and finally run that bot against other bots using the www.sc2ai.net ladder manager locally.

## Assumptions
* You have a basic knowledge of Git (fork, clone, git shell, etc)
* You are using Windows.
* You are using Visual Studio 2017
* You have a reasonable understanding of C++ and project configuration (includes, libs mostly)

## Caveats
* Release mode only for now (TODO:  Figure out debug)

# Work...

## Choose a starting location
* Everything we do will live under this folder.  As an example we'll use 'c:\sc2api\'.  Feel free to change this to wherever you want it.
* Open up Git Shell, we'll do all work from there
```
mkdir c:\sc2api
cd c:\sc2api
```

## Clone this repo
* Open up git shell
* Clone to your PC
```
git clone https://github.com/DonThompson/sc2api-gettingstarted
```

## Prep folders
```
mkdir sc2api
mkdir LadderServer
mkdir LadderServer\Bots
mkdir LadderServer\Replays
mkdir LadderServer\Maps
```

## Get & build the Starcraft 2 API from Blizzard
* Follow the build documentation:  https://github.com/Blizzard/s2client-api/blob/master/docs/building.md
```
git clone --recursive https://github.com/Blizzard/s2client-api
cd s2client-api
mkdir build
cd build
cmake ../ -G "Visual Studio 15 2017 Win64"
```
* Build it in release mode
* TODO:  cmd line this?
* Open Visual Studio 2017, browse to C:\sc2api\s2client-api\build\ and open s2client-api.sln
* Set your configuration to "Release" and "x64" via Build->Configuration Manager or in your toolbar
* Choose Build -> Rebuild Solution
* TODO:  Only building release mode right now. If we want to debug later, we might want more built.
* Once complete, we want to grab the output
```
cd ..
.\synchproject.bat --If asked to overwrite, choose All
copy-item project/include/ ../sc2api/include/ -recurse
copy-item project/lib/ ../sc2api/lib/ -recurse
cd ..
```

* You have now built the sc2 api libraries we'll use to build everything else.  We have house them in a central location @ C:\sc2api\sc2api\ that everyone else can reference.

## Get the sc2ai.net Ladder Manager
* Note:  Currently using the dllinterface branch, not master
* TODO:  Probably move this down?  Might be simplest to get you going 1vai before other bots
```
git clone https://github.com/Cryptyc/Sc2LadderServer -b DLLInterface
```
* Now build it in release mode
* TODO:  cmd line this?
* Open Visual Studio 2017, browse to C:\sc2api\Sc2LadderServer\ and open LadderManager.vcxproj
* Set your configuration to "Release" and "x64" via Build->Configuration Manager or in your toolbar
* Right click on the project (not solution) and go to Properties.  Make sure you're looking at Release / x64.
* Under C/C++, look for "Additional Include Directories".  Add `../sc2api/include;curl/include;` to the existing list
* Under Linker, look for "Additional Library Dependencies".  Add `../sc2api/lib` to the existing list
* Choose Build -> Rebuild Solution
* TODO:  Only building release mode right now. If we want to debug later, we might want more built.
* Once complete, we want to grab the output
```
copy-item .\Sc2LadderServer\x64\Release\LadderManager.exe LadderServer
copy-item .\Sc2LadderServer\curl\bin\libcurl.dll LadderServer
copy-item .\sc2api-gettingstarted\LadderManagerConfig\* LadderServer -recurse
```
* TODO:  Maps path is hardcoded to c:\sc2api\
* Grab the latest bots from sc2ai.net:   http://sc2ai.net/Season3Bots.zip
* Unzip these into C:\sc2api\LadderServer\Bots
* TODO:  Should we just auto download these?
* TODO:  Test if LadderManager.exe can take relative paths.  Would make things simpler.  Make PR if not.


# Build your own bot

* Open sc2api-gettingstarted\MyBot\MyBot.sln in Visual Studio 2017.
* Set your configuration to Release x64 (Build -> Configuration Manager)
* Build -> Rebuild Solution
* Note:  A post-build step exists to automatically copy your bot to the LadderManager bot directory

## 2 ways to run your bot
1. Run the application from Visual Studio, which will execute the Launcher project.  This starts starcraft, loads your bot, and starts a 1v1 game against the built in Blizzard computer opponents.
  * NOTE:  The code is hardcoded to a map path at c:\sc2api\.  If you chose a different starting path, you will need to change this manually.
2. Run LadderManager.exe, you should see * MyBot.dll as a detected bot and will be put into the rotation against other bots.



# Help
Stuck?  Something not quite working as planned?
* Check out the sc2ai.net discord or facebook group
* http://sc2ai.net/Joinus.php
