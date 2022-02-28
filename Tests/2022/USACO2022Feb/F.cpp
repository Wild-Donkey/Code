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
vector <unsigned> Popd;
set<unsigned> Box, InBox[10005];
unsigned Cnt[10005], a[100005], m, n, K;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
char Flg(0);
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) InBox[i].clear();
  Popd.clear(), Box.clear();
  memset(Cnt, 0, (n + 1) << 2);
  n = RD(), m = RD(), K = RD(), Flg = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    unsigned Cur(1);
    for (unsigned i(1); i <= m; ++i) ++Cnt[a[i] = RD()];
    for (unsigned i(1); i <= n; ) {
      // printf("Doing %u Popd %u Box %u\n", Popd.size(), Box.size());
      // for (auto j : Box) printf("%u ", j); putchar(0x0A);
      while (Cnt[i] && (Box.size() < K)) {
        if (Cur > m) {
          unsigned Pop(*(Popd.rbegin()));
          Popd.pop_back();
          if (a[Pop] < i + K) --Cnt[a[Pop]];
          else InBox[a[Pop]].insert(Pop), Box.insert(Pop);
        }
        if (a[Cur] < i + K) --Cnt[a[Cur++]];
        else InBox[a[Cur]].insert(Cur), Box.insert(Cur++);
      }
      if (!Cnt[i]) {
        ++i;
        if ((i + K - 1) <= n) for (auto k : InBox[i + K - 1]) Box.erase(k), --Cnt[a[k]];
        continue;
      }
      if (Box.size() == K) {
        if (Cur <= m) Popd.push_back(*(Box.begin())), InBox[a[*(Box.begin())]].erase(*(Box.begin())), Box.erase(Box.begin());
        else { Flg = 1; break; }
      }
    }
    // if (<= n) Flg = 1;
    printf(Flg ? "NO\n" : "YES\n");
  }
  //  system("pause");
  return Wild_Donkey;
}