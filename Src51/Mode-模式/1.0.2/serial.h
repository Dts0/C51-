/******************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月30日17:37:56 By赵靖石**********************/
/********************版本号:1.1.1***********************************************/
#ifndef SERIAL_H
#define SERIAL_H

#include <reg52.h>
#include <stdio.h>
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#endif

#define _stopFlag '\n'//接收信息的结尾标识符,注：仅接收消息
#define _MaxSize 50//一次接收到信息的最大字节数

//希望或允许外界使用的函数请前置声明
void serialBegin(int bits);
void serialPrint(uchar msg[]);
void serialPrintln(uchar msg[]);
uchar* serialReceivedMsg();

uchar* wifiReceivedMsg();
#endif // SERIAL_H
