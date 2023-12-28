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
unsigned long long Ans;
unsigned m, n;
unsigned t;
unsigned Cnt(0), Tmp(0);
unsigned Ls[100005], Rs[100005], Lens[100005], Stack[100005], *STop(Stack);
inline void Clr() { n = RD(), Ans = 0; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) Ls[i] = RD();
    for (unsigned i(1); i <= n; ++i) Rs[i] = RD();
    sort(Ls + 1, Ls + n + 1);
    sort(Rs + 1, Rs + n + 1);
    Ls[n + 1] = Rs[n + 1] = 0x3f3f3f3f;
    for (unsigned i(1), j(1); j <= n;) {
      if (Ls[i] < Rs[j])
        *(++STop) = Ls[i++];
      else
        Lens[j] = Rs[j] - (*(STop--)), ++j;
    }
    for (unsigned i(1); i <= n; ++i) Ls[i] = RD();
    sort(Ls + 1, Ls + n + 1);
    sort(Lens + 1, Lens + n + 1);
    for (unsigned i(1), j(n); i <= n; ++i, --j)
      Ans += (unsigned long long)Ls[i] * Lens[j];
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}