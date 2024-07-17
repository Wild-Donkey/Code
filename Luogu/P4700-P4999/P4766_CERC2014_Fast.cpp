#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
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
unsigned b[605], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
unsigned f[605][605];
struct Alien {
  unsigned L, R, Val;
}a[305];
inline unsigned Do (const unsigned Fr, const unsigned To) {
  unsigned U(0x3f3f3f3f), D(0);
  for (unsigned i(Fr); i <= To; ++i) U = min(U, a[i].L), D = max(D, a[i].R);
  if(Fr == To) f[U][D] = a[Fr].Val;
  if(f[U][D] < 0x3f3f3f3f) return f[U][D];
  unsigned Mid(Fr), Mdl, Mdr, Mdv, Ri(To), Le(Fr);
  for (unsigned i(Fr); i <= To; ++i) if(a[Mid].Val < a[i].Val) Mid = i;
  Mdl = a[Mid].L, Mdr = a[Mid].R, Mdv = a[Mid].Val, Mid = 0x3f3f3f3f;
  for (unsigned j(To); j >= Fr; --j) if(a[j].L > Mdl) swap(a[j], a[Ri--]);
  for (unsigned i(Mdl); i <= Mdr; ++i) {
    unsigned Tmp(0);
    for (unsigned j(Le); j <= To; ++j) if(a[j].R < i) swap(a[j], a[Le++]);
    for (unsigned j(To); j > Ri; --j) if(a[j].L == i) swap(a[j++], a[++Ri]);
    if(Le > Fr) Tmp = Do(Fr, Le - 1);
    if(Ri < To) Tmp += Do(Ri + 1, To);
    Mid = min(Mid, Tmp);
  }
  f[U][D] = Mid + Mdv;
  return f[U][D];
}
signed main() {
  freopen("P4766_2.in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    n = RD();
    for (unsigned i(0); i < n; ++i) {
      a[i + 1].L = b[i << 1] = RD();
      a[i + 1].R = b[(i << 1) ^ 1] = RD(); 
      a[i + 1].Val = RD();
    }
    sort(b, b + (n << 1));
    m = unique(b, b + (n << 1)) - b;
    if(m <= 40) {
      for (unsigned i(0); i < m; ++i)
        for (unsigned j(i); j < m; ++j) 
          f[i][j] = 0x3f3f3f3f;
    } else memset(f, 0x3f, sizeof(f));
    for (unsigned i(1); i <= n; ++i) {
      a[i].L = lower_bound(b, b + m, a[i].L) - b;
      a[i].R = lower_bound(b, b + m, a[i].R) - b;
    }
    printf("%u\n", Do(1, n));
  }
  return Wild_Donkey;
}
