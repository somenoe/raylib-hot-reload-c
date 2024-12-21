@echo off

cd bin

echo LOCKFILE IN AID OF HOTLOADING > lock.file

gcc ..\src\game.c -o game_code.dll -shared libraylibdll.a -lwinmm -lopengl32 -lgdi32

del lock.file

echo --- Successfully compiled (.dll)

cd ..
