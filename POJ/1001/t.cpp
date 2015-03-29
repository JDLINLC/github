#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myNum
{
private:
  
public:
	myNum();
	
	int dot;
	vector<int> value;
	
	bool clear(){ dot = 0; value.clear();}
	bool operator = (string &str);
	bool operator = (myNum n);
	myNum operator + (myNum n);

	int getDot() const { return dot;}
	void setDot(int d) { dot = d;}

	void test()
	{
		for(int i = 0; i != value.size(); i++)
			cout<<value[i];
		cout<<":Dot="<<dot<<":size="<<value.size()<<endl;
	}
};

myNum::myNum()
{
	clear();
}

bool myNum::operator = (string &str)
{
	clear();

	for(int i = 0; i != str.length(); i++)
	{
		if(str[str.length() - 1 - i] == '.')
		{
			dot = i;
		}
		else
		{
			value.push_back(str[str.length() - 1 - i] - '0');
		}
	}

	return true;
}

bool myNum::operator = (myNum n)
{
	clear();

	for(vector<int>::iterator it = n.value.end(); it != n.value.begin(); it--)
	{
		value.push_back((*it));
	}
	dot = n.getDot();

	return true;
}

myNum myNum::operator + (myNum n)
{
	// figure the matter of dot
	int d = 0;
	if(dot > n.getDot())
	{
		d = dot - n.getDot();
		for(int i = 0; i != d; i++)
			n.value.insert(n.value.begin(), 0);
		n.setDot(dot);
	}
	else
	{
		d = n.getDot() - dot;
		for(int i = 0; i != d; i++)
			value.insert(value.begin(), 0);
		dot = n.getDot();
	}

	// plus
	myNum temp;
	int add = 0;
	int len1 = value.size(), len2 = n.value.size();
	int maxLen = len1 > len2 ? len1 : len2;
//	cout<<"maxlen="<<maxLen<<endl;
	for(int i = 0; i != maxLen; i++)
	{
		int t = 0;

		if(i < len1 && i < len2)
			t = (value[i] + n.value[i] + add);
		else if(i >= len1 && i < len2)
			t = (0 + n.value[i] + add);
		else if(i < len1 && i >= len2)
			t = (value[i] + 0 + add);
		else
			t = add;

		add = t/10;
		temp.value.push_back(t%10);
		cout<<"p"<<temp.value[i];
	}
	if(add != 0)
		temp.value.push_back(add);
	cout<<"p"<<add<<endl;

	// reverse
/*
	int len = temp.getValue().size();
	for(int i = 0; i != len/2; i++)
	{
		int t = temp.getValue()[i];
		temp.getValue()[i] = temp.getValue()[len - i - 1];
		temp.getValue()[len - i - 1] = t;
	}
*/
	temp.setDot(dot);

	return temp;
}

int main()
{
	string str, str2;
	int pow = 0;
	myNum num1, num2, num3;

	while(cin>>str>>str2)
	{
	//	cout<<str<<" "<<pow<<endl;
		num1 = str;
		num2 = str2;
		num3 = (num1 + num2);
		num3.test();
	}

	return 0;
}
