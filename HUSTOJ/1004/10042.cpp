#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int N = 50000 + 1;

int n = 0, T = 0, result = 0;
char word[N][30];

int init(int num);
int input();
int output();
bool judge(int i, int j);

int main(void)
{
	cin>>T;
	for(int t = 0; t != T; t++)
	{
		cin>>n;
		init(n);
		input();
		for(int i = 0; i != n; i++)
		    for(int j = 0; j != n; j++)
		        if(strlen(word[i]) < strlen(word[j]))
		            judge(i, j);
		output();
	}
	
	return 0;
}

int init(int num)
{
	for(int i = 0; i != num; i++)
	    word[i][0] = '\0';
	return 0;
}

int input()
{
	for(int i = 0; i != n; i++)
	    fscanf(stdin, "%s", word[i]);
	return 0;
}

int output()
{
	cout<<(result%11519)<<endl;
	result = 0;
	return 0;
}

bool judge(int i, int j)
{
	for(int k = 0; k != strlen(word[i]); k++)
	    if(word[i][k] != word[j][k])
	        return false;
	result++;
	return true;
}