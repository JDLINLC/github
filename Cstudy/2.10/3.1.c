#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char ch;
	FILE *fp;

	if((fp=fopen("3.1.write.dat","w"))==NULL)
	{
		printf("Can't open the file!\n");
		exit(-1);
	}
	while((ch=fgetc(stdin))!=EOF)
	{
		fputc(fp,ch);
	}
	fclose(fp);

	return 0;
}
