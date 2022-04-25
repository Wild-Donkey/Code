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
const unsigned long long Mod(1000000009);
inline void Mn(unsigned long long& x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
bitset<100005> Flp;
unsigned a[100005][2], Pos[100005], f[100005], g[100005][5];
unsigned long long mm, M1, M2, M3, M4, Sum;
unsigned m, n;
unsigned Cnt(0), Ans(0);
inline unsigned ColorTwo(unsigned x) {return a[x][Flp[x] ^ 1];}
inline unsigned ColorOne(unsigned x) {return a[x][Flp[x]];}
inline unsigned long long Onesided(unsigned x) {
  if(!x) return 1; --x;
  return ((g[x][0] * M2 % Mod) * M3 + g[x][1] + g[x][2] + ((g[x][3] + g[x][4]) * M2 << 1)) % Mod;
}
inline void Mul(unsigned long long x) {
  Sum = Sum * x % Mod;
  for (unsigned i(1); i <= m; ++i) f[i] = f[i] * x % Mod;
}
inline void Add(unsigned x) {
  Sum = (Sum + (unsigned long long)m * x) % Mod;
  for (unsigned i(1); i <= m; ++i) Mn(f[i] += x);
}
inline void Def(unsigned x) {
  Sum = (m * x) % Mod;
  for (unsigned i(1); i <= m; ++i) f[i] = x;
}
inline void Set(unsigned x, unsigned y) {
  Mn(Sum += y + Mod - f[x]), Mn(Sum), f[x] = y;
}
inline unsigned long long Find(unsigned x) {
  return f[x];
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), mm = (m = RD()) - 1, mm = mm * m % Mod;
  M1 = m - 1, M2 = m - 2, M3 = m - 3, M4 = m - 4; 
  for (unsigned i(1); i <= n; ++i) a[i][0] = RD();
  for (unsigned i(1); i <= n; ++i) a[i][1] = RD();
  g[0][0] = g[0][2] = g[0][4] = 1, g[0][1] = g[0][3] = 0;
  for (unsigned i(1); i <= n; ++i) {
    g[i][0] = (g[i - 1][0] * ((M3 * M4 + 1) % Mod) + g[i - 1][1] + g[i - 1][2] + ((g[i - 1][3] + g[i - 1][4]) * M3 << 1) % Mod) % Mod;
    g[i][1] = ((g[i - 1][0] * M2 % Mod) * M3 + g[i - 1][2] + (g[i - 1][4] * M2 << 1)) % Mod;
    g[i][2] = ((g[i - 1][0] * M2 % Mod) * M3 + g[i - 1][1] + (g[i - 1][3] * M2 << 1)) % Mod;
    g[i][3] = ((g[i - 1][0] * M3 % Mod) * M3 + g[i - 1][2] + g[i - 1][3] * M2 + g[i - 1][4] * (M3 + M2)) % Mod;
    g[i][4] = ((g[i - 1][0] * M3 % Mod) * M3 + g[i - 1][1] + g[i - 1][4] * M2 + g[i - 1][3] * (M3 + M2)) % Mod;
  }
//  for (unsigned i(0); i <= n; ++i) printf("%u: %u %u %u %u %u\n", i, g[i][0], g[i][1], g[i][2], g[i][3], g[i][4]);
  for (unsigned i(1); i <= n; ++i) if(a[i][0] | a[i][1]) {Pos[++Cnt] = i; if(a[i][1]) Flp[Cnt] = 1;}
  for (unsigned i(1); i <= Cnt; ++i) a[i][0] = a[Pos[i]][0], a[i][1] = a[Pos[i]][1];
  if(!Cnt) {
    printf("%llu\n", (Onesided(n - 1) * m % Mod) * M1 % Mod);
    return 0;
  }
  unsigned CT(ColorTwo(1)), Val(Onesided(Pos[1] - 1));
  if(CT) Sum = f[CT] = Val;
  else {for (unsigned i(1); i <= m; ++i) f[i] = Val; f[ColorOne(1)] = 0, Sum = Val * M1 % Mod;}
  for (unsigned i(2); i <= Cnt; ++i) {
    if(0) {
      CT = ColorTwo(Cnt), Ans = 0;
      for (unsigned i(1); i <= m; ++i) if(CT ^ i) Mn(Ans += f[i]);
      printf("%llu\n", Ans);
    }
    unsigned A(a[i - 1][0]), B(a[i - 1][1]), C(a[i][0]), D(a[i][1]), *Len(g[Pos[i] - Pos[i - 1] - 1]);
    if(Flp[i]) swap(A, B), swap(C, D), Flp[i - 1] = (Flp[i - 1] ^ 1);
    if(Flp[i - 1]) {
      if(B == C) {
        unsigned long long PTmp(Sum * Len[4] % Mod);
        Mul(Mod + Len[2] - Len[4]), Add(PTmp), Set(ColorOne(i), 0);
      } else {
        unsigned long long FC(Find(C)), PTmp(((Mod + Sum - FC) * Len[0] + FC * Len[3]) % Mod);
        unsigned long long AB((FC * Len[1] + (Mod + Sum - FC) * Len[3]) % Mod);
        Mul(Mod + Len[4] - Len[0]), Add(PTmp), Set(C, 0), Set(B, AB);
      }
    } else {
      if(A == C) {
        unsigned long long PTmp(Sum * Len[3] % Mod);
        Mul(Mod + Len[1] - Len[3]), Add(PTmp), Set(ColorOne(i), 0);
      } else {
        unsigned long long FC(Find(C)), PTmp(((Mod + Sum - FC) * Len[0] + FC * Len[4]) % Mod);
        unsigned long long AB((FC * Len[2] + (Mod + Sum - FC) * Len[4]) % Mod);
        Mul(Mod + Len[3] - Len[0]), Add(PTmp), Set(C, 0), Set(A, AB);
      }
    }
    if(D) {
      unsigned TmpF(Find(D));
      Def(0), Set(D, TmpF);
    }
  }
  CT = ColorOne(Cnt), Ans = 0;
  for (unsigned i(1); i <= m; ++i) if(CT ^ i) Mn(Ans += f[i]);
  printf("%llu\n", Ans * Onesided(n - Pos[Cnt]) % Mod);
//  }
  return Wild_Donkey;
}
