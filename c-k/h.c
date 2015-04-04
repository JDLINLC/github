/*一个用来判断输入的区间内所有的回文数并将其输出的小程序*/
#include<stdio.h>
#include<string.h>
void h(char *n);				//判断是否是回文数，如果是就将其输出
void p(int start,int end);			//用来判断输入的区间是否正确，如果正确就对其中的每一个整数进行判断，看是否是回文数
void t(int num);				//将整数存储入数组中以方便下一步判断
int main(void)
{
	int start,end;				
	
	printf("Enter a number to start and a number to end(q to quit):\n");
	while(scanf("%d %d",&start,&end)==2)		  //获取要判断的区间	
	{
		p(start,end);				  //判断回文数并将回文数输出
	}

	return 0;
}


void h(char *n)
{
	char t[100];
	int i,j=0,l;

	l=strlen(n);
	n[l]='\0';
	for(i=0;i<l;i++)			//将数组中的字符串倒序存储进另一个数组中
	{
		t[l-i-1]=n[i];
	}
	t[l]='\0';
	if(strcmp(t,n)==0)			//根据倒序的整数是否等于原序的整数判断是否是回文数
	{
		printf("%s\t",n);		//输出回文数
	}
}


void p(int start,int end)
{
	int i=0;

	if(start>end)				//判断输入的区间是否正确
	{
		printf("Your enter is wrong!\nPlease try again(q to quit):\n");
	}
	else					//对区间内的整数一一进行判断
	{
		for(start;start<=end;start++)
		{
			t(start);
		}
		printf("\nPlease enter again(q to quit:)\n");
	}
}


void t(int num)
{
	char s[100],o[100];		//s数组用来存储倒序后的整数，o数组用来存储正序的数组
	int i=0,j;

	s[i]=num%10+48;			//将输入的整数从个位到最高位，一个一个的存入数组中
	while(num/10!=0)
	{
		i +=1;
		num /=10;
		s[i]=num%10+48;
	}
	s[i+1]='\0';
	for(j=0;j<=i;j++)		//将s数组中的字符串倒序存储到o数组中
	{
		o[i-j]=s[j];
	}
	o[i+1]='\0';
	h(o);				//调用函数h，判断输入的num是否是回文数
}	
