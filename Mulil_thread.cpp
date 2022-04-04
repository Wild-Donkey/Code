#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <thread>
#include <pthread.h>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long a[1005][1005], b[1005][1005], c[1005][1005], m, n;
void *Calc(void* z1, void* z2) {
  unsigned x(*(unsigned*)z1), y(*(unsigned*)z2); 
  c[x][y] = 0;
  for (unsigned i(1); i <= n; ++i) c[x][y] += a[x][i] * b[i][y]; 
}
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = 1000;
  pthread_t *Tr[16];
//  for (unsigned i(0); i < 16; ++i) 
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) {
//      Calc(i, j);
      pthread_create(Tr[i], NULL, Calc, *i, *j);
      printf("(%u, %u)\n", i, j);
//      Tr.detach();
    }
  }
  printf("%u Done\n", clock());
//  }
  return Wild_Donkey;
}

