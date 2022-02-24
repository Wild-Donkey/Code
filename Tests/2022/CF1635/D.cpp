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
const unsigned Mod(1000000007);
unsigned f[200005], a[200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
set<unsigned> S;
bitset<200005> Del;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) S.insert(a[i] = RD());
  for (unsigned i(1); i <= n; ++i) {
    A = a[i];
    while (A) {
      if (!(A & 3)) {
        A >>= 2;
        if (S.find(A) != S.end()) { Del[i] = 1; break; }
      }
      else {
        if (A & 1) {
          A >>= 1;
          if (S.find(A) != S.end()) { Del[i] = 1; break; }
        }
        else break;
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) if (!Del[i]) {
    unsigned j(30);
    while (!(a[i] >> j)) --j;
    ++f[j + 1];
  }
  Ans = f[1];
  for (unsigned i(2); i <= m; ++i) {
    f[i] += f[i - 1] + f[i - 2];
    if (f[i] >= Mod) f[i] -= Mod;
    if (f[i] >= Mod) f[i] -= Mod;
    Ans += f[i];
    if (Ans >= Mod) Ans -= Mod;
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}