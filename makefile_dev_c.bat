@echo off
color 2e
mode con lines=32 cols=60
echo ###################
echo 请输入Dev-C安装目录：
:enter
set /p a=
echo.

set bin=%a%\MinGW64\bin

if exist %bin%\gcc.exe goto compile
echo 找不到dev-c下的编译器gcc.exe
echo 请重新输入dev-c的安装目录
goto enter

:compile
set PATH=%bin%
echo 已将PATH临时变量设置到%bin%

set lib=%a%\MinGW64\lib
set LIBRARY_PATH=%lib%
echo 已将LIBRARY_PATH临时变量设置到%lib%

set include=%a%\MinGW64\include
set C_INCLUDE_PATH=%include%
echo 已将C_INCLUDE_PATH临时变量设置到%include%

echo 开始使用dev-c编译...
as --32 startup.s -o startup.o
gcc -c -m32 biosIO.c
gcc -c -m32 system.c
gcc -c -m32 GUI.c
gcc -c -m32 time.c
gcc -c -m32 main.c
ld -Ttext 0x0 -m i386pe startup.o main.o biosIO.o system.o GUI.o time.o -o main.elf
objcopy -j .text -O binary main.elf main.com

copy /b /y loader.com+MBR.dat+main.com os.img


echo.
echo 编译完成
echo.
echo 将a.img写入u盘或使用虚拟机即可运行
pause