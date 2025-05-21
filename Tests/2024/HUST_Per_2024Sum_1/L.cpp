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
inline unsigned long long RDll() {
  unsigned long long intmp(0);
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
unsigned long long m;
unsigned long long Size[100005];
unsigned n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
vector<unsigned> Fa[100005];
unsigned Find(unsigned x, unsigned long long y) {
  for (auto i : Fa[x]) {
    if (Size[i] >= y) return Find(i, y);
    y -= Size[i];
  }
  return x;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    Tmp = RD(), Size[i] = 1;
    for (unsigned j(1); j <= Tmp; ++j) {
      A = RD();
      Fa[i].push_back(A);
      if (Size[i] < 10000000000000000) Size[i] += Size[A];
    }
  }
  m = RDll();
  printf("%u\n", Find(n, m));
  //  }
  //  system("pause");
  return Wild_Donkey;
}