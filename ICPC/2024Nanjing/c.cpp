#include <bits/stdc++.h>
using namespace std;
unsigned Size[5005], f[5005][5005];
unsigned long long g[5005], G[5005], S[5005];
unsigned long long Fac[5005], Inv[5005];
const unsigned long long Mod(998244353);
unsigned n;
vector<unsigned> Sons[5005];
unsigned long long C(unsigned x, unsigned y) {
  return (Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
}
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned DFS(unsigned x) {
  Size[x] = 1, G[x] = 1, S[x] = 1;
  for (auto i : Sons[x]) {
    Size[x] += DFS(i), G[x] = G[x] * g[i] % Mod,
                       S[x] = S[x] * Inv[Size[i]] % Mod;
  }
  g[x] = Fac[Size[x] - 1] * G[x] % Mod;
  for (auto i : Sons[x]) g[x] = g[x] * Inv[Size[i]] % Mod;
  return Size[x];
}
void DP(unsigned x, unsigned Fa) {
  unsigned long long TmpS = 0, TmpP = G[Fa] * S[Fa] % Mod;
  TmpP = TmpP * Fac[Size[x]] % Mod;
  TmpP = TmpP * Pow(g[x], Mod - 2) % Mod;
  // printf("%u TmpP %llu\n", x, TmpP);
  for (unsigned j(1), k(1); j + Size[x] - 1 <= n; ++j) {
    while (k <= min(j - 1, n + 1 - Size[Fa])) {
      TmpS = (TmpS + (Fac[n - k - Size[x]] * Inv[n - k + 1 - Size[Fa]] % Mod) *
                         f[Fa][k]) %
             Mod;
      ++k;
    }
    f[x][j] = TmpP * TmpS % Mod;
  }
  for (auto i : Sons[x]) DP(i, x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned A, B;
  cin >> n;
  Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[n] = Pow(Fac[n], Mod - 2);
  for (unsigned i(n); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  for (unsigned i(2); i <= n; ++i) {
    cin >> A;
    Sons[A].push_back(i);
  }
  // return 0;
  DFS(1);
  f[1][1] = 1;
  for (auto i : Sons[1]) DP(i, 1);
  // printf("Done\n");
  // for (unsigned i(1); i <= n; ++i) {
  // printf("%llu:", g[i]);
  //   for (unsigned j(1); j <= n; ++j) printf("%llu ", f[i][j]);
  //   putchar(0x0A);
  // }
  for (unsigned i(1); i <= n; ++i) {
    printf("%llu ", (f[i][i] * g[i] % Mod) * C(n - i, Size[i] - 1) % Mod);
  }
  putchar(0x0A);
  return 0;
}
/*
g++ c.cpp -lstdc++
4
1 1 2
*/