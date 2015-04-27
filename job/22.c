#include<stdio.h>

enum {COPY,COMMIT};

int main(void)
{
	int state;
	int n,i;
	char ch;

	scanf("%d",&n);
	while(getchar()!='\n')
	  ;
	for(i=0;i<n;i++)
	{
		state=COPY;

		while((ch=getchar())!='\n')
		{
			switch(state)
			{
				case COPY:
					putchar(ch);
					if(ch==' ')
					{
						state=COMMIT;
					}
					break;
				case COMMIT:
					if(ch!=' ')
					{
						putchar(ch);
						state=COPY;
					}
					break;
				default:
					break;
			}
		}

		putchar('\n');
	}

	return 0;
}
