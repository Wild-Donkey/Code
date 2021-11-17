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
unsigned Tri[20];
unsigned BinTri[17005];
pair<unsigned, unsigned> End[600005];
unsigned Beg[300005];
unsigned n, m, Bn, Tr;
unsigned A, B, C, D, t;
char a[17005], f[4800005], g[4800005];
char Get(unsigned x, char y) {
  return (x / Tri[y - 1]) % 3;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  Bn = (1 << (n = RD())), Tri[0] = 1;
  for (unsigned i(1); i <= n; ++i) Tri[i] = Tri[i - 1] * 3;
  scanf("%s", a);
  for (unsigned i(0); i < Bn; ++i) f[BinTri[i] = BinTri[i >> 1] * 3 + (i & 1)] = ((a[i] ^ '0') ? 2 : 1);
  Tr = Tri[n];
  for (unsigned i(0); i < Tr; ++i) for (unsigned j(0); j < n; ++j) 
    if(!((i / Tri[j]) % 3)) f[i + (Tri[j] << 1)] = (f[i] | f[i + Tri[j]]);
//  for (unsigned i(0); i < Tr; ++i) putchar(f[i] + '0'); putchar(0x0A);
  for (unsigned i(Tr - 1); ~i; --i) for (unsigned j(0); j < n; ++j) {
    if((((i / Tri[j]) % 3) & 1) && (f[i + Tri[j]] ^ 3))
      g[i] = max(g[i], (char)(g[i + Tri[j]] + 1));
    if((!((i / Tri[j]) % 3)) && (f[i + (Tri[j] << 1)] ^ 3))
      g[i] = max(g[i], (char)(g[i + (Tri[j] << 1)] + 1));
  }
  for (unsigned i(0); i < Bn; ++i) printf("%u ", n - g[BinTri[i]]); putchar(0x0A);
//  printf("Bn %u Tr %u\n", Bn, Tr);
  return Wild_Donkey;
}
/*

*/
