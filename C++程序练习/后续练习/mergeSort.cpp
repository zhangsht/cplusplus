#include <cstdio>
#include <list>
using namespace std;

int main() {
    int totalNum, interval;
    while(scanf("%d%d", &totalNum, &interval) && totalNum) {
        list<int> numList;
        int temp;
        while(totalNum--) {
            scanf("%d", &temp);
            numList.push_back(temp);
        }

        numList.sort();

        list<int>::iterator numIter;
        numIter = numList.begin();

        while(true) {
            int count = 0;
            printf("%d", *numIter);
            while(count != interval){
                count++;
                numIter++;
                if(numIter == numList.end()) {
                    break;
                }
            }

            if(numIter == numList.end()) {
                break;
            }
            else {
                printf(" ");//最后一个不输出空格
            }

        }
        printf("\n");
    }
    return 0;
}