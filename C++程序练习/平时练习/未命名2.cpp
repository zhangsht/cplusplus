#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1501 ;
vector<int> location[26] ;
int c[maxn*maxn] , d[maxn*maxn] ;

inline int get_max(int a,int b) {   return a > b ? a : b ;  }

//nlogn Çólcs
int lcs(char a[],char b[])
{
    int i , j , k , w , ans , l , r , mid ;
    for( i = 0 ; i < 26 ; i++) location[i].clear() ;
    for( i = strlen(b)-1 ; i >= 0 ; i--) location[b[i]-'a'].push_back(i) ;
    for( i = k = 0 ; a[i] ; i++)
    {
        for( j = 0 ; j < location[w=a[i]-'a'].size() ; j++,k++) c[k] = location[w][j] ;
    }
    d[1] = c[0] ;   d[0] = -1 ;
    for( i = ans = 1 ; i < k ; i++)
    {
        l = 0 ; r = ans ;
        while( l <= r )
        {
            mid = ( l + r ) >> 1 ;
            if( d[mid] >= c[i] ) r = mid - 1 ;
            else l = mid + 1 ;
        }
        if( r == ans ) ans++,d[r+1] = c[i] ;
        else if( d[r+1] > c[i] ) d[r+1] = c[i] ;
    }
    return ans ;
}

int main()
{
    char a[maxn] , b[maxn] ;
    while (~scanf("%s%s",a,b))
    {
        printf("%d\n",lcs(a,b));
    }
}
