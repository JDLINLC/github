    #include <iostream>
    #include <string>
     
    using namespace std;
     
    string str;
    bool quit = false;
     
    int main()
    {
    while(cin>>str)
    {
    for(int i = 0; i != str.length(); i++)
    if(str[i] != '4'&&str[i] != '7')
    {
    cout<<"NO"<<endl;
    quit = true;
    break;
    }
    if(!quit)
    {
    int L = 0, R = 0;
    for(int i = 0; i != str.length()/2; i++)
    L += int(str[i]);
    for(int i = str.length()/2; i != str.length(); i++)
    R += int(str[i]);
    if(L == R)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    }
    quit = false;
    }
    return 0;
    } 
