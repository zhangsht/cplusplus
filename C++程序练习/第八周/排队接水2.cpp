#include <cstdio>
#include <cstdlib>
struct User{
    int data;
    int inputOrder;
};


    int main() {
        int peopleNumber;
        scanf("%d",&peopleNumber);
        
        User users[1003];
        int d;
        for (int i=1;i<=peopleNumber;i++) {
            scanf("%d",&d);
            users[i].data = d;
            users[i].inputOrder = i;
        }
        
        for (int j=1;j<peopleNumber;j++) {
            int temp=j;
            for(int k=j+1;k<=peopleNumber;k++) {
                if(users[temp].data>users[k].data)
                    temp=k;
                else if(users[temp].data==users[k].data&&users[temp].inputOrder>users[k].inputOrder)
                   temp=k;
            }


              int exchange;


              exchange=users[temp].data;
              users[temp].data=users[j].data;
              users[j].data=exchange;


             exchange=users[temp].inputOrder;
             users[temp].inputOrder=users[j].inputOrder;
             users[j].inputOrder=exchange;
    }
    double result;
    for(int i=1;i<=peopleNumber;i++)
    {

    printf("%d",users[i].inputOrder);
    if(i==peopleNumber) printf("\n");
    else printf(" ");

    result+=(peopleNumber-i)*users[i].data;

    }
    printf("%.2lf\n",result/peopleNumber);



    return 0;
}
