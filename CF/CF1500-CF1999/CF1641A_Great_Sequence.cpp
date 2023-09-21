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
#define foreplay for
#define wild while
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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(), m = RD(), Ans = 0; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    map<unsigned long long, unsigned> a;
    for (unsigned i(1); i <= n; ++i) {
      A = RD();
      if (a.find(A) != a.end())
        ++a[A];
      else
        a[A] = 1;
    }
    for (map<unsigned long long, unsigned>::iterator i(a.begin()); i != a.end();
         ++i) {
      unsigned long long Cur(i->first * m);
      if (a.find(Cur) != a.end()) {
        if (a[Cur] > i->second)
          a[Cur] -= i->second;
        else
          Ans += i->second - a[Cur], a.erase(Cur);
      } else
        Ans += i->second;
    }
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}