#include<stdio.h>
int main(void)
{
	int n,i;
	char name;
	float A,B,C,mid;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f%f%f",&A,&B,&C);
		if(A>B)
		{
			if(A>C)
			{
				if(B>C)
				{
					mid=B;
					name='B';
				}
				else
				{
					mid=C;
					name='C';
				}
			}
			else
			{
				mid=A;
				name='A';
			}
		}
		else
		{
			if(B>C)
			{
				if(C>A)
				{
					mid=C;
					name='C';
				}
				else
				{
					mid=A;
					name='A';
				}
			}
			else
			{
				mid=B;
				name='B';
			}
		}
		printf("%c:%.1f\n",name,mid);
	}

	return 0;
}
