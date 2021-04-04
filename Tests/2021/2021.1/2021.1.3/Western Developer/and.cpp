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
inline unsigned int RD() {
  char ich(getchar());
  unsigned int intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  //  printf("RD %d\n", intmp);
  return intmp;
}
unsigned int ans(0), n;
struct Edge;
struct Node {
  unsigned char siz;
  unsigned int Son0 : 24, Son1 : 24;
} N[8500000], *cntn(N), *now(N);
void Add(const unsigned int &x) {
  Node *y(N);
  for (register int i(29); i >= 0; --i) {
    if (x & 1 << i) {
      if (!(y->Son1)) {
        y->Son1 = (++cntn) - N;
        N[y->Son1].siz = 0;
      }
      y = N + y->Son1;
      if (y->siz <= 1) {
        ++(y->siz);
      }
    } else {
      if (!(y->Son0)) {
        y->Son0 = (++cntn) - N;
      }
      y = N + y->Son0;
      if (y->siz <= 1) {
        ++(y->siz);
      }
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("and.in", "r", stdin);
  // freopen("and.out", "w", stdout);
  n = RD();
  for (register int i(1); i <= n; ++i) {
    Add(RD());
  }
  for (register int i(29); i >= 0; --i) {
    if (now->Son1) {
      if (N[now->Son1].siz >= 2) {
        ans += 1 << i;
        now = N + now->Son1;
        continue;
      }
    }
    now = N + now->Son0;
  }
  printf("%u\n", ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
8
10
2

3
853
76
2720
*/