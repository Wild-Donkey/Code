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
multiset<pair<unsigned, unsigned> > a;
unsigned m, n, c;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
struct Ans {
  unsigned Fir, Sec, FirSi;
}Way[5005];
inline void Clr() {
  a.clear(), Flg = 0;
}
signed main() {
  // freopen("dish.in", "r", stdin);
  // freopen("dish.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD(), m = RD(), c = RD();
    for (unsigned i(1); i <= n; ++i) a.insert(make_pair(RD(), i));
    for (unsigned i(1); i <= m; ++i) {
      // printf("Now Round %u:\n", i);
      // for (auto j : a) printf("(%u, %u) ", j.first, j.second);
      // putchar(0x0A);
      unsigned Num((a.begin())->second), Now((a.begin())->first);
      a.erase(a.begin());
      if (Now < c) {
        Way[i].Fir = Num, Way[i].FirSi = Now;
        multiset<pair<unsigned, unsigned> >::iterator It(a.lower_bound(make_pair(c - Now, 0)));
        if (It == a.end()) {
          printf("-1\n"), Flg = 1;
          break;
        }
        else {
          unsigned Snu(It->second), Sno(It->first);
          a.erase(It);
          Way[i].Sec = Snu;
          if (Sno + Now > c) a.insert(make_pair(Sno + Now - c, Snu));
        }
      }
      else {
        Way[i].Fir = Num, Way[i].FirSi = c;
        a.insert(make_pair(Now - c, Num));
      }
    }
    if (!Flg) {
      for (unsigned i(1); i <= m; ++i) {
        if (Way[i].FirSi == c) printf("%u %u\n", Way[i].Fir, c);
        else printf("%u %u %u %u\n", Way[i].Fir, Way[i].FirSi, Way[i].Sec, c - Way[i].FirSi);
      }
    }
  }
  system("pause");
  return Wild_Donkey;
}