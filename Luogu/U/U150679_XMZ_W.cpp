#include <algorithm>
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
#define Lbt(x) ((x)&((~(x))+1))
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
unsigned Mod(1000000007);
unsigned Tr[6][200005];
unsigned a[200005], b[200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Insert(unsigned* Des) {
  while (A <= Cnt) {
    Des[A] += B;
    if(Des[A] >= Mod) Des[A] -= Mod;
    A += Lbt(A);
  }
}
inline void Find(unsigned* Des) {
  Tmp = 0;
  while (A) {
    Tmp += Des[A];
    if(Tmp >= Mod) Tmp -= Mod;
    A -= Lbt(A);
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
  sort(b + 1, b + n + 1), Cnt = unique(b + 1, b + n + 1) - b;
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + Cnt, a[i]) - b + 1;
  A = 1, B = 1, Insert(Tr[0]);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= 5; ++j) {
      if(j & 1) {
        A = a[i] - 1, Find(Tr[j - 1]);
        A = a[i], B = Tmp, Insert(Tr[j]);
      }else {
        A = Cnt, Find(Tr[j - 1]), B = Tmp + Mod;
        A = a[i], Find(Tr[j - 1]), B -= Tmp;
        if(B >= Mod) B -= Mod;
        A = a[i], Insert(Tr[j]);
      }
    }
  }
  A = Cnt, Find(Tr[5]); 
  printf("%u\n", Tmp);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

