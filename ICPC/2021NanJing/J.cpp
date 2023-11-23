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
unsigned a, b, m, n;
unsigned A, B, C, D, t;
unsigned Fct[30], CntF(0);
unsigned Pri[20005], CntP(0);
char NoP[100005];
map<unsigned long long, unsigned> F;
inline void Clr() {
  a = RD(), b = RD(), CntF = 0;
  F.clear();
  if (a < b) swap(a, b);
  D = a - b;
  for (unsigned i(1); i <= CntP; ++i)
    if (!(D % Pri[i])) {
      Fct[++CntF] = Pri[i];
      while (!(D % Pri[i])) D /= Pri[i];
    }
  if (D != 1) Fct[++CntF] = D;
  // for (unsigned i(1); i <= CntF; ++i) printf("%u ", Fct[i]);
  // putchar(0x0A);
}
inline unsigned DFS(unsigned x, unsigned y) {
  if (y == 1) return 0;
  unsigned long long Cond(((unsigned long long)x << 32) + y);
  if (F[Cond]) return F[Cond];
  unsigned Rt(y - 1);
  for (unsigned i(1); i <= CntF; ++i)
    if (!((x - y) % Fct[i])) {
      Rt = min(Rt, DFS(x / Fct[i], y / Fct[i]) + x % Fct[i] + 1);
      Rt = min(Rt,
               DFS(x / Fct[i] + 1, y / Fct[i] + 1) + Fct[i] - (x % Fct[i]) + 1);
    }
  F[Cond] = Rt;
  return Rt;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (unsigned i(2); i <= 100000; ++i) {
    if (!NoP[i]) Pri[++CntP] = i;
    for (unsigned j(1); j <= CntP && i * Pri[j] <= 100000; ++j) {
      NoP[i * Pri[j]] = 1;
      if (!(i % Pri[j])) break;
    }
  }
  // for (unsigned i(1); i <= 20; ++i) printf("%u ", Pri[i]);
  // putchar(0x0A);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    printf("%u\n", DFS(a, b));
  }
  //  system("pause");
  return Wild_Donkey;
}