#ifndef _biosIO_H_
#define _biosIO_H_ 0


void hex(char* src,char* buffer,int length);	//��Ŀ���ڴ�������ʮ����������������ֱ�ΪԴ��ַ�����ʮ�������ַ�����ַ��Դ���� 

 
char scanKeycode();	//�ȴ���������ɨ���룬���ް������뷵��0 
char scanASCIIcode();	//�ȴ���������ascii�룬���ް������뷵��0 


void print(char* str,int length,int row,int col,int attr);	//�ַ�����ַ�����ȡ�����С��С��ַ����� 

#endif
