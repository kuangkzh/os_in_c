#ifndef _biosIO_H_
#define _biosIO_H_ 0


void hex(char* src,char* buffer,int length);	//将目标内存区域以十六进制输出，参数分别为源地址、输出十六进制字符串地址、源长度 

 
char scanKeycode();	//等待按键输入扫描码，若无按键输入返回0 
char scanASCIIcode();	//等待按键输入ascii码，若无按键输入返回0 


void print(char* str,int length,int row,int col,int attr);	//字符串地址、长度、输出行、列、字符属性 

#endif
