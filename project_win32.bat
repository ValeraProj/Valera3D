@echo off
if not exist project\win32 mkdir project\win32
cd project\win32
cmake -DPLATFORM_WIN32=ON -G"Visual Studio 11" ../..
pause