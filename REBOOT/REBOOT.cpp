// REBOOT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int gethour()
{
    time_t rawtime;
    struct tm *current;
    time(&rawtime);
    current=localtime(&rawtime);
    return current->tm_hour;
}

int getmin()
{
    time_t rawtime;
    struct tm *current;
    time(&rawtime);
    current=localtime(&rawtime);
    return current->tm_min;
}

/* void wait()
{
    
    time_t rawtime;
    struct tm *start,*end;
    
    time(&rawtime);
    start=localtime(&rawtime);
    time(&rawtime);
    end=localtime(&rawtime);
    end->tm_min=(end->tm_min)+1;
    while((start->tm_min)<=(end->tm_min))
    {
    time(&rawtime);
    start=localtime(&rawtime);
    }
    return;
}  */
    
void wait()
{
    clock_t goal = 60000 + clock();
    while (goal > clock());
    return;
}



int bcdtodec(int bcd)
{
int temp=0;

temp=temp+(bcd & 15);
bcd=bcd >> 4;
temp=temp+(10*(bcd & 15));
return temp;
}

int main()
{
FILE *fp;
const char *str = "shutdown -s\nshutdown /s";
int bcdtodec(int);
int gethour();
int getmin();
void wait();
//union REGS inregs,outregs;
int hours,current=0,target,curhour,curmin;
fp = fopen("C:\\RB.bat","w");
fputs(str,fp);
fclose(fp);
//inregs.h.ah=2;
printf("\n***********  AUTO REBOOT  **************\n - developed by Soham Chakraborty ");
//int86(26,&inregs,&outregs);
curhour=gethour();
curmin=getmin();
//printf("\nCURRENT TIME : %d:%d \n",bcdtodec(outregs.h.ch),bcdtodec(outregs.h.cl));
printf("\nCURRENT TIME : %d : %d \n",curhour,curmin);
printf("\n\nENTER THE DURATION in hours After Which YOUR PC Will SHUT DOWN \n");
scanf("%d",&hours);
//int86(26,&inregs,&outregs);
//current=outregs.h.ch;
//current=bcdtodec(current);
target=curhour+hours;
if(target>24)
target=target-24;
printf("\nYOUR SHUTDOWN TIME IS %d : %d \n",target,curmin);
printf("THANK YOU . NOW THE COUNTDOWN BEGINS FOR %d HOURS : \nCURRENT CLOCK : \n",hours);
while(curhour!=target)
{
//int86(26,&inregs,&outregs);
    curhour=gethour();
    curmin=getmin();
    //current=bcdtodec(outregs.h.ch);
    //printf("\n%d:%d",bcdtodec(outregs.h.ch),bcdtodec(outregs.h.cl));
    printf("\n%d : %d",curhour,curmin);
    wait();
}
//int86(25,&inregs,&outregs);
printf("REBOOTING SYSTEM ");
system("C:\\RB.bat");
system("del C:\\RB.bat");
getch();
return 0;
}





