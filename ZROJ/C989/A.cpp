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
unsigned long long Ans(0), Mod(998244353);
unsigned Dif[5000005], DifPre[5000005];
unsigned m, n, Pos, Cnt(0);
unsigned A, B, C, D, t;
char aP[5000005], * a(aP), Last(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 5000002, stdin);
  while (a[1] < 'A') ++a;
  while (a[n + 1] >= 'A') ++n;
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] == 'C') {
      if (Last == 'A') Dif[i] = 1, DifPre[Pos + 1] = 1;
      Last = 'C', Pos = i;
    }
    if (a[i] == 'A') {
      if (Last == 'C') Dif[i] = 1, DifPre[Pos + 1] = 1;
      Last = 'A', Pos = i;
    }
  }
  for (unsigned i(1); i <= n; ++i)
    Dif[i] += Dif[i - 1], DifPre[i] += DifPre[i - 1];
  for (unsigned long long i(1); i <= n; ++i)
    Ans = (Ans + Dif[i] * i) % Mod;
  for (unsigned long long i(1), j(n); i <= n; ++i, --j) {
    Ans = Mod + Ans - ((DifPre[i] * j) % Mod);
    if (Ans >= Mod) Ans -= Mod;
  }
  for (unsigned i(1); i <= n; ++i) {
    if (Dif[i] < DifPre[i]) {
      Ans += (++Cnt);
      if (Ans >= Mod) Ans -= Mod;
    }
    else Cnt = 0;
  }
  printf("%llu\n", Ans % Mod);
  //  }
  // system("pause");
  return Wild_Donkey;
}