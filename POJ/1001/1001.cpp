#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myNum
{
private:
	int dot;
	vector<int> value;
public:
	myNum();

	bool clear(){ dot = 0; value.clear();}
	// used to eliminate '0' don't need
	bool fix();

	bool operator = (string &str);
	bool operator = (myNum n);
	myNum operator + (myNum n);

	vector<int> &getValue(){ return value;}
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

bool myNum::fix()
{
	// after dot
	while(value[0] == 0 && dot > 0)
	{
		value.erase(value.begin());
		dot--;
	}
	// before dot
	while(value[value.size()-1] == 0)
	{
		value.pop_back();
	}
	return true;
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

	fix();

	return true;
}

bool myNum::operator = (myNum n)
{
	clear();

	for(int i = n.getValue().size() - 1; i >= 0; i--)
	{
		value.push_back(n.getValue()[i]);
	}
	dot = n.getDot();

	fix();

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
			n.getValue().insert(n.getValue().begin(), 0);
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
	int len1 = value.size(), len2 = n.getValue().size();
	int maxLen = len1 > len2 ? len1 : len2;

	for(int i = 0; i != maxLen; i++)
	{
		int t = 0;

		if(i < len1 && i < len2)
			t = (value[i] + n.getValue()[i] + add);
		else if(i >= len1 && i < len2)
			t = (0 + n.getValue()[i] + add);
		else if(i < len1 && i >= len2)
			t = (value[i] + 0 + add);
		else
			t = add;

		add = t/10;
		temp.getValue().push_back(t%10);
	}
	if(add != 0)
		temp.getValue().push_back(add);

	// reverse
	int len = temp.getValue().size();
	for(int i = 0; i != len/2; i++)
	{
		int t = temp.getValue()[i];
		temp.getValue()[i] = temp.getValue()[len - i - 1];
		temp.getValue()[len - i - 1] = t;
	}

	temp.setDot(dot);

	temp.fix();

	return temp;
}

int main()
{
	string str, str2;
	int pow = 0;
	myNum num1, num2, num3;

	while(cin>>str)
	{
	//	cout<<str<<" "<<pow<<endl;
		num1 = str;
		num1.test();
	}

	return 0;
}
