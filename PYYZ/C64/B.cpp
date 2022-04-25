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
bitset<10000005> OK;
unsigned Bd[5000005];
char a[10000005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  memset(a, 0, (n << 1) + 1);
  for (unsigned i(1); i <= (n << 1); ++i) OK[i] = 0;
}
inline void KMP(char* x, unsigned y) {
//  printf("KMP it %u %u\n", x - a, y);
//  for (unsigned i(1); i <= y; ++i) putchar(x[i]); putchar(0x0A);
  if(y <= 1) return;
  Bd[1] = 0;
  for (unsigned i(2); i <= y; ++i) {
    unsigned Jump(Bd[i - 1]);
    while (Jump && (x[Jump + 1] ^ x[i])) Jump = Bd[Jump];
    if(x[Jump + 1] == x[i]) Bd[i] = Jump + 1;
    else Bd[i] = 0;
  }
//  printf("BD "); for (unsigned i(1); i <= y; ++i) printf("%u ", Bd[i]); putchar(0x0A);
  unsigned Len(Bd[y]), Cur(2);
  while (Len) {
    while (Cur <= y - Len) OK[Cur++] = 1; ++Cur;
    Len = Bd[Len];
  }
  while (Cur <= y) OK[Cur++] = 1;
}
signed main() {
//  freopen("loop2.in", "r", stdin);
//  freopen("loop.out", "w", stdout);
  while(scanf("%s", a + 1) == 1) {
    n = strlen(a + 1), a[n + 1] = a[1];
//    printf("Len %u\n", n);
    vector<unsigned> Cut;
//    for (unsigned i(n); i; --i) putchar(OK[i] + '0'); putchar(0x0A);
    for (unsigned i(1); i <= n; ++i) if(a[i] == a[i + 1]) Cut.push_back(i);
    if(!(Cut.size())) memcpy(a + n + 1, a + 1, n), KMP(a, n << 1);
    else {
      Cut.push_back(Cut[0] + n);
//      printf("Cut "); for (auto j:Cut) printf("%u ", j); putchar(0x0A);
      memcpy(a + n + 1, a + 1, Cut[0]);
      unsigned Len(Cut.size() - 1);
      for (unsigned i(0); i < Len; ++i) KMP(a + Cut[i], Cut[i + 1] - Cut[i]);
    }
    for (unsigned i(n); i; --i) putchar(OK[i] + '0'); putchar(0x0A);
    Clr();
  }
  return Wild_Donkey;
}

