#include <cstdio>
#include <queue>
using namespace std ;
#define maX 101

int m,n,d ;
int x[4] = {1,0,-1,0} ;
int y[4] = {0,1,0,-1} ;
char mp[maX][maX] ;
int visited[maX][maX][maX] ;

class Node {
public :
   int x,y,d,t ;
   Node ( ) {
      x = y = d = t = 0 ;
   }
   Node ( int xx, int yy, int dd, int tt )
     : x(xx) , y(yy) , d(dd) , t(tt) {
   }
};

queue<Node> q ;

inline bool InSpace ( int x , int y ) {
 if ( x < 1 || y < 1 || x > m || y > n ) return 0 ;
 return 1 ;
}

inline void bfs ( ) {
 while ( !q.empty() ) {
  Node temp ;
  temp = q.front() ;
  q.pop() ;
  if ( temp.x == m && temp.y == n ) {
   printf("%d\n",temp.t) ;
   return ;
  }
  int fd = temp.d ;
  int ft = temp.t ;
  for ( int i = 0 ; i < 4 ; ++i ) {
   int fx = temp.x + x[i] ;
   int fy = temp.y + y[i] ;

  // walk mode !
   if ( fx < 1 || fy < 1 || fx > m || fy > n ) continue ;
   if ( !visited[fx][fy][fd] && mp[fx][fy] == 'P'  ) {
    visited[fx][fy][fd] = 1 ;
    q.push(Node(fx,fy,fd,ft+1));
   }


  //  fly mode !
   int cnt = 0 ;
   for ( int j = 2 ; j <= fd ; ++j ) {
    fx = temp.x + x[i]*j ;
    fy = temp.y + y[i]*j ;
    if ( fx < 1 || fy < 1 || fx > m || fy > n ) break ;
    if ( !visited[fx][fy][fd-j]  && mp[fx][fy] == 'P' ) {
     visited[fx][fy][fd-j] = 1 ;
     q.push(Node(fx,fy,fd-j,ft+1));
    }
   }
  }
 }
 printf("impossible\n");
 return ;
}

int main () {
 int i,j,k ;
 scanf ( "%d%d%d",&m,&n,&d ) ;
// memset(visited,0,sizeof(visited)) ;
 for ( i = 1 ; i <= m ; ++i ) {
  getchar() ;
  for ( j = 1 ; j <= n ; ++j ) {
   scanf ( "%c", &mp[i][j] ) ;
   for( k = 0 ; k < maX ; ++k ) visited[i][j][k] = 0 ;
  }
 }
 visited[1][1][d] = 1 ;
 q.push(Node(1,1,d,0) ) ;
 bfs ( ) ;
// system("pause") ;
 return 0 ;
}