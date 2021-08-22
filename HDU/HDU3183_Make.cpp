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
#define Wild_Donkey 0
using namespace std;
unsigned n;
signed main() {
  printf("FaQ\n");
  freopen("HDU3183.in", "w", stdout);
  srand(0);
  for (register unsigned T(1); T <= 1000; ++T) {
    n = (rand() % 1000) + 1;
    for (register unsigned i(1); i <= n; ++i) {
      putchar('0' + (rand() % 10));
    }
    putchar(' ');
    printf("%u\n", (rand() % (n + 1))); 
  }
  return Wild_Donkey;
}

