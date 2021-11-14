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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[2005][2005];
inline void Clr() {}
int main() {
  freopen("B.in", "w", stdout);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  memset(b, '.', sizeof(b));
  n = 1701 + rand() % 300, m = 1701 + rand() % 300; 
  B = 500;
  A = rand() * rand() % (n * m - B);
  for (register unsigned i(1); i <= A; ++i) {
    C = rand() % n + 1;
    D = rand() % m + 1; 
    while (b[C][D] != '.') {
      C = rand() % n + 1;
      D = rand() % m + 1; 
    }
    b[C][D] = '#'; 
  }
  for (register unsigned i(1); i <= B; ++i) {
    C = rand() % n + 1;
    D = rand() % m + 1; 
    while (b[C][D] != '.') {
      C = rand() % n + 1;
      D = rand() % m + 1; 
    }
    b[C][D] = '+'; 
  }
  printf("%u %u\n", n, m);
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      putchar(b[i][j]);
    }
    putchar('\n');
  }
//  }
  return Wild_Donkey;
}

