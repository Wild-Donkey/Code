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
const unsigned Mi(2500001);
multiset<pair<unsigned, unsigned> > S;
bitset<5000005> f[505];
int b[505];
unsigned a[505], m, n, c;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
inline void Clr() {
  Flg = 0;
}
inline void Roll(unsigned x) {
  S.clear();
  unsigned Now(Mi + c);
  for (unsigned i(x); i; --i) {
    if (f[i - 1][Now]) continue;
    S.insert(make_pair(a[i], i)), Now -= b[i], a[i] = 0x3f3f3f3f;
  }
}
inline void Do(unsigned x) {
  for (unsigned i(1); i <= x; ++i) {
    unsigned Num((S.begin())->second), Now((S.begin())->first);
    S.erase(S.begin());
    if (Now < c) {
      // printf("Size %u\n", S.size());
      unsigned Snu((--(S.end()))->second), Sno((--(S.end()))->first);
      S.erase(--(S.end()));
      printf("%u %u %u %u\n", Num, Now, Snu, c - Now);
      if (Sno + Now > c) S.insert(make_pair(Sno + Now - c, Snu));
    }
    else {
      printf("%u %u\n", Num, c);
      if (Now > c) S.insert(make_pair(Now - c, Num));
    }
  }
}
signed main() {
  freopen("dish.in", "r", stdin);
  freopen("dish.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD(), m = RD(), c = RD();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    if (n - 2 == m) {
      for (unsigned i(1); i <= n; ++i) b[i] = c - a[i];
      f[1] = 0, f[1][Mi + b[1]] = 1;
      for (unsigned i(2); i <= n; ++i) {
        f[i] = 0;
        if (b[i] >= 0) f[i] = f[i - 1] | (f[i - 1] << b[i]);
        else f[i] = f[i - 1] | (f[i - 1] >> (-b[i]));
        if (f[i][Mi + c]) { Flg = 1, Roll(i), m -= S.size() - 1, Do(S.size() - 1); break; }
      }
      if (!Flg) { printf("-1\n"); continue; }
    }
    S.clear();
    for (unsigned i(1); i <= n; ++i) if (a[i] < 0x3f3f3f3f) S.insert(make_pair(a[i], i));
    Do(m);
  }
  // system("pause");
  return Wild_Donkey;
}