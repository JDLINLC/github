#include <iostream>
// #include <fstream>
#include <string>

using namespace std;
// ifstream fin("in.txt");

const int N = 50000 + 1;

int n = 0, T = 0, result = 0;
string word[N];
// used to record a word is how many words' prefix
// int prefix[N];

int init(int num);
int input();
int output();
bool judge(int i, int j);

int main(void)
{
	//cin>>T;
	cin>>T;
	for(int t = 0; t != T; t++)
	{
		//cin>>n;
		cin>>n;
		init(n);
		input();
		for(int i = 0; i != n; i++)
		    for(int j = 0; j != n; j++)
		        if(word[i].length() < word[j].length())
		            judge(i, j);
		output();
	}
	
	return 0;
}

int init(int num)
{
	for(int i = 0; i != num; i++)
	{
	    word[i].clear();
	}
	return 0;
}

int input()
{
	for(int i = 0; i != n; i++)
	    cin>>word[i];
	return 0;
}

int output()
{
	cout<<result<<endl;
	result = 0;
	return 0;
}

bool judge(int i, int j)
{
	for(int k = 0; k != word[i].length(); k++)
	    if(word[i][k] != word[j][k])
	        return false;
	result++;
	return true;
}