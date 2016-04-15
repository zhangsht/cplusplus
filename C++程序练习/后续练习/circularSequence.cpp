#include <cstdio>
using namespace std ;
#define maxn 200009
#define max(a,b) a>b?a:b 

int t,n;
int a[maxn];

long long calc () {
    long long sum = 0 , ans = -2119999999 ;
    for ( int i = 0 ; i < n ; ++i ) {
        sum += a[i] ;
        if ( sum > ans ) ans = sum ;
        if ( sum < 0 ) sum = 0 ;
    }
    return ans ;
}
int main () {

    scanf ( "%d" , &t ) ;
    while ( t-- ) {
        scanf ( "%d" , &n ) ;
        bool flag = 1 ;
        long long maxx = -2119999999 , sum ;
        for ( int i = 0 ; i < n ; ++i ) {
            scanf ( "%d" , &a[i] ) ;
            if ( a[i] >= 0 ) flag = 0 ;
            if ( flag ) maxx = max ( maxx , a[i] ) ;
        }
        if ( flag ) {
            printf ( "%lld\n" , maxx ) ;
            continue ;
        }
        
        maxx = calc () , sum = 0 ;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += a[i] ;
            a[i] = -a[i] ;
        }
        printf ( "%lld\n" , max(maxx,sum+calc()) ) ;
        //printf ( "DD %d" , c[m] ) ;
    }
    //system ( "pause" ) ;
    return 0 ;
} 
