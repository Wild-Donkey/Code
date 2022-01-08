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
unsigned f[1005], g[1005], m, n;
unsigned Ri[10005], Fl[10005];
unsigned A, B, C, D, t;
unsigned Cnt(1), Ans(0x3f3f3f3f), Tmp(0);
struct Col {
  unsigned Pos, Dw, Up;
  inline const char operator < (const Col& x) const {
    return this->Pos < x.Pos;
  }
}No[10005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD();
  for (unsigned i(1); i <= n; ++i) Ri[i] = RD(), Fl[i] = RD();
  for (unsigned i(1); i <= t; ++i) No[i].Pos = RD(), No[i].Dw = RD(), No[i].Up = RD();
  sort(No + 1, No + t + 1);
  for (unsigned i(1); i <= n; ++i) {
    memset(g, 0x3f, sizeof(g));
    for (unsigned j(m - Ri[i] + 1); j <= m; ++j) g[m] = min(g[m], f[j] + 1);
    for (unsigned j(m - Ri[i]); j; --j) g[j + Ri[i]] = min(g[j + Ri[i]], f[j] + 1);
    for (unsigned j(Ri[i] + 1); j <= m; ++j) g[j] = min(g[j], g[j - Ri[i]] + 1);
    for (unsigned j(m - Ri[i] + 1); j <= m; ++j) g[m] = min(g[m], g[j] + 1);
    for (unsigned j(Fl[i] + 1); j <= m; ++j) g[j - Fl[i]] = min(g[j - Fl[i]], f[j]);
    if (No[Cnt].Pos == i) {
      // printf("Colu %u: [%u, %u]\n", No[Cnt].Pos, No[Cnt].Dw, No[Cnt].Up);
      Ans = 0x3f3f3f3f, memset(f, 0x3f, sizeof(f));
      for (unsigned j(No[Cnt].Dw + 1); j < No[Cnt].Up; ++j) Ans = min(Ans, f[j] = g[j]);
      if (Ans >= 0x3f3f3f3f) {
        // printf("%u: ", i);
        // for (unsigned j(1); j <= m; ++j) printf("%u ", g[j]);
        // putchar(0x0A);
        printf("0\n%u\n", Cnt - 1);
        // system("pause");
        return 0;
      }
      Cnt++;
    }
    else memcpy(f, g, sizeof(f));
    // printf("%u: ", i);
    // for (unsigned j(1); j <= m; ++j) printf("%u ", f[j]);
    // putchar(0x0A);
  }
  Ans = 0x3f3f3f3f;
  for (unsigned j(1); j <= m; ++j) Ans = min(Ans, g[j]);
  if (Ans < 0x3f3f3f3f) printf("1\n%u\n", Ans);
  else printf("0\n%u\n", Cnt);
  //  }
  // system("pause");
  return Wild_Donkey;
}