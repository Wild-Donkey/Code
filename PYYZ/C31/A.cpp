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
const unsigned long long Mod(998244353);
unordered_map <unsigned long long, pair<unsigned, unsigned>> M;
unsigned long long R[55][105];
unsigned f[55][55], g[55][55], m, n(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char a[105], s[105];
//  inline void Clr() {}
inline pair<unsigned, unsigned> Calc(unsigned long long x) {
  if (M.find(x) != M.end()) return M[x];
  unsigned Len(0);
  for (unsigned long long i(x); i; i >>= 1, ++Len);
  // printf("Calc %llu %u\n", x, Len);
  --Len;
  unsigned long long Fst(0), Scd(0);
  for (unsigned len(Len >> 1); len; --len) if (!(Len % len)) {
    unsigned long long Cs(((unsigned long long)1 << len) - 1);
    for (unsigned i(Len - len); i < 0x3f3f3f3f; i -= len) Cs &= (x >> i);
    Cs |= ((unsigned long long)1 << len);
    Scd += Calc(Cs).first;
  }
  M[x].second = (Scd %= Mod);
  // printf("Calc g %llu = %u\n", x, Scd);
  unsigned long long XSon(x);
  for (unsigned len(1); len < Len; ++len) {
    unsigned long long Cs(((unsigned long long)1 << len) - 1);
    Cs &= x, XSon >>= 1, Cs |= ((unsigned long long)1 << len);
    // printf("%llu f %llu * g %llu\n", x, XSon, Cs);
    Fst = (Fst + (unsigned long long)Calc(XSon).first * Calc(Cs).second) % Mod;
  }
  M[x].first = (Fst + Scd) % Mod;
  return M[x];
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 102, stdin);
  while (a[n + 1] >= '0') ++n;
  m = min(n, (unsigned)50);
  // printf("Input %u\n", n);
  for (unsigned i(1); i <= n; ++i) R[0][i] = 1, a[i] -= '0';
  // for (unsigned i(1); i <= n; ++i) putchar(a[i] + '0');putchar(0x0A);
  for (unsigned Len(1); Len <= m; ++Len) for (unsigned l(n - Len + 1); l; --l)
    R[Len][l] = ((R[Len - 1][l] << 1) | a[l + Len - 1]);// printf("[%u, %u] %llu\n", l, Len + l - 1, R[Len][l]);
  M[2] = { 1,1 }, M[3] = { 2,2 }, M[1] = { 1,1 };
  if (n <= 50) {
    unsigned long long St(1);
    for (unsigned i(1); i <= n; ++i) St = ((St << 1) | a[i]);
    Calc(St), printf("%u\n", M[St].first);
    // for (auto i : M) printf("M %llu = %u, %u\n", i.first, i.second.first, i.second.second);
    return 0;
  }
  for (unsigned Len(51); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      unsigned long long Tmp(0);
      for (unsigned len(Len >> 1); len; --len) if (!(Len % len)) {
        // printf("Faq %u\n", len);
        unsigned long long Cs(((unsigned long long)1 << (len + 1)) - 1);
        // printf("CS %llu\n", Cs);
        for (unsigned j(0); j < Len; j += len) Cs &= R[len][i + j];// printf("CS %llu\n", Cs);
        Tmp += Calc(Cs).first;
      }
      f[Len - 50][i] = g[Len - 50][i] = (Tmp %= Mod);
      for (unsigned len(1); len < Len; ++len) {
        unsigned long long Tmpa, Tmpb;
        if (len <= 50) Tmpa = Calc(R[len][i]).first;
        else Tmpa = f[len - 50][i];
        if (Len - len <= 50) Tmpb = Calc(R[Len - len][i + len]).second;
        else Tmpb = g[Len - len - 50][i + len];
        f[Len - 50][i] = (f[Len - 50][i] + Tmpa * Tmpb) % Mod;
      }
    }
  }
  printf("%u\n", f[n - 50][1]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
340807072
340807072
2 6 18 60 186
*/