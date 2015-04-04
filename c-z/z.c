/*一个用数组来存储大型整数的程序*/
#include<stdio.h>
int main(void)
{
	int n,i=0,j;
	char s[100],r[100];			//s用来存储倒序后的整数，r用来存储正序的整数

	printf("Enter an interger:\n");
	scanf("%d",&n);
	s[i]=(n%10)+48;				//将输入的整数的个位存进数组的第一位
	while(n/10!=0)				//用同样的方法将整数的每一位存入数组	
	{
		i +=1;
		n /=10;
		s[i]=(n%10)+48;
	}
	s[i+1]='\0';				//控制数组的结束	
	printf("%s\n",s);			
	for(j=0;j<=i;j++)			//将顺序改回来
	{
		r[i-j]=s[j];
	}
	printf("%s\n",r);			//输出字符串
	return 0;
}
