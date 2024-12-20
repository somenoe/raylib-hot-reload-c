@echo off

if not exist bin mkdir bin
if not exist src\library mkdir src\library

cd raylib\src

@REM Compiling Raylib
make RAYLIB_LIBTYPE=SHARED
echo --- Successfully compiled (Raylib)

@REM Built with 'make RAYLIB_LIBTYPE=SHARED'
copy raylib.dll ..\..\bin
copy libraylibdll.a ..\..\bin

@REM Prebuilt headers (Raylib 5.5)
copy raylib.h ..\..\src\library
copy raymath.h ..\..\src\library
copy rcamera.h ..\..\src\library
copy rlgl.h ..\..\src\library

echo --- Successfully copied (Raylib)
