#include<stdio.h>
void bubble_sort(int num[],int n);
void select_sort(int num[],int n);
int main(void)
{
	int num_1[6]={4,6,3,2,5,1};
	int num_2[6]={4,6,3,2,5,1};

	printf("原序:\n4 6 3 2 5 1\n");
	printf("\nbubble_sort:\n");
	bubble_sort(num_1,6);
	printf("\nselect_sort:\n");
	select_sort(num_2,6);

	return 0;
}
void bubble_sort(int num[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
			if(num[j]>num[j+1])
				t=num[j],num[j]=num[j+1],num[j+1]=t;
		for(k=0;k<n;k++)
			printf("%d ",num[k]);
		printf("\n");
	}
}
void select_sort(int num[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(num[i]>num[j])
				t=num[i],num[i]=num[j],num[j]=t;
		for(k=0;k<n;k++)
			printf("%d ",num[k]);
		printf("\n");
	}
}
