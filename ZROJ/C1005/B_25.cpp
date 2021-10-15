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
#include <string>
#include <vector>
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
unsigned long long A, B;
pair<unsigned, unsigned> a[200005];
unsigned m, n;
unsigned C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Ans[2][200005];
char Choice[200005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  srand(20041205);
//  srand(20041022);
//  srand(87543);
  n = RD(), m = n - RD();
  for (unsigned i(1); i <= n; ++i) a[i].first = RD(), a[i].second = i;
//  printf("%u Times\n", 100000000 / n);
  for (unsigned T(20000000 / n); T; --T) {
    random_shuffle(a + 1, a + n + 1);
    C = D = A = B = 0;
//    for (unsigned i(1); i <= n; ++i) printf("a[%u] %u\n", a[i].second, a[i].first);
    for (unsigned i(1); i <= n; ++i) {
      if (A < B) {
        Choice[a[i].second] = 0;
        A += a[i].first;
      } else {
        Choice[a[i].second] = 1;
        B += a[i].first;
      }
      if((A == B) && (i >= m)) {
//        printf("%u Times At last\n", (100000000 / n) - T + 1);
        for (unsigned j(1); j <= i; ++j) {
          if(Choice[a[j].second]) Ans[1][++C] = a[j].second;
          else Ans[0][++D] = a[j].second;
        }
        printf("%u ", C);
        for (unsigned j(1); j <= C; ++j) printf("%u ", Ans[1][j]);
        printf("\n%u ", D);
        for (unsigned j(1); j <= D; ++j) printf("%u ", Ans[0][j]);
        putchar(0x0a);
        return 0;
      }
    }
  }
  printf("-1\n");
//  }
  return Wild_Donkey;
}

