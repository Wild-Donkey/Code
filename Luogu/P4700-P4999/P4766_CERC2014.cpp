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
inline unsigned Do (const unsigned Fr, const unsigned To, const unsigned U, const unsigned D) {
//  printf("%u %u %u %u %u\n", Fr, To, U, D, f[U][D]);
  if(Fr == To) f[U][D] = a[Fr].Val;
  if(f[U][D] < 0x3f3f3f3f) return f[U][D];
  unsigned Mid(Fr), Mdl, Mdr, Mdv, Ri(To), Le(Fr);
  for (unsigned i(Fr); i <= To; ++i) if(a[Mid].Val < a[i].Val) Mid = i;
  Mdl = a[Mid].L, Mdr = a[Mid].R, Mdv = a[Mid].Val, Mid = 0x3f3f3f3f;
//  printf("Mid = %u [%u, %u]\n", Mdv, Mdl, Mdr);
  for (unsigned j(To); j >= Fr; --j) if(a[j].L > Mdl) swap(a[j], a[Ri--]);
//  printf("[%u, %u) (%u, %u]\n", Fr, Le, Ri, To);
  for (unsigned i(Mdl); i <= Mdr; ++i) {
    unsigned Tmp(0);
    for (unsigned j(Le); j <= To; ++j) if(a[j].R < i) swap(a[j], a[Le++]);
    for (unsigned j(To); j > Ri; --j) if(a[j].L == i) swap(a[j++], a[++Ri]);
//    printf("Div %u\nLe:", i);
//    for (unsigned j(Fr); j < Le; ++j) printf("[%u, %u]", a[j].L, a[j].R);
//    printf("\nRi:");
//    for (unsigned j(To); j > Ri; --j) printf("[%u, %u]", a[j].L, a[j].R);
//    putchar(0x0A); 
    if(Le > Fr) Tmp = Do(Fr, Le - 1, U, i - 1);
    if(Ri < To) Tmp += Do(Ri + 1, To, i + 1, D);
    Mid = min(Mid, Tmp);
  }
  f[U][D] = Mid + Mdv;
//  printf("Done %u\n", f[U][D]);
  return f[U][D];
}
signed main() {
//  freopen("P4766_1.in", "r", stdin);
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
    for (unsigned i(0); i < m; ++i)
      for (unsigned j(i); j < m; ++j) 
        f[i][j] = 0x3f3f3f3f;
    for (unsigned i(1); i <= n; ++i) {
      a[i].L = lower_bound(b, b + m, a[i].L) - b;
      a[i].R = lower_bound(b, b + m, a[i].R) - b;
//      printf("[%u, %u]\n", a[i].L, a[i].R);
    }
//    printf("%u %u %u\n", T, n, Do(1, n, 0, m - 1));
    printf("%u\n", Do(1, n, 0, m - 1));
  }
  return Wild_Donkey;
}
/*
1
18
3 28 98
16 68 25
12 40 2
3 72 33
1 74 12
18 73 6
9 96 53
35 47 61
91 96 28
68 94 37
12 98 48
16 82 42
9 91 84
3 15 47
15 74 59
1 82 68
3 44 41
15 18 34
*/
