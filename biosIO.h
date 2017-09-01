#ifndef _biosIO_H_
#define _biosIO_H_ 0


void str2hex(unsigned char* src,unsigned char* buffer,int length,char split);
//将目标内存区域转换为十六进制文本，参数分别为源地址、输出十六进制字符串地址、转换长度、分隔符 

 
unsigned char scanKeycode();	//等待按键输入扫描码，若无按键输入返回0 
unsigned char scanASCIIcode();	//等待按键输入ascii码，若无按键输入返回0 


void print(char* str,int length,int row,int col,int attr);	//字符串地址、长度、输出行、列、字符属性 

int readDisk(int start,int length,int disk,char* buffer);//成功返回读取扇区数(小于63)，失败返回失败代码(大于64) 
int writeDisk(int start,int length,int disk,char* buffer);//成功返回写入扇区数(小于63)，失败返回失败代码(大于64) 
//start:开始扇区，扇区从1开始编号 
//length:读写扇区数，不能自动换磁道
//disk:驱动器，软盘从00H开始编号，硬盘从80H开始编号
//buffer:缓冲区指针 

#endif
