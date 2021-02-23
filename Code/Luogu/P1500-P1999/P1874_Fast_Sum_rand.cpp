#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int a, n, sum(0);
string s;
int main() {
  freopen("P1874.in", "w", stdout);
  srand(time(0));
  n = rand() % 6 + 1;
  for (register int i(1); i <= n; ++i) {
    a = rand() % 1000;
    sum += a;
    printf("%d", a);
    if (rand() % 1) {
      printf("0000000");
    }
  }
  printf("\n%d\n", sum);
  fclose(stdout);
  return 0;
}