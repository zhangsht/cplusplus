#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//������ת��Ϊ�ַ���
string convertstrtoint(int j){
  stringstream tempstream;
  tempstream<<j;
  string i;
  tempstream>>i;
  return i;
}

//�ݹ���⡣����
string recsmallt(int n,string result,int curtotal, int total) {
    string temp="";
    if(curtotal==total)  return result+",";
    
    for(int j=n; j>0; j--) {
       if (curtotal + j == total)
           temp=temp + result+"+"+convertstrtoint(j)+"\n";
       if (curtotal + j<total)
         temp=temp + recsmallt(j,result+"+"+convertstrtoint(j),curtotal+j,total);
    }
    return temp;
}

void getres(int n) {
  string finalresult="";
  for(int j=n;j>0;j--) {
     finalresult=recsmallt(j,convertstrtoint(j),j,n);
       //ȥ�������Ķ���
     finalresult.resize(finalresult.size()-1);
     cout<<finalresult<<endl;
  }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        getres(n);
    }
    return 0;
}
