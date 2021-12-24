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
unsigned long long f[16][33005], Bin[20];
vector <unsigned> Have[33005];
unsigned a[20][33005], m, n, N;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char Li[20][20];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  N = (1 << (n = RD())) - 1, m = RD(), Bin[0] = 1;
  for (unsigned i(1); i <= n; ++i) { Bin[i] = Bin[i - 1] << 1; if (Bin[i] >= Mod) Bin[i] -= Mod; }
  for (unsigned i(1); i <= m; ++i) A = RD(), Li[A][RD()] = 1;
  for (unsigned i(0); i < N; ++i)//Set Contain
    for (unsigned j(0); j < n; ++j)
      if (i & (1 << j)) Have[i].push_back(j);
  for (unsigned i(0); i < n; ++i) {//Point to Set
    for (unsigned j(i + 1); j < n; ++j) if (Li[i][j]) a[i][1 << j] = 1;
    for (unsigned j(0); j < N; ++j) a[i][j] = a[i][j - Lbt(j)] + a[i][Lbt(j)];
  }
  for (unsigned i(0); i < N; ++i) {//Side Case
    f[0][i] = 1;
    for (auto j : Have[i]) f[0][i] = f[0][i] * Bin[a[j][N ^ i]] % Mod;
    for (auto j : Have[N ^ i]) f[0][i] = f[0][i] * (Bin[a[j][i]] - 1) % Mod;
  }
  for (unsigned i(0); i < n; ++i) {
    for (unsigned j(0); j <= N; ++j) {
      for (unsigned k(0); )
    }
  }
  for (unsigned i(0); i <= n - 1; ++i) {
    for (unsigned)
      Ans = (Ans + f[i][N - 3] *) % Mod;
  }
  for (unsigned i(0))
    printf("%u\n", Bin[n] - Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}