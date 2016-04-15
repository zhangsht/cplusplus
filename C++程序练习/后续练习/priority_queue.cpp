#include <iostream>
#include <queue>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
    priority_queue<int> q;
    int n;
	srand((int)time(NULL));
	    for( int i= 0; i< 10; ++i ) q.push( rand());
	    while( !q.empty() ){
	        cout << q.top() << endl;
	        q.pop();
	    }

    return 0;
}
