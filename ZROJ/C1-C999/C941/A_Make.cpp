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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[200005][3], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
inline void Clr() {}
int main() {
  freopen("A.in", "w", stdout);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  n = 50001 + rand() % 50000; 
  for (register unsigned i(2); i <= n; ++i) {
    a[++m][0] = rand() % (i - 1) + 1;
    a[m][1] = i;
    a[m][2] = 9001 + rand() % 1000; 
  }
  m += rand() % 100001;
  for (register unsigned i(n); i <= m; ++i) {
    a[i][0] = rand() % n + 1;
    a[i][1] = rand() % n + 1;
    a[i][2] = 9001 + rand() % 1000; 
  }
  random_shuffle(a + 1, a + m + 1);
  printf("%u %u\n", n, m);
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u %u %u\n", a[i][0], a[i][1], a[i][2]);
  }
//  }
  return Wild_Donkey;
}

