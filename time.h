#ifndef _TIME_H_
#define _TIME_H_ 0

typedef struct BIOSTime
{
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char summertime;	//��Ϊ0ʱ��ʾ����ʱ 
} BIOSTime;

typedef struct BIOSDate
{
	short year;
	unsigned char month;
	unsigned char day;
} BIOSDate;

int getTime(BIOSTime* t);	//��ȡϵͳʱ�� 
int getDate(BIOSDate* t);	//��ȡϵͳ���� 

#endif
