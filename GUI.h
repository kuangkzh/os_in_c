#ifndef _GUI_H_
#define _GUI_H_ 0

//背景色常量 
#define COLOR_BG_BLACK 0x00
#define COLOR_BG_BLUE 0x10
#define COLOR_BG_GREEN 0x20
#define COLOR_BG_AQUA 0x30
#define COLOR_BG_RED 0x40
#define COLOR_BG_PURPLE 0x50
#define COLOR_BG_YELLOW 0x60
#define COLOR_BG_WHITE 0x70
#define COLOR_BG_LIGHT 0x80	//浅色 
//前景色常量 
#define COLOR_FR_BLACK 0x0
#define COLOR_FR_BLUE 0x1
#define COLOR_FR_GREEN 0x2
#define COLOR_FR_AQUA 0x3
#define COLOR_FR_RED 0x4
#define COLOR_FR_PURPLE 0x5
#define COLOR_FR_YELLOW 0x6
#define COLOR_FR_WHITE 0x7
#define COLOR_FR_LIGHT 0x8

//显示模式常量 
#define TEXT_40x25x2_BW 0x00
#define TEXT_40x25x16 0x01
#define TEXT_80x25x16_SHADE 0x02
#define TEXT_80x25x16 0x03
#define GRAPH_320x200x4 0x04
//#define GRAPH_320x200x4 0x05
#define GRAPH_640x200x2_BW 0x06
#define TEXT_80x25x2_MONO 0x07
#define GRAPH_160x200x16 0x08
#define GRAPH_320x200x16 0x09
#define GRAPH_640x200x4 0x0A
//#define GRAPH_320x200x16 0x0D
#define GRAPH_640x200x16 0x0E
#define GRAPH_640x350x2_MONO 0x0F
#define GRAPH_640x350x16 0x10
#define GRAPH_640x480x2_BW 0x11
#define GRAPH_640x480x16 0x12
#define GRAPH_320x200x256 0x13

void setDisplayMode(int mode);	//设置显示模式 
void setCursorPosition(int page,unsigned char row,unsigned char col);	//设置光标位置 
void setPixel(int page,unsigned short row,unsigned short col,unsigned char color);	//绘制某点颜色 
void setBackground(unsigned char color);	//设置背景色，在某些显示模式下不可用
void setPalette(unsigned char palette); 	//选取调色板 

#endif
