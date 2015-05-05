#include<stdio.h>

int main(void)
{
	int num[10]={0,0,0,0,0,0,0,0,0,0};
	int character=0,other=0;
	char ch;

	while((ch=getchar())!=EOF)
	{
		if(ch>='0'&&ch<='9')
		{
			num[ch-'0']++;
		}
		else if(ch>='a'&&ch<='z')
		{
			character++;
		}
		else if(ch>='A'&&ch<='Z')
		{
			character++;
		}
		else 
		{
			other++;
		}
	}
	
	int i;
	for(i=0;i<10;i++)
	{
		printf("Number %d: %d\n",i,num[i]);
	}
	printf("characters: %d\n",character);
	printf("other: %d\n",other);

	return 0;
}
