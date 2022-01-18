#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned long long Mod(1000000007);
unsigned long long f[64][4][45][45], Ans[4][45][45], C[10][10], InvC[10][10], m, Bg(1);
unsigned Cnd[50][3], n, P, Q, Lgm(0), Cnt(0xffffffff);
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned long long Calc(unsigned x) { return InvC[n][Cnd[x][0]] * InvC[n - Cnd[x][0]][Cnd[x][1]] % Mod; }
inline void Comb(unsigned long long x[][45][45], unsigned long long y[][45][45], unsigned long long z[][45][45]) {
  unsigned long long Sum[4][45][45];
  memset(Sum, 0, sizeof(Sum));
  for (unsigned RC(Q); ~RC; --RC) for (unsigned Mi(0); Mi <= Cnt; ++Mi) for (unsigned i(0); i <= Cnt; ++i)
    if ((Cnd[i][2] <= Cnd[Mi][0]) && (Cnd[i][2] + Cnd[i][1] <= Cnd[Mi][0] + Cnd[Mi][1])) for (unsigned Lel(0); Lel <= Cnt; ++Lel)
      Sum[RC][Mi][Lel] = (Sum[RC][Mi][Lel] + ((y[RC][i][Lel] * Calc(i) % Mod) * C[Cnd[Mi][0]][Cnd[i][2]] % Mod) * C[Cnd[Mi][0] + Cnd[Mi][1] - Cnd[i][2]][Cnd[i][1]]) % Mod;
  memset(z, 0, sizeof(Ans));
  for (unsigned LC(0); LC <= Q; ++LC) for (unsigned RC(Q - LC); ~RC; --RC) for (unsigned Lel(0); Lel <= Cnt; ++Lel) for (unsigned Rir(0); Rir <= Cnt; ++Rir)
    for (unsigned Mi(0); Mi <= Cnt; ++Mi) z[LC + RC][Lel][Rir] = (z[LC + RC][Lel][Rir] + x[LC][Lel][Mi] * Sum[RC][Mi][Rir]) % Mod;
}
inline void Comb2(unsigned long long x[][45][45], unsigned long long y[][45][45], unsigned long long z[][45][45]) {
  unsigned long long Sum[4][45][45];
  memset(Sum, 0, sizeof(Sum));
  for (unsigned RC(Q); ~RC; --RC) for (unsigned Mi(0); Mi <= Cnt; ++Mi) for (unsigned i(0); i <= Cnt; ++i) if (Cnd[i][1] <= Cnd[Mi][0])
    for (unsigned Lel(0); Lel <= Cnt; ++Lel) Sum[RC][Mi][Lel] = (Sum[RC][Mi][Lel] + (y[RC][i][Lel] * InvC[n][Cnd[i][1]] % Mod) * C[Cnd[Mi][0]][Cnd[i][1]]) % Mod;
  memset(z, 0, sizeof(Ans));
  for (unsigned LC(0); LC <= Q; ++LC) for (unsigned RC(Q - LC); ~RC; --RC) for (unsigned Lel(0); Lel <= Cnt; ++Lel) for (unsigned Mi(0); Mi <= Cnt; ++Mi)
    for (unsigned Rir(0); Rir <= Cnt; ++Rir) z[LC + RC][Lel][Rir] = (z[LC + RC][Lel][Rir] + x[LC][Lel][Mi] * Sum[RC][Mi][Rir]) % Mod;
}
inline unsigned long long Sub2() {
  for (unsigned i(0); i <= n; ++i) Cnd[++Cnt][0] = i, Cnd[Cnt][1] = n - i, f[0][i ? 0 : 1][Cnt][Cnt] = C[n][i];
  for (unsigned i(0); i < Lgm; ++i) Comb2(f[i], f[i], f[i + 1]); memcpy(Ans, f[Lgm], sizeof(Ans)), Bg >>= 1;
  for (unsigned i(Lgm - 1); ~i; --i, Bg >>= 1) if (Bg & m) Comb2(f[i], Ans, Ans); Bg = 0;
  for (unsigned i(0); i <= Q; ++i) for (unsigned j(0); j <= Cnt; ++j) for (unsigned k(0); k <= Cnt; ++k) Bg += Ans[i][j][k];
  return Bg % Mod;
}
signed main() {
  for (unsigned i(0); i < 10; ++i) { C[i][0] = 1; for (unsigned j(1); j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1]; }
  for (unsigned i(0); i < 10; ++i) for (unsigned j(0); j <= i; ++j) InvC[i][j] = Pow(C[i][j], Mod - 2);
  n = RD(), m = RD(), P = RD(), Q = RD();
  while ((Bg <= m) && (Lgm <= 64)) Bg <<= 1, ++Lgm; --Lgm, Bg >>= 1;
  if (Lgm == 64) Bg = (unsigned long long)1 << 63, --Lgm;
  if (P == 0) { printf("0\n");return 0; }
  if (P == 1) { printf("1\n");return 0; }
  if (P == 2) { printf("%llu\n", Sub2());return 0; }
  for (unsigned i(0); i <= n; ++i) { for (unsigned j(n - i); ~j;--j) Cnd[++Cnt][0] = i, Cnd[Cnt][1] = n - j - i, Cnd[Cnt][2] = j; f[0][i ? 0 : 1][Cnt][Cnt] = C[n][i]; }
  if (m == 1) { printf("%llu\n", (1 << n) - (Q ? 0 : 1)); return 0; }
  for (unsigned i(0); i < n; ++i) {
    unsigned CoL, CoR;
    for (unsigned j(0); j <= Cnt; ++j)  if (Cnd[j][2] == i) {
      if (!Cnd[j][0]) CoL = j;
      if (!Cnd[j][1]) CoR = j;
    }
    f[1][1][CoR][CoL] = f[1][1][CoL][CoR] = C[n][i];
  }
  f[1][2][0][0] = 1;
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j < n; ++j) {
    for (unsigned k(min(i, j)); ~k; --k) {
      unsigned CoL, CoR;
      for (unsigned Cdt(0); Cdt <= Cnt; ++Cdt) {
        if ((Cnd[Cdt][2] == k) && (Cnd[Cdt][0] + i == n)) CoL = Cdt;
        if ((Cnd[Cdt][2] == k) && (Cnd[Cdt][0] + j == n)) CoR = Cdt;
      }
      f[1][0][CoL][CoR] = (C[n][k] * C[n - k][i - k] % Mod) * C[n - i][j - k] % Mod;
    }
  }
  for (unsigned i(1); i < Lgm; ++i) Comb(f[i], f[i], f[i + 1]);
  memcpy(Ans, f[Lgm], sizeof(Ans)), Bg >>= 1;
  for (unsigned i(Lgm - 1); i; --i, Bg >>= 1) if (Bg & m) Comb(f[i], Ans, Ans); Bg = 0;
  if (m & 1) for (unsigned Rc(0); Rc <= Cnt; ++Rc) for (unsigned i(n - Cnd[Rc][2]); ~i; --i) for (unsigned Lc(0); Lc <= Cnt; ++Lc)
    for (unsigned Col((i == n) ? 1 : 0); Col <= Q; ++Col) Bg += Ans[Col - ((i == n) ? 1 : 0)][Lc][Rc] * C[n - Cnd[Rc][2]][i];
  else for (unsigned i(0); i <= Q; ++i) for (unsigned j(0); j <= Cnt; ++j) for (unsigned k(0); k <= Cnt; ++k) Bg += Ans[i][j][k];
  printf("%llu\n", Bg % Mod);
  return Wild_Donkey;
}