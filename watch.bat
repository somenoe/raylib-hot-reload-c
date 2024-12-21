@REM watch all files in ./src folder, run update.bat if any file changes

@echo off
setlocal enabledelayedexpansion

set "src=src"
set "lastState=.\bin\watch.txt"

REM Ensure state file exists
if not exist %lastState% (
    echo Initializing state file...
    for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
        echo %%F %%~zF %%~tF >> %lastState%
    )
)

echo Watching for changes in %src%...

:loop
REM Wait for 2 seconds before checking again
ping -n 3 127.0.0.1 > nul

REM Capture current state of files
for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
    echo %%F %%~zF %%~tF >> currentState.txt
)

REM Compare states
fc %lastState% currentState.txt > nul
if errorlevel 1 (
    echo Change detected! Running update.bat...
    call update.bat
    copy /y currentState.txt %lastState% > nul
)

del currentState.txt

goto loop
