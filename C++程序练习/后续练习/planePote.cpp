#define MAX_SIZE 300
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Period {
  float average;
  int length;
  int end;
};

bool operator< (const Period &a, const Period &b) {
  if (fabs(a.average - b.average) > 1e-6) return a.average > b.average;
  if (a.length != b.length) return a.length > b.length;
  return a.end < b.end;
}

int main() {
  int runs;
  cin >> runs;
  int quarters, requested, min;
  int quars[MAX_SIZE + 1];   // abandons quars[0]
  Period periods[MAX_SIZE*MAX_SIZE];

  for (int run = 1; run <= runs; run++) {
    cin >> quarters >> requested >> min;
    for (int i = 1; i <= quarters; i++) {
      cin >> quars[i];
    }

    int count = 0;
    for (int i = 1; i <= quarters; i++) {
      int sum = 0;
      for (int j = i; j <= quarters; j++) {
        sum += quars[j];
        if (j - i + 1 >= min) {
          periods[count].length = j - i + 1;
          periods[count].end = j;
          periods[count].average = (double)sum / (j - i + 1);
          count++;
        }
      }
    }
    sort(periods, periods + count);

    cout << "Result for run " << run << ":" << endl;
    for (int i = 0;i < requested && i < count; i++) {
      cout << periods[i].end - periods[i].length + 1;
      cout << "-" << periods[i].end << endl;
    }
  }
  return 0;
}
