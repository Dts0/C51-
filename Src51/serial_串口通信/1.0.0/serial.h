/*********************2017年7月7日19:24:15***********************************/
/**************************By 赵靖石*****************************************/
#ifndef SERIAL_H
#define SERIAL_H

#include <reg52.h>
#include <stdio.h>
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#endif

#define _stopFlag '#'//信息的结尾标识符
#define _MaxSize 50//一次信息的最大字节数
uchar flag,flag_t,s[_MaxSize]="",flag_n=0,i,j=0;
//  转存标志,传输标志,接收到的信息,换行标志
uchar code table[]="OK ";//接收到消息的回复

void serialBegin(int bits);
void serialPrint(uchar msg[]);
void serialPrintln(uchar msg[]);
uchar* serialReceivedMsg();

void serialBegin(int bits)
{
       TMOD=0x20;    //定时器工作方式，选择了定时器1，工作方式2 八位初值自动重装的8位定时器
       TH1=bits;     //定时器1初值  ,设置波特率为9600 晶振11.0529MHZ?
       TL1=bits;
       TR1=1;        //开启定时器1

       SM0=0;
       SM1=1;        //10位异步接收，（8位数据）波特率可变
       REN=1;        //允许串行口接收位
       EA=1;         //允许中断（总闸）
       ES=1;         //允许串口中断
}
void serialPrint(uchar msg[])
{
    TI=1;
    printf("%s",msg);
    while (!TI);
    TI=0;
}
void serialPrintln(uchar msg[])
{
    TI=1;
    printf("\n%s\n",msg);
    while(!TI);
    TI=0;
}
uchar* serialReceivedMsg()
{
    return s;
}

void sendMsg(uchar answerMsg[])
{
    if(flag==1)
    {
        if(flag_n!=0)
        {TI=1;
        printf("\n");
        while(!TI);
        TI=0;
        }
        for(i=0;s[i]!=_stopFlag&&i<_MaxSize;++i)//输出缓存区内容
        {
            SBUF=s[i];
            while(!TI);
            TI=0;
        }
        for(i=0;i<3;++i)//输出OK
        {
            SBUF=table[i];
            while(!TI);
            TI=0;
        }

        flag=0;
    }
    if(flag_t==1)
    {
        TI=1;
        printf("\nMessage:\n%s",answerMsg);
        while(!TI);
        TI=0;
        flag_t=0;
    }
}


void receiveMsg() interrupt 4
{
    if(RI)//如果收到信息
    {
        RI=0;
        if(flag==0&&j!=0)
        {
            ++flag_n;
            for(j=0;s[j]!=_stopFlag&&j<_MaxSize;++j)//之前的信息置零
                s[j]='\0';
            j=0;
        }
        s[j]=SBUF;//将串口缓冲区内容读出
        flag=1;//标记为SBUF中有数据
        if(s[j]==_stopFlag||j==_MaxSize-1)//如果是最后一位,将标记位设为1
            flag_t=1;
        else ++j;
    }
    if(TI)
    {

    }
}

#endif // SERIAL_H
