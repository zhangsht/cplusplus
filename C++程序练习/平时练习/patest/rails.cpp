#include<stack>
#include <iostream>
using namespace std;
stack<int>number;
int n;
int s[1100];
int judge()
{
     int i=1,j=0;
   while(j<n&&i<=n+1)
    {
        if(number.empty()||number.top()!=s[j+1])
        {
            number.push(i);
            i++;
        }
        else
        if(number.top()==s[j+1])
        {
            number.pop();
            j++;
            if(j==n-1)return 1;
        }
    }
    return 0;
}
int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        while(cin>>s[1])
        {
        if(s[1]==0)break;
        for(int i=2;i<=n;i++)
        cin>>s[i];
        if(judge())
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
