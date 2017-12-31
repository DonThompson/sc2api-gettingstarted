# sc2api-gettingstarted

## Purpose
This guide & sample code will walk you through 

## Assumptions
* Git knowledge (forks, clone, git shell, etc)
* Windows
* You are using VS 2017
* Reasonable understanding of C++ and project configuration (includes, libs mostly)

## Caveats
* Release mode only for now (TODO:  Figure out debug)

# Work...

## Choose a starting location
* Everything we do will live under this folder.  As an example we'll use 'sc2api'.  Feel free to change this to wherever you want it.
* Open up git shell, we'll do all work from there
```
mkdir c:\sc2api
cd c:\sc2api
```

## Fork this repo
* Open up git shell
* Clone to your PC
```
git clone https://github.com/DonThompson/sc2api-gettingstarted
```

## Prep folders
```
mkdir sc2api
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
```
