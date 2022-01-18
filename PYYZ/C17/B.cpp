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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
const unsigned long long Mod(1000000007);
unsigned long long Bin[105], C[10][10], InvC[10][10], Fac[105], Inv[105], m, Bg(1);
unsigned long long f[65][4][50][50], Ans[4][50][50], Tmp[4][50][50];
unsigned Cnd[50][3], Twd[50];
unsigned n, P, Q, Lgm(0);
unsigned A, B, D, t;
unsigned Cnt(0);
inline void MnM(unsigned long long& x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned long long Calc(unsigned x) { return InvC[n][Cnd[x][0]] * InvC[n - Cnd[x][0]][Cnd[x][1]] % Mod; }
inline void Comb(unsigned long long x[][50][50], unsigned long long y[][50][50], unsigned long long z[][50][50]) {
  unsigned long long Sum[4][50][50];
  memset(z, 0, sizeof(Ans)), memset(Sum, 0, sizeof(Sum));
  for (unsigned RC(Q); ~RC; --RC) for (unsigned Mi(1); Mi <= Cnt; ++Mi) for (unsigned i(1); i <= Cnt; ++i) {
    if ((Cnd[i][2] <= Cnd[Mi][0]) && (Cnd[i][2] + Cnd[i][1] <= Cnd[Mi][0] + Cnd[Mi][1]))
      for (unsigned Lel(1); Lel <= Cnt; ++Lel)
        Sum[RC][Mi][Lel] = (Sum[RC][Mi][Lel] + ((y[RC][i][Lel] * Calc(i) % Mod) * C[Cnd[Mi][0]][Cnd[i][2]] % Mod) * C[Cnd[Mi][0] + Cnd[Mi][1] - Cnd[i][2]][Cnd[i][1]]) % Mod;
  }
  for (unsigned LC(0); LC <= Q; ++LC) {
    for (unsigned RC(Q - LC); ~RC; --RC) {
      for (unsigned Lel(1); Lel <= Cnt; ++Lel) {
        for (unsigned Rir(1); Rir <= Cnt; ++Rir) {
          for (unsigned Mi(1); Mi <= Cnt; ++Mi) {
            z[LC + RC][Lel][Rir] = (z[LC + RC][Lel][Rir] + x[LC][Lel][Mi] * Sum[RC][Mi][Rir]) % Mod;
          }
        }
      }
    }
  }
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       printf("f %u %u %u = %llu\n", LC, i, Lel, z[LC][i][Lel]);
}
inline void Comb2(unsigned long long x[][50][50], unsigned long long y[][50][50], unsigned long long z[][50][50]) {
  unsigned long long Sum[4][50][50];
  memset(z, 0, sizeof(Ans)), memset(Sum, 0, sizeof(Sum));
  for (unsigned RC(Q); ~RC; --RC) {
    for (unsigned Mi(1); Mi <= Cnt; ++Mi) {
      for (unsigned i(1); i <= Cnt; ++i) {
        if (Cnd[i][1] <= Cnd[Mi][0]) for (unsigned Lel(1); Lel <= Cnt; ++Lel)
          Sum[RC][Mi][Lel] = (Sum[RC][Mi][Lel] + (y[RC][i][Lel] * InvC[n][Cnd[i][1]] % Mod) * C[Cnd[Mi][0]][Cnd[i][1]]) % Mod;
      }
    }
  }
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       printf("Sum %u %u %u = %llu\n", LC, i, Lel, Sum[LC][i][Lel]);
  for (unsigned LC(0); LC <= Q; ++LC) {
    for (unsigned RC(Q - LC); ~RC; --RC) {
      for (unsigned Lel(1); Lel <= Cnt; ++Lel) {
        for (unsigned Mi(1); Mi <= Cnt; ++Mi) {
          for (unsigned Rir(1); Rir <= Cnt; ++Rir) {
            // printf("z %u %u %u += x %u %u %u * Sum %u %u %u (%llu)\n", LC + RC, Lel, Rir, LC, Lel, Mi, RC, Mi, Rir, x[LC][Lel][Mi] * Sum[RC][Mi][Rir]);
            z[LC + RC][Lel][Rir] = (z[LC + RC][Lel][Rir] + x[LC][Lel][Mi] * Sum[RC][Mi][Rir]) % Mod;
          }
        }
      }
    }
  }
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       printf("f 1 %u %u %u = %llu\n", LC, i, Lel, z[LC][i][Lel]);
}
inline void Sub2() {
  for (unsigned i(0); i <= n; ++i) {
    Cnd[++Cnt][0] = i, Cnd[Cnt][1] = n - i, Twd[Cnt] = n - i + 1;
    f[0][i ? 0 : 1][Cnt][Cnt] = C[n][i];
  }
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       printf("Src %u %u %u = %llu\n", LC, i, Lel, f[0][LC][i][Lel]);
  // printf("Lgm %u %llu\n", Lgm, Bg);
  for (unsigned i(0); i < Lgm; ++i) Comb2(f[i], f[i], f[i + 1]);
  memcpy(Ans, f[Lgm], sizeof(Ans)), Bg >>= 1;
  for (unsigned i(Lgm - 1); ~i; --i, Bg >>= 1) if (Bg & m) memcpy(Tmp, Ans, sizeof(Tmp)), Comb2(f[i], Tmp, Ans);
  Bg = 0;
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       printf("f %u %u %u = %llu\n", LC, i, Lel, Ans[LC][i][Lel]);
  for (unsigned i(0); i <= Q; ++i) {
    for (unsigned j(1); j <= Cnt; ++j) {
      for (unsigned k(1); k <= Cnt; ++k) {
        Bg += Ans[i][j][k];
      }
    }
  }
  printf("%llu\n", Bg % Mod);
  // system("pause");
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), P = RD(), Q = RD(), Bin[0] = Fac[0] = 1;
  for (unsigned i(1); i <= 100; ++i) Bin[i] = Bin[i - 1] << 1, Bin[i] -= (Bin[i] >= Mod) ? Mod : 0;
  for (unsigned i(0); i < 10; ++i) {
    C[i][0] = 1;
    for (unsigned j(1); j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  for (unsigned i(0); i < 10; ++i) for (unsigned j(0); j <= i; ++j) InvC[i][j] = Pow(C[i][j], Mod - 2);
  for (unsigned i(1); i < 100; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  for (unsigned i(99); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  while ((Bg <= m) && (Lgm <= 64)) Bg <<= 1, ++Lgm/*, printf("F %u %llu\n", Lgm, Bg)*/; --Lgm, Bg >>= 1;
  // printf("%llu Lgm %u\n", Bg, Lgm);
  if (Lgm == 64) Bg = (unsigned long long)1 << 63, --Lgm;
  if (P == 0) { printf("0\n");return 0; }
  if (P == 1) { printf("1\n");return 0; }
  if (P == 2) { Sub2();return 0; }
  for (unsigned i(0); i <= n; ++i) {
    unsigned Co(Cnt + 1);
    for (unsigned j(n - i); ~j;--j) {
      Cnd[++Cnt][0] = i, Cnd[Cnt][1] = n - j - i, Cnd[Cnt][2] = j;
      // printf("%u: %u %u %u\n", Cnt, i, n - j - i, j);
    }
    f[0][i ? 0 : 1][Cnt][Cnt] = C[n][i];
  }
  if (m == 1) { printf("%llu\n", Bin[n] - (Q ? 0 : 1)); return 0; }
  for (unsigned i(1); i <= Cnt; ++i) for (unsigned j(1); j <= Cnt; ++j)
    if ((Cnd[i][0] == Cnd[j][2]) && (Cnd[i][1] == Cnd[j][1])) { Twd[i] = j; break; }
  for (unsigned i(0); i < n; ++i) {
    unsigned CoL, CoR;
    for (unsigned j(1); j <= Cnt; ++j) {
      if (Cnd[j][2] == i) {
        if (!Cnd[j][0]) CoL = j;
        if (!Cnd[j][1]) CoR = j;
      }
    }
    f[1][1][CoR][CoL] = f[1][1][CoL][CoR] = C[n][i];
  }
  f[1][2][1][1] = 1;
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j < n; ++j) {
    for (unsigned k(min(i, j)); ~k; --k) {
      unsigned CoL, CoR;
      for (unsigned Cdt(1); Cdt <= Cnt; ++Cdt) {
        if ((Cnd[Cdt][2] == k) && (Cnd[Cdt][0] + i == n)) CoL = Cdt;
        if ((Cnd[Cdt][2] == k) && (Cnd[Cdt][0] + j == n)) CoR = Cdt;
      }
      f[1][0][CoL][CoR] = (C[n][k] * C[n - k][i - k] % Mod) * C[n - i][j - k] % Mod;
    }
  }
  // printf("Lgm %u Bg %llu\n", Lgm, Bg);
  for (unsigned i(1); i < Lgm; ++i) Comb(f[i], f[i], f[i + 1]);
  memcpy(Ans, f[Lgm], sizeof(Ans)), Bg >>= 1;
  for (unsigned i(Lgm - 1); i; --i, Bg >>= 1) if (Bg & m) memcpy(Tmp, Ans, sizeof(Tmp)), Comb(f[i], Tmp, Ans);
  // for (unsigned LC(0); LC <= Q; ++LC)
  //   for (unsigned i(1); i <= Cnt; ++i)
  //     for (unsigned Lel(1); Lel <= Cnt; ++Lel)
  //       // printf("f %u %u %u = %llu\n", LC, i, Lel, Ans[LC][i][Lel]);
  Bg = 0;
  if (m & 1) {
    for (unsigned Rc(1); Rc <= Cnt; ++Rc) {
      for (unsigned i(n - Cnd[Rc][2]); ~i; --i) {
        for (unsigned Lc(1); Lc <= Cnt; ++Lc) {
          for (unsigned Col((i == n) ? 1 : 0); Col <= Q; ++Col) {
            Bg = (Bg + Ans[Col - ((i == n) ? 1 : 0)][Lc][Rc] * C[n - Cnd[Rc][2]][i]) % Mod;
          }
        }
      }
    }
  }
  else {
    for (unsigned i(0); i <= Q; ++i) {
      for (unsigned j(1); j <= Cnt; ++j) {
        for (unsigned k(1); k <= Cnt; ++k) {
          Bg += Ans[i][j][k];
        }
      }
      Bg %= Mod;
    }
  }
  // system("pause");
  printf("%llu\n", Bg);
  // for (unsigned)
    //  }
  system("pause");
  return Wild_Donkey;
}
/*
2 3 3 1
46
2 3 2 1
2 10 2 2
2 8 2 2
2 4 2 2
1 954431 3 1
954432
1 954430 3 1
954431
*/