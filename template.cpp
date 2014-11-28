#include <iostream>
#include <fstream>

#define EDITING

using namespace std;
#ifdef EDITING
ifstream fin("in.txt");
#endif

bool input();
bool output();

int main()
{
  
  return 0;
}

bool input()
{
#ifdef EDITING
  
#else
  
#endif
 
  return true;
}

bool output()
{
  
  return true;
}