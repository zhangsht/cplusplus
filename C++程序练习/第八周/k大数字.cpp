#include <cstdio>
#include <memory.h>
const int maxn=10000000;
int N,K;
bool tag[maxn*2+1];//标示位
int main() {
     scanf("%d%d",&N,&K);
     memset(tag,0,sizeof(tag));
     for(int i=0; i < N;i++) {
         int tmp;
         scanf("%d",&tmp);
         tag[tmp+maxn]=1;//标示tag位
     }
     int sum=0;
     for(int i=maxn*2; i>=0; i--) {
        if(sum+tag[i]==K){
         printf("%d\n",i-maxn);
         break;
       }
      sum+=tag[i];
    }
      return 0;
}
