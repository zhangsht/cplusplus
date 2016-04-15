#include<stdio.h>

int x[1000]={0};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        void split(int n,int k);
        int n;
        scanf("%d",&n);
        split(n,0);
    }
    return 0;
}

void split(int n,int k)//k是数组中的位置，亦是递归层数
{
    void display(int k);
    int i;
    if(n==0)//分解完成，输出结果
        display(k);
    else
        for(i=n;i>0;i--)
            if(k==0||i<=x[k-1])
            {
                x[k]=i;//写入数组
                split(n-i,k+1);
            }
}

//输出数组前k项
void display(int k)
{
    int i;
    for(i=0;i<k;i++)
        printf("%d ",x[i]);
    printf("\n");
}
