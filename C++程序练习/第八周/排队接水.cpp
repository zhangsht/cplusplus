#include <iostream>
#include <iomanip>
using namespace std;

struct waiter {
    int n;
    int t;
};

int main() {
   int n, time;
   waiter tem[1001], tem2;
   
   cin >> n;
   for (int i = 0; i < n; i++) {
        cin >> time;
        tem[i].n = i + 1;
        tem[i].t = time;
   }
   
   int i, j, k;
   for (i = 0; i < n - 1; i++) {
       k = i;
       for (j = i + 1; j < n; j++) {
           if (tem[j].t < tem[k].t)  k = j;
           else if(tem[j].t == tem[k].t && tem[j].n < tem[k].n) k = j;
       }
       if (i != k) {
           tem2 = tem[i];
           tem[i] = tem[k];
           tem[k] = tem2;
       }
   }
   
   long double tot = 0, tot2 = 0;
   for (int i = 0; i < n - 1; i++) {
       cout << tem[i].n << ' ';
       tot +=  tem[i].t;
       tot2 += tot;
   }
   cout <<  tem[n - 1].n << endl;
   
   cout << setiosflags(ios::fixed) << setprecision(2) << tot2 / n << endl;
   return 0;
}

