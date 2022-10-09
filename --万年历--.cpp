#include<stdio.h>

int year,month,day,sum = 0,i;
int run_nian[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int ping_nian[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][3]= {"һ","��","��","��","��","��","��"};

/////////////////////////////////////////////////////////////////////////////////////////////

void biao_tou()//������ͷ 
{
	printf("###########################################################\n");
	printf("\t\t\t������\t\t\n");
	printf("-----------------------------------------------------------\n");
	for (i=0;i<7;i++)
	{
		printf("%s\t",week[i]);
	}
	printf("\n");
}
/////////////////////////////////////////////////////////////////////

int check(int year)//
	{
		if(year % 4 == 0 && year % 100 != 0)	
		{
			return 1;//���귵��1 
		}
		
		if(year % 400 == 0)
		{
			return 1;//���귵��1 
		}
		
		return 0;
	}

//�����Ƿ�Ϊ����  a= Year_Check(2020)=1

///////////////////////////////////////////////////////////////////////////

int daysum(int year,int month,int day,int run_nian[],int ping_nian[])
{
	for (i = 1900;i < year;i++)
	{
		if (check(i) == 1)
		{
			sum+=366;//sum = sum + 366;(0 + 366)
		}
		else
		{
			sum+=365;//sum = sum + 365;(0 + 365)
		}
	}
	for (i=0;i<month-1;i++)//month=6				2020.6.7
	{
		if (check(year) == 1){
			sum += run_nian[i];//sum = sum + run[i] 
		}
		else{
			sum += ping_nian[i];//sum  = sum + ping[i]
		}
	}
	return sum;
 } 
 //1900��1��1��Ϊ����һ sumΪ��1900��ʼ�������·�ǰһ���µ������ܺ�
 
 /////////////////////////////////////////////////////////////////////////////////////////// 
 
 void printf_excel(int year,int month,int day,int sum)
{
	int a,b;
	a = sum % 7;
	for (i=0;i< a ;i++)
	{
		printf("\t");
	}
	b = 7 - a;
	if (check(year) == 1)
	{
		for (i = 1;i <= run_nian[month - 1];i++)
		{
			if (i != day)
			{
			printf("%d\t",i);
			}
			else
			{
				printf("%d*\t",i);
			}
			if (i == b || (i - b) %7 == 0 )
			{
				printf("\n");
			}
		
		}
	}
	else
	{
		for (i = 1;i <= ping_nian[month - 1];i++)
		{
			if (i != day)
			{
			printf("%d\t",i);
			}
			else
			{
				printf("%d*\t",i);
			}
			if (i == b || (i - b) %7 == 0 )
			{
				printf("\n");
			}
			
		}
	}
	
	printf("\n");
}

 
int main()//������ 
	{
 		char Return = 'a';
		while(Return == 'a')
	{
		printf("�������꣬�£��գ�\n");
		scanf("%d %d %d",&year,&month,&day); 
	 	biao_tou();	
	 	sum = daysum(year,month,day,run_nian,ping_nian);
	 	printf_excel(year,month,day,sum);
	 	printf("\n-----------------------------------------------------------\n");
	 	printf("###########################################################\n");
	 	printf("\n��a���¿�ʼ�������λ�˳�����");
	 	scanf("%s",&Return);
	}
	
		return 0;
	  }

