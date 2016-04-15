#include <iostream>
#include <stdio.h>
#include <memory.h>


using namespace std;
int n;
int coun[26] = {0}, temp[26]={0}, sum = 0;
int f[26],d[26],t[26];
int h = 0;

int main()
{
    while(cin>>n)
    {
        if(n == 0)
            break;
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        memset(t,0,sizeof(t));
        scanf("%d",&h);
        h *= 12;
        for(int i = 0; i < n; i ++)
            scanf("%d",&f[i]);
        for(int i = 0; i < n; i ++)
            scanf("%d",&d[i]);
        for(int i = 0; i < n-1; i ++)
            scanf("%d",&t[i]);
        memset(coun,0,sizeof(coun));

        sum = -1;
        for(int i = 0; i < n; i ++)
        {
            memset(temp,0,sizeof(temp));
            int tim = 0;
            for(int j = 0; j < i; j ++)
            {
                tim += t[j];
            }
            tim = h - tim;
            //printf("%d\n",tim);
            int tf[26];
            memcpy(tf,f,sizeof(tf));
            /*for(int i = 0; i <n; i++)
                printf("%d\n",tf[i]);
             */
            int ts = 0;
            for(int k = 0; k < tim; k ++)
            {
                int ti = 0; //compute the max lake
                int tn = 0; // the index
                for(int j = 0; j <= i; j ++)
                {    if( tf[j] > ti)
                {
                    ti = tf[j];
                    tn = j;
                }
                }
                if(ti == 0)
                {
                    temp[0] += tim - k;
                    break;
                }
                ts += ti;
                tf[tn] -= d[tn];
                if( tf[tn] < 0 )
                    tf[tn] = 0;
                temp[tn] ++;
            }
            if(ts > sum)
            {
                sum = ts;
                memcpy(coun,temp,sizeof(coun));
            }
        }
        printf("%d",coun[0]*5);
        for(int i = 1; i < n; i ++)
            printf(", %d",coun[i]*5);
        printf("\n");
        printf("Number of fish expected: %d \n\n",sum);
    }

    return 0;
}
