#include <array>
#include <vector>
#include <iostream>
#include <cstdio>

typedef long long int ll;

const int maxn = 105;
const int maxm = 1000006;
const int p = 998244353;

int n, m, invm, invm2;
std::array<std::array<std::array<std::array<std::array<long long, 3>, maxn>, maxn>, 2>, maxn> f;
std::array<int, maxn> pos, sz;
std::array<long long, maxn> g;
std::array<std::vector<int>, maxn> e;

void dfs(const int u, const int fa);
void calc(const int u, const int fa);

int mpow(ll x, int y) {
  ll ret = 1;
  while (y) {
    if (y & 1) (ret *= x) %= p;
    y >>= 1;
    (x *= x) %= p;
  }
  return ret;
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.ans", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  invm = mpow(m, 998244351);
  invm2 = mpow(m - 2, 998244351);
  long long ans = m;
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  calc(1, 0);
  ll s1 = 0, s2 = 0;
  for (int i = n / 3 + 2; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= 2; ++k) {
        (s1 += f[1][pos[1]][i][j][k]) %= p;
      }
    }
    for (int j = n / 3 + 2; j <= n; ++j) {
      for (int k = 0; k <= 2; ++k) {
        (s2 += f[1][pos[1]][i][j][k]) %= p;
      }
    }
  }
  ans = g[1];
  ans -= m * s1 % p;
  ans += (m - 1ll) * m / 2 % p * s2 % p;
  (ans += p) %= p;
  std::cout << ans << '\n';
}

void calc(const int u, const int fa) {
  f[u][pos[u]][1][0][0] = f[u][pos[u]][0][1][1] = 1; f[u][pos[u]][0][0][2] = m - 2;
  sz[u] = 1;
  g[u] = m;
  for (auto v : e[u]) if (v != fa) {
    calc(v, u);
    pos[u] ^= 1;
    (g[u] *= (m - 1ll) * invm % p * g[v] % p) %= p;
    for (int i = 0; i <= sz[u] + sz[v]; ++i) {
      for (int j = 0; j <= sz[u] + sz[v]; ++j) {
        f[u][pos[u]][i][j].fill(0);
      }
    }
    for (int i = sz[u]; i >= 0; --i) {
      for (int x = 0; x <= sz[v]; ++x) {
        for (int j = sz[u]; j >= 0; --j) {
          for (int y = 0; y <= sz[v]; ++y) {
            (f[u][pos[u]][i + x][j + y][0] += (f[u][pos[u] ^ 1][i][j][0]) * (f[v][pos[v]][x][y][1] + f[v][pos[v]][x][y][2]) % p) %= p;
            (f[u][pos[u]][i + x][j + y][1] += (f[u][pos[u] ^ 1][i][j][1]) * (f[v][pos[v]][x][y][0] + f[v][pos[v]][x][y][2]) % p) %= p;
            (f[u][pos[u]][i + x][j + y][2] += (f[u][pos[u] ^ 1][i][j][2]) * ((f[v][pos[v]][x][y][0] + f[v][pos[v]][x][y][1]) % p 
                + f[v][pos[v]][x][y][2] * invm2 % p * (m - 3) % p) % p) %= p;
          }
        }
      }
    }
    sz[u] += sz[v];
  }
}
