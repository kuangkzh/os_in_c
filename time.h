#ifndef _TIME_H_
#define _TIME_H_ 0

typedef struct BIOSTime
{
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char summertime;	//不为0时表示夏令时 
} BIOSTime;

typedef struct BIOSDate
{
	short year;
	unsigned char month;
	unsigned char day;
} BIOSDate;

int getTime(BIOSTime* t);	//获取系统时间 
int getDate(BIOSDate* t);	//获取系统日期 

#endif
