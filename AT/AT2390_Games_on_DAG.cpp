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
#define Lbt(x) ((x)&((~(x))+1))
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
unsigned long long Ans(0), f[16][33005], Bin[200];
vector <unsigned> Have[33005];
unsigned a[20][33005], m, n, N;
unsigned A, B, C, D, t;
char Li[20][20];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  N = (1 << (n = RD())) - 1, m = RD(), Bin[0] = 1;
  for (unsigned i(1); i <= m; ++i) { Bin[i] = Bin[i - 1] << 1; if (Bin[i] >= Mod) Bin[i] -= Mod; }
  for (unsigned i(1); i <= m; ++i) A = RD() - 1, Li[A][RD() - 1] = 1;//A to Li[A]
  for (unsigned i(0); i <= N; ++i)//Set Contain
    for (unsigned j(0); j < n; ++j)
      if (i & (1 << j)) Have[i].push_back(j);
  for (unsigned i(0); i < n; ++i) {//Point to Set
    for (unsigned j(i + 1); j < n; ++j) if (Li[i][j]) a[i][1 << j] = 1;
    for (unsigned j(0); j <= N; ++j) a[i][j] = a[i][j - Lbt(j)] + a[i][Lbt(j)];
  }
  // printf("f 0:\n");
  for (unsigned i(0); i <= N; ++i) {//Side Case
    f[0][i] = 1;
    for (auto j : Have[i]) f[0][i] = f[0][i] * Bin[a[j][N ^ i]] % Mod;
    for (auto j : Have[N ^ i]) f[0][i] = f[0][i] * (Bin[a[j][i]] - 1) % Mod;
    // printf("%4u", f[0][i]);
  }
  // putchar(0x0A);
  for (unsigned i(1); i < n; ++i) {
    // printf("f %u:\n", i);
    for (unsigned j(0); j <= N; ++j) {
      for (unsigned k(j); k; k = ((k - 1) & j)) {
        if ((!(k & 3)) || ((k & 3) == 3)) {
          unsigned long long Tmp(1);
          for (auto Poi : Have[N ^ j]) Tmp = Tmp * (Bin[a[Poi][k]] - 1) % Mod;
          for (auto Poi : Have[k]) Tmp = Tmp * Bin[a[Poi][N ^ j]] % Mod;
          f[i][j] = (f[i][j] + f[i - 1][j ^ k] * Tmp) % Mod;
        }
      }
      // printf("%4u", f[i][j]);
    }
    // putchar(0x0A);
  }
  Ans = Bin[m];
  for (unsigned i(0); i < n; ++i) {
    Ans = Mod + Ans - f[i][N];
    if (Ans >= Mod) Ans -= Mod;
  }
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
654287
*/