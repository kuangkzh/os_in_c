@echo off
color 2e
mode con lines=32 cols=60
echo ###################
echo ������Dev-C��װĿ¼��
:enter
set /p a=
echo.

set bin=%a%\MinGW64\bin

if exist %bin%\gcc.exe goto compile
echo �Ҳ���dev-c�µı�����gcc.exe
echo ����������dev-c�İ�װĿ¼
goto enter

:compile
set PATH=%bin%
echo �ѽ�PATH��ʱ�������õ�%bin%

set lib=%a%\MinGW64\lib
set LIBRARY_PATH=%lib%
echo �ѽ�LIBRARY_PATH��ʱ�������õ�%lib%

set include=%a%\MinGW64\include
set C_INCLUDE_PATH=%include%
echo �ѽ�C_INCLUDE_PATH��ʱ�������õ�%include%

echo ��ʼʹ��dev-c����...
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
echo �������
echo.
echo ��a.imgд��u�̻�ʹ���������������
pause