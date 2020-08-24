@ECHO off
PUSHD ..\
CALL vendor\bin\premake\premake5.exe vs2019
POPD
PAUSE