@REM watch all files in ./src folder, run update.bat if any file changes

@echo off
setlocal enabledelayedexpansion

set "src=src"
set "lastState="

REM Get initial state
for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
	set "lastState=!lastState!%%F %%~zF %%~tF$"
)

echo Watching for changes in %src%...

:loop
REM Wait for 1 seconds before checking again
timeout /t 1 /nobreak > nul

REM Clear current state
set "currentState="

REM Capture current state of files
for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
	set "currentState=!currentState!%%F %%~zF %%~tF$"
)

REM Compare states
if not "!lastState!"=="!currentState!" (
	echo %lastState%
	echo [%TIME%] Change detected! Recompiling...
	call update.bat
	set "lastState=!currentState!"
)

goto loop
