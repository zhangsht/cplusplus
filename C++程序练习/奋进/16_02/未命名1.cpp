#include <iostream>
#include <list>
using namespace std;

void max(int a, int b)
{
    cout<<"now call max("<<a<<","<<b<<")..."<<endl;
    int t = a>b?a:b;
    cout<<t<<endl;
}
void min(int a, int b)
{
    cout<<"now call min("<<a<<","<<b<<")..."<<endl;
    int t = a<b?a:b;
    cout<<t<<endl;
}
typedef void (*myFun)(int a, int b); //����һ������ָ����������max,min

//�ص�����
void callback(myFun fun, int a, int b)
{
    fun(a,b);
}
int main()
{
    int i = 10;
    int j = 55;
    callback(max,i,j); 

    callback(min,i,j);
}
