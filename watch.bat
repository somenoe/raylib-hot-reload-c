@REM watch all files in ./src folder, run update.bat if any file changes

@echo off
setlocal enabledelayedexpansion

set "src=src"
set "lastState="

REM Get initial state with content hash
for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
    set "hash="
    for /f "skip=1 tokens=* delims=" %%H in ('certutil -hashfile "%%F" MD5 2^>nul') do (
        if not defined hash (
            set "hash=%%H"
            set "lastState=!lastState!%%F:!hash!$"
        )
    )
)

echo Watching for changes in %src%...

:loop
REM Wait for 1 seconds before checking again
timeout /t 1 /nobreak > nul

REM Clear current state
set "currentState="

REM Capture current state with content hash
for /f "delims=" %%F in ('dir /s /b /a-d "%src%\*.*"') do (
    set "hash="
    for /f "skip=1 tokens=* delims=" %%H in ('certutil -hashfile "%%F" MD5 2^>nul') do (
        if not defined hash (
            set "hash=%%H"
            set "currentState=!currentState!%%F:!hash!$"
        )
    )
)

REM Compare states
if not "!lastState!"=="!currentState!" (
    echo [%TIME%] Change detected! Recompiling...
    call update.bat
    set "lastState=!currentState!"
)

goto loop
