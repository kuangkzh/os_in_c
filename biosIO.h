#ifndef _biosIO_H_
#define _biosIO_H_ 0


void str2hex(unsigned char* src,unsigned char* buffer,int length,char split);
//��Ŀ���ڴ�����ת��Ϊʮ�������ı��������ֱ�ΪԴ��ַ�����ʮ�������ַ�����ַ��ת�����ȡ��ָ��� 

 
unsigned char scanKeycode();	//�ȴ���������ɨ���룬���ް������뷵��0 
unsigned char scanASCIIcode();	//�ȴ���������ascii�룬���ް������뷵��0 


void print(char* str,int length,int row,int col,int attr);	//�ַ�����ַ�����ȡ�����С��С��ַ����� 

int readDisk(int start,int length,int disk,char* buffer);//�ɹ����ض�ȡ������(С��63)��ʧ�ܷ���ʧ�ܴ���(����64) 
int writeDisk(int start,int length,int disk,char* buffer);//�ɹ�����д��������(С��63)��ʧ�ܷ���ʧ�ܴ���(����64) 
//start:��ʼ������������1��ʼ��� 
//length:��д�������������Զ����ŵ�
//disk:�����������̴�00H��ʼ��ţ�Ӳ�̴�80H��ʼ���
//buffer:������ָ�� 

#endif
