@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
cl CrossPlatformLineEnding.c
cmd /c CrossPlatformLineEnding.exe
