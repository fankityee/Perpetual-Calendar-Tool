#include<conio.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//函数声明 
int runnian(int year);                                              //判断是否为闰年
int fd_year(int year);                                              //判断每年的第一天 
int fd_month(int year,int month,int year0);                         //判断每月的第一天 
void show(int year,int month,int first_month) ;                     //展示日历 
void fun();                                                         //查询日历程序 
void shijian();                                                     //显示实时时间 
int GetHour(char *s);
int GetMinute(char *s);
void naozhong();                                                    //设定闹钟 
void nianli();                                                      //查询年历 
void Menu();                                                        //菜单 
                                                                                                              // 
int main(){
	while (1)
	{
        Menu();                                                      //引用菜单 
		int n;
		scanf("%d",&n);
		switch (n)
		{
		case 0:
		return 0;
		break;
		case 1:
		fun();
		system("cls");                                               //清屏 
		break;
		case 2:
		shijian();
		system("cls");                                               //清屏 
		break;
		case 3:
		naozhong(); 
		system("pause");                                             //系统暂停(避免闹钟响后立马跳转主菜单） 
		system("cls");                                               //清屏 
		break;
		case 4:
		nianli();
		system("cls");                                               //清屏 
		break;
			default:
			printf("输入有误，没有该功能\n\n"); 
			system("pause");                                         //系统暂停(避免输出文字后立马跳转主菜单）        
			system("cls");                                           //清屏 
			break;	
			                                                                                                   // 
		}
	}

	return 0;
} 
                                                                                                               // 
//函数部分
 
//判断是否为闰年
int runnian(int year)
{
    if ((year%4==0&&year%100!=0)||year%400==0)                      //判断是否为闰年 
        return 1;                                                   //如果满足条件则返回1，即闰年天数为普通年数加1，即366天 
    else
        return 0;                                                   //普通年份则默认365天             
}
//判断每年的第一天 
int fd_year(int year)                                                
{
    int year0=2000;                                                 //定义一个起始年份2000年
    int day0=6;                                                     //在日历中查询得知2000年1月1号是星期六
    int i=2000;
    int sum=0;                                                      //天数总和
    for (i=year0;i<year;i++)
    {
        sum =sum+365+runnian(i);                                    //runnian函数如果是闰年则在总天数加1。 
    }
    return (sum+day0)%7;
}
//判断每月的第一天 
int fd_month(int year,int month,int year0)                           
{
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    int sum = 0;                                                    //sum为天数和
    int i = 0;
    for(i=1;i<month;i++)
    {
        sum=sum+mon[runnian(year)][i];
    } 
    return (sum+year0)%7;
}
//展示日历 
void show(int year,int  month, int first_month)
{
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };           //第一组为不是闰年，第二组为闰年        
    int i = 0;
    printf("一   二   三   四   五   六  日\n");
    for (i = 0; i < first_month-1; i++)
    {
        printf("     ");                                          //留行和空格排版 
    }
    for (i = 1; i <= mon[runnian(year)][month]; i++)
    {
        printf("%-5d", i);
        if ((first_month-1+i) % 7 ==0)                            //基姆拉尔森公式 
            printf("\n");
    }
    printf("\n");
}
//查询日历程序
void fun(){
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };        //第一组为不是闰年，第二组为闰年         
    int year,month;
    printf("请输入你想查询的年份\n");
    printf("年 月:"); 
    scanf("%d %d", &year, &month);
    int year0 = fd_year(year);                                      //年份第一天
    int first_month = fd_month(year, month, year0);                 //月份第一天
    show(year, month, first_month);
    system("pause");
}
//显示实时时间
void shijian(){                                                      
	char time[50];
	while(1)
	{
		if(!kbhit())
		{
		_strtime(time);
		printf("\r%s",time); 
		}
		else{
		printf("\n"); 
	    return;
	}
}
}
//获取系统小时的函数
int GetHour(char *s)    
{
	char *p, *q;
	p = (char *)malloc(10);
	strcpy(p, s);
	q = p;
	while(*q != ':')
	{
		q++;
	}
	*q = '\0';
	return atoi(p);
}
//获取系统分钟的函数
int GetMinute(char *s)  
{
	char *p;
	p = (char *)malloc(10);
	strcpy(p, s);
	while(*p != ':')
	{
		p++;
	}
	p++;
	return atoi(p);
}
//设定闹钟
void naozhong(){
	char s[10];
	int hour,minute;
	time_t t;
	struct tm *timeinfo;
	printf("请设置闹钟响铃时间(18:30):");
	scanf("%s",&s);
	hour = GetHour(s);
	minute = GetMinute(s);
	while(1)
	{
		time(&t);
		timeinfo = localtime(&t);
		if((minute+hour*60-timeinfo->tm_min-timeinfo->tm_hour*60)<0)   //设定时间小于系统时间
		{
			if(timeinfo->tm_hour > hour)
			{
				printf("闹钟早就响了!\n\007");
			    printf("\a\a\a\a");
				break;
			}
			else if(timeinfo->tm_hour = hour && timeinfo->tm_min >= minute)
			{
				printf("闹钟早就响了!\n\007");
			    printf("\a\a\a\a");
				break;
			}
		}
		else           //设定时间大于等于系统时间
		{
			if(timeinfo->tm_hour < hour)continue;
			else if(timeinfo->tm_min < minute)continue;
			else
			{
				printf("时间到!\n\007");
				printf("\a\a\a\a");
				break;
			}
		}
	}
	
}
//查询年历
void nianli(){
	int year,month,day,c,Y,W,i,j,w;
	int t[]={31,0,31,30,31,30,31,31,30,31,30,31};
	printf("请输入查询年份");
	scanf("%d",&year);
	if(year%4==0&&year%100!=0||year%400==0)
	t[1]=29;                                                             //闰年 
	else t[1]=28;                                                        //不是闰年 
	for(month=1;month<=12;month++)
	{
		if(month<3){
		c=((int)(year-1)/100);
		Y=(year-1)-((int)((year-1)/100))*100;
		w=((int)(c/4))-2*c+Y+((int)(Y/4))+((int)(13*(month+13)/5));
		W=(w+70)%7;
	}
	else if(month>=3)
	{
	c=((int)(year/100));
	Y=year-((int)(year/100))*100;
	w=((int)(c/4))-2*c+Y+((int)(Y/4))+((int)(13*(month+1)/5));
	W=(w+70)%7;
	}
	i=W;
	printf("\n\n              %d月\n\n",month);                //输出月份名称 
	printf("  日  一  二  三  四  五  六\n");
	for(j=1;j<=W;j++)
	printf("    ");
	for(day=1;day<=t[month-1];day++)
	{
	i++;
	printf("%4d",day);
	if(i%7==0)
	printf("\n");
}
}
printf("\n");
system("pause");
}
//菜单 
void Menu() {
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t  欢迎使用万年历与时间工具\t\t*\n");
	printf("\t\t\t\t*\t     请选择您需要的功能\t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t1.查询日历\t\t\t*\n");
	printf("\t\t\t\t*\t\t2.查看当前时间\t\t\t*\n");
	printf("\t\t\t\t*\t\t3.设定闹钟\t\t\t*\n");
	printf("\t\t\t\t*\t\t4.查询年历\t\t\t*\n");
	printf("\t\t\t\t*\t\t0.退出系统\t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}



















