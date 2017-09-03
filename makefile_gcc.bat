as --32 loader.s -o loader.o
ld -Ttext 0x7c00 -m i386pe loader.o -o loader.elf
objcopy -j .text -S -O binary loader.elf loader.com

as --32 startup.s -o startup.o
gcc -c -m32 biosIO.c
gcc -c -m32 system.c
gcc -c -m32 GUI.c
gcc -c -m32 time.c
gcc -c -m32 main.c
ld -Ttext 0x0 -m i386pe startup.o main.o biosIO.o system.o GUI.o time.o -o main.elf
objcopy -j .text -O binary main.elf main.com

copy /b /y loader.com+MBR.dat+main.com os.img

pause