    #include <iostream>
    //#include <string>
     
    using namespace std;
     
    int n = 0;
    bool cal(int num);
    int change(int num);
     
    int main()
    {
    while(cin>>n)
    {
    if(cal(n))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    }
    return 0;
    }
     
    bool cal(int num)
    {
    int t = 4;
    while(t<=num)
    {
    if(num%t==0)
    return true;
    t = change(t);
    }
    return false;
    }
     
    int change(int num)
    {
    int mul = 1;
    int temp = num;
    while(temp/10>0&&temp%10==7)
    {
    mul*=10;
    temp/=10;
    }
    if(temp/10>0||temp==4)
    num+=3*mul;
    else
    {
    num+=4*mul*10;
    }
    // cout<<num<<"ji"<<endl;
    return num;
    } 
