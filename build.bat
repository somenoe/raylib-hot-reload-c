@echo off

cd bin

echo LOCKFILE IN AID OF HOTLOADING > lock.file

@REM Compiling game logic (.dll) for hot reloading
@REM - o <file>                    # set output file name
@REM - shared                      # compile as a shared / dynamic library
@REM - libraylibdll.a              # link with raylib static library
@REM - lwinmm -lopengl32 -lgdi32   # link with necessary system libraries
gcc ..\src\game.c -o game_code.dll -shared libraylibdll.a -lwinmm -lopengl32 -lgdi32
echo --- Successfully compiled (.dll)

del lock.file

@REM Compiling executable (.exe)
gcc ..\src\main.c -o game.exe libraylibdll.a -lgdi32 -lwinmm
echo --- Successfully compiled (.exe)

cd ..
