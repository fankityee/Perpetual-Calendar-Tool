#include<conio.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//�������� 
int runnian(int year);                                              //�ж��Ƿ�Ϊ����
int fd_year(int year);                                              //�ж�ÿ��ĵ�һ�� 
int fd_month(int year,int month,int year0);                         //�ж�ÿ�µĵ�һ�� 
void show(int year,int month,int first_month) ;                     //չʾ���� 
void fun();                                                         //��ѯ�������� 
void shijian();                                                     //��ʾʵʱʱ�� 
int GetHour(char *s);
int GetMinute(char *s);
void naozhong();                                                    //�趨���� 
void nianli();                                                      //��ѯ���� 
void Menu();                                                        //�˵� 
                                                                                                              // 
int main(){
	while (1)
	{
        Menu();                                                      //���ò˵� 
		int n;
		scanf("%d",&n);
		switch (n)
		{
		case 0:
		return 0;
		break;
		case 1:
		fun();
		system("cls");                                               //���� 
		break;
		case 2:
		shijian();
		system("cls");                                               //���� 
		break;
		case 3:
		naozhong(); 
		system("pause");                                             //ϵͳ��ͣ(�����������������ת���˵��� 
		system("cls");                                               //���� 
		break;
		case 4:
		nianli();
		system("cls");                                               //���� 
		break;
			default:
			printf("��������û�иù���\n\n"); 
			system("pause");                                         //ϵͳ��ͣ(����������ֺ�������ת���˵���        
			system("cls");                                           //���� 
			break;	
			                                                                                                   // 
		}
	}

	return 0;
} 
                                                                                                               // 
//��������
 
//�ж��Ƿ�Ϊ����
int runnian(int year)
{
    if ((year%4==0&&year%100!=0)||year%400==0)                      //�ж��Ƿ�Ϊ���� 
        return 1;                                                   //������������򷵻�1������������Ϊ��ͨ������1����366�� 
    else
        return 0;                                                   //��ͨ�����Ĭ��365��             
}
//�ж�ÿ��ĵ�һ�� 
int fd_year(int year)                                                
{
    int year0=2000;                                                 //����һ����ʼ���2000��
    int day0=6;                                                     //�������в�ѯ��֪2000��1��1����������
    int i=2000;
    int sum=0;                                                      //�����ܺ�
    for (i=year0;i<year;i++)
    {
        sum =sum+365+runnian(i);                                    //runnian�������������������������1�� 
    }
    return (sum+day0)%7;
}
//�ж�ÿ�µĵ�һ�� 
int fd_month(int year,int month,int year0)                           
{
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    int sum = 0;                                                    //sumΪ������
    int i = 0;
    for(i=1;i<month;i++)
    {
        sum=sum+mon[runnian(year)][i];
    } 
    return (sum+year0)%7;
}
//չʾ���� 
void show(int year,int  month, int first_month)
{
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };           //��һ��Ϊ�������꣬�ڶ���Ϊ����        
    int i = 0;
    printf("һ   ��   ��   ��   ��   ��  ��\n");
    for (i = 0; i < first_month-1; i++)
    {
        printf("     ");                                          //���кͿո��Ű� 
    }
    for (i = 1; i <= mon[runnian(year)][month]; i++)
    {
        printf("%-5d", i);
        if ((first_month-1+i) % 7 ==0)                            //��ķ����ɭ��ʽ 
            printf("\n");
    }
    printf("\n");
}
//��ѯ��������
void fun(){
	int mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };        //��һ��Ϊ�������꣬�ڶ���Ϊ����         
    int year,month;
    printf("�����������ѯ�����\n");
    printf("�� ��:"); 
    scanf("%d %d", &year, &month);
    int year0 = fd_year(year);                                      //��ݵ�һ��
    int first_month = fd_month(year, month, year0);                 //�·ݵ�һ��
    show(year, month, first_month);
    system("pause");
}
//��ʾʵʱʱ��
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
//��ȡϵͳСʱ�ĺ���
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
//��ȡϵͳ���ӵĺ���
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
//�趨����
void naozhong(){
	char s[10];
	int hour,minute;
	time_t t;
	struct tm *timeinfo;
	printf("��������������ʱ��(18:30):");
	scanf("%s",&s);
	hour = GetHour(s);
	minute = GetMinute(s);
	while(1)
	{
		time(&t);
		timeinfo = localtime(&t);
		if((minute+hour*60-timeinfo->tm_min-timeinfo->tm_hour*60)<0)   //�趨ʱ��С��ϵͳʱ��
		{
			if(timeinfo->tm_hour > hour)
			{
				printf("�����������!\n\007");
			    printf("\a\a\a\a");
				break;
			}
			else if(timeinfo->tm_hour = hour && timeinfo->tm_min >= minute)
			{
				printf("�����������!\n\007");
			    printf("\a\a\a\a");
				break;
			}
		}
		else           //�趨ʱ����ڵ���ϵͳʱ��
		{
			if(timeinfo->tm_hour < hour)continue;
			else if(timeinfo->tm_min < minute)continue;
			else
			{
				printf("ʱ�䵽!\n\007");
				printf("\a\a\a\a");
				break;
			}
		}
	}
	
}
//��ѯ����
void nianli(){
	int year,month,day,c,Y,W,i,j,w;
	int t[]={31,0,31,30,31,30,31,31,30,31,30,31};
	printf("�������ѯ���");
	scanf("%d",&year);
	if(year%4==0&&year%100!=0||year%400==0)
	t[1]=29;                                                             //���� 
	else t[1]=28;                                                        //�������� 
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
	printf("\n\n              %d��\n\n",month);                //����·����� 
	printf("  ��  һ  ��  ��  ��  ��  ��\n");
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
//�˵� 
void Menu() {
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t  ��ӭʹ����������ʱ�乤��\t\t*\n");
	printf("\t\t\t\t*\t     ��ѡ������Ҫ�Ĺ���\t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\t1.��ѯ����\t\t\t*\n");
	printf("\t\t\t\t*\t\t2.�鿴��ǰʱ��\t\t\t*\n");
	printf("\t\t\t\t*\t\t3.�趨����\t\t\t*\n");
	printf("\t\t\t\t*\t\t4.��ѯ����\t\t\t*\n");
	printf("\t\t\t\t*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("\t\t\t\t*************************************************\n");
}



















