/********************����: 2017��7��26��11:25:03 By�Ծ�ʯ***********************/
/******************����޸�: 2017��7��26��11:25:03 By�Ծ�ʯ**********************/
/********************�汾��:1.1.0***********************************************/
#include "serial.h"
uchar flag,flag_t,receivedMsg[_MaxSize]="",i,j=0;
//  ת���־,�����־,���յ�����Ϣ
uchar code respondMsg[]="OK\n";//���յ���Ϣ�Ļظ�

extern  uchar _serialBegined=0;

void serialBegin(int bits)
{
       TMOD=0x20;    //��ʱ��������ʽ��ѡ���˶�ʱ��1��������ʽ2 ��λ��ֵ�Զ���װ��8λ��ʱ��
       TH1=bits;     //��ʱ��1��ֵ,���ò�����Ϊ9600 ����11.0529MHZ?
       TL1=bits;
       TR1=1;        //������ʱ��1

       SM0=0;
       SM1=1;        //10λ�첽���գ���8λ���ݣ������ʿɱ�
       REN=1;        //�����пڽ���λ
       EA=1;         //�����жϣ���բ��
       ES=1;         //�������ж�

       _serialBegined=1;

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
    printf("%s\n",msg);
    while(!TI);
    TI=0;
}
uchar* serialReceivedMsg()
{
    while(1)
    {
    if(flag==1)
    {
        for(i=0;receivedMsg[i]!=_stopFlag&&i<_MaxSize;++i)//�������������
        {
            SBUF=receivedMsg[i];
            while(!TI);
            TI=0;
        }
        for(i=0;i<3;++i)//���OK
        {
            SBUF=respondMsg[i];
            while(!TI);
            TI=0;
        }

        flag=0;
    }//end if
    if(flag_t==1)
    {
        flag_t=0;
        return respondMsg;
    }//end if
    }//end while
}
  
void rev() interrupt 4
{
    if(RI)//����յ���Ϣ
    {
        RI=0;
        if(flag==0&&j!=0)//��֮ǰ��receivedMsg���
        {
            for(j=0;receivedMsg[j]!=_stopFlag&&j<_MaxSize;++j)//֮ǰ����Ϣ����
                receivedMsg[j]='\0';
            j=0;
        }
        receivedMsg[j]=SBUF;//�����ڻ��������ݶ���
        flag=1;//���Ϊ������
        if(receivedMsg[j]==_stopFlag||j==_MaxSize-1)//��������һλ,�����λ��Ϊ1
            flag_t=1;
        else ++j;
    }
    if(TI)
    {

    }
}
