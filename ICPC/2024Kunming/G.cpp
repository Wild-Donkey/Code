#include<bits/stdc++.h>
using namespace std;
unsigned f[5005][5005];
unsigned Gcd[5005][5005];
unsigned long long g[5005][5005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned t = 1;
  cin >> t;
  for (unsigned i(0); i <= 5000; ++i) {
    Gcd[i][i] = i;
    for (unsigned j(0); j < i; ++j)
      Gcd[i][j] = __gcd(i, j);
  }
  for (unsigned i(0); i <= 5000; ++i)
    for (unsigned j(i + 1); j <= 5000; ++j)
      Gcd[i][j] = Gcd[j][i];
  while (t--) {
    unsigned a, b, gCd, Ans = 0x3f3f3f3f;
    unsigned long long bTmp, p;
    cin >> a >> bTmp;
    b = bTmp % a;
    p = bTmp / a;
    gCd = Gcd[a][b];
    a /= gCd;
    b /= gCd;
    for (unsigned i = 0; i <= a; ++i) {
      memset(f[i], 0x3f, (a + 1) * sizeof(unsigned));
      memset(g[i], 0, (a + 1) * sizeof(unsigned long long));
    }
    f[a][b] = 0, g[a][b] = p;
    for (unsigned i = a; i; --i) {
      for (unsigned j = a; j; --j) {
        unsigned I, J;
        // printf("f[%u][%u] = %uz`\n", i, j, f[i][j]);
        if (i > 1) {
          I = i - 1, J = (j + g[i][j]) % (i - 1);
          if (f[i][j] + 1 < f[I][J]) {
            f[I][J] = f[i][j] + 1;
            g[I][J] = (j + g[i][j]) / (i - 1);
          }
        }
        if (f[i][j] + 1 < f[i][j - 1]) {
          f[i][j - 1] = f[i][j] + 1;
          g[i][j - 1] = g[i][j];
        }
        gCd = Gcd[i][j], I = i / gCd, J = j / gCd;
        if (f[i][j] < f[I][J]) {
          f[I][J] = f[i][j];
          g[I][J] = g[i][j];
        }
      }
      f[1][0] = min(f[1][0], f[i][0]);
    }
    // for (unsigned i = 0; i <= a; ++i) {
    //   for (unsigned j = 0; j <= a; ++j)
    //     cerr << f[i][j] << ' ';
    //   cerr << '\n';
    // }
    cout << min(f[0][1] + 1, f[1][0] + 2) << '\n';
  }
  return 0;
}
/*
2
3 4
12 20

114 514
*/