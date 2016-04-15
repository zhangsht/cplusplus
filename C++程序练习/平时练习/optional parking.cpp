#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int m,temp,min=100,max=-1;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>temp;
			if(temp>max) max=temp;
			if(temp<min) min=temp;
		}
		cout<<(max-min)*2<<endl;
	}
	return 0;
}
