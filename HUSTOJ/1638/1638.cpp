    #include <iostream>
    //#include <string>
     
    using namespace std;
     
    int n = 0, x = 0, y = 0;
     
    int main()
    {
    while(cin>>n>>x>>y)
    {
    int cnt = 0;
    int ps = n - y - 1;
    for(int i = 0; i != y+1; i++)
    {
    if(ps + i > x - 1)
    cnt++;
    }
    cout<<cnt<<endl;
    }
    return 0;
    } 
