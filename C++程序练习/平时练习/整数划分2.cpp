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

void split(int n,int k)//k�������е�λ�ã����ǵݹ����
{
    void display(int k);
    int i;
    if(n==0)//�ֽ���ɣ�������
        display(k);
    else
        for(i=n;i>0;i--)
            if(k==0||i<=x[k-1])
            {
                x[k]=i;//д������
                split(n-i,k+1);
            }
}

//�������ǰk��
void display(int k)
{
    int i;
    for(i=0;i<k;i++)
        printf("%d ",x[i]);
    printf("\n");
}
