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
const unsigned long long Mod(1000000007);
unsigned long long Fac[405], Inv[405], Pow, Poi(Mod - 2);
unsigned long long Cnt(0), Ans(0);
unsigned long long Cases[805];
unsigned long long C[405][405];// Binom
unsigned long long DP[405][405];// in Suf ith element to make pair, chosed j pairs of them to <= x 
unsigned long long f[405];//at least i pairs <= x, i th pair = x
unsigned long long g[405];//x = x - 1, f
unsigned long long h[405];// i pairs  <= x, i th pair = x
unsigned a[405], b[405], Pos[805], m, n;
unsigned MA(0), MB(0), A, B;
unsigned List[15], Tmp[15];
char Ava[15], Flg (0);
inline void DFS (unsigned Dep) {
  if(Dep > n) {
    memcpy(Tmp, List, 44);
    sort(Tmp + 1, Tmp + n + 1);
//    for (unsigned i(1); i <= n; ++i) printf("%u ", Tmp[i]);
//    putchar(0x0A);
    Ans += Tmp[n - m + 1];
  }
  for (unsigned i(1); i <= n; ++i) if(!Ava[i]){
    Ava[i] = 1, List[Dep] = a[Dep] + b[i], DFS(Dep + 1), Ava[i] = 0;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), m = RD(), Inv[n] = Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) MA = max(a[i] = RD(), MA);
  for (unsigned i(1); i <= n; ++i) MB = max(b[i] = RD(), MB);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Pow = Fac[n]; while (Poi) {if(Poi & 1) Inv[n] = Inv[n] * Pow % Mod; Poi >>= 1, Pow = Pow * Pow % Mod;}
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
//  if(n <= 10) {
//    DFS(1);
//    Ans = Ans * Inv[n] % Mod;
//    printf("%llu\n", Ans);
//    return 0;
//  }
  b[n + 1] = 0x3f3f3f3f;
  for (unsigned i(1), j(1); i <= n; ++i)
    while (j < b[i]) Pos[j++] = i - 1;
  for (unsigned i(MA + MB); !(Pos[i]); --i) Pos[i] = n;
//  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
//  putchar(0x0A);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", b[i]);
//  putchar(0x0A);
//  for (unsigned i(1); i <= MA + MB + 1; ++i) printf("%u ", Pos[i]);
//  putchar(0x0A);
//  if(m == 1) {
//    for (unsigned i(MA + MB); i; --i) {
//      Flg = 0, Cnt = 1;
//      if(a[n] >= i) { Cases[i] = 0; continue;}
//      for (unsigned j(n); j; --j) {
//        unsigned Need(i - a[j]), Used(n - j);
//        if(Pos[Need] > Used) Cnt = (Cnt * (Pos[Need] - Used)) % Mod;
//        else {Cnt = 0; break;}
//      }
//      Cases[i] = Cnt;
//    }
//    for (unsigned i(MA + MB); i; --i) Ans = (Ans + ((Mod + Cases[i] - Cases[i - 1]) * i)) % Mod;
//    Ans = Ans * Inv[n] % Mod;
//    printf("%llu\n", Ans);
//    return 0;
//  }
  for (unsigned i(1); i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (unsigned j(1); j < i; ++j){
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= Mod) C[i][j] -= Mod;
    }
  }
  MA += MB;
  m = n - m + 1;
  for (unsigned x(1); x <= MA; ++x) {
    memset(f, 0, sizeof(f));
    memset(DP[0], 0, sizeof(f));
    Cnt = 0;
    DP[0][0] = 1;
    for (unsigned i(1); i <= n; ++i) {
      DP[i][0] = 1;
      for (unsigned j(1); j <= i; ++j) {
//        printf("x - a[n - i + 1] %u\n", x - a[n - i + 1]);
//        if(x >= a[n - i + 1]) printf("Pos %u\n", Pos[x - a[n - i + 1]]);
        if((x <= a[n - i + 1]) || (Pos[x - a[n - i + 1]] < j)) DP[i][j] = DP[i - 1][j];
        else DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1] * (Pos[x - a[n - i + 1]] - j + 1)) % Mod;
//        printf("x = %u f[%u][%u] = %u\n", x, i, j, DP[i][j]);
      }
    }
    for (unsigned i(1); i <= n; ++i) g[i] = DP[n][i] * Fac[n - i] % Mod;
//    for (unsigned i(1); i <= n; ++i) {g[i] = f[i] + Mod - g[i]; if(g[i] >= Mod) g[i] -= Mod;}
//    for (unsigned i(1); i <= n; ++i) printf("x = %u g[%u] = %u\n", x, i, g[i]);
    memcpy(f, h, sizeof(h));
    memset(h, 0, sizeof(h));
    for (unsigned i(1); i <= n; ++i) {
      for (unsigned j(i); j <= n; ++j) {
        if((j + i) & 1) {h[i] = (h[i] + Mod - ((C[j][i] * g[j]) % Mod)); if(h[i] >= Mod) h[i] -= Mod;}
        else h[i] = (h[i] + C[j][i] * g[j]) % Mod;
      }
    }
//    for (unsigned i(1); i <= n; ++i) printf("x = %u h[%u] = %u\n", x, i, h[i]);
    Cnt = 0;
    for (unsigned i(m); i <= n; ++i) {
      Cnt = Cnt + Mod + h[i] - f[i];
      while(Cnt >= Mod) Cnt -= Mod;
    }
//    printf("Cnt of %u is %llu\n", x, Cnt);
    Ans = (Ans + Cnt * x) % Mod;
  }
//  printf("Before %llu\n", Ans);
  Ans = Ans * Inv[n] % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

