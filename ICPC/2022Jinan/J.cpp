#pragma GCC optimize(3)
#pragma GCC optimize("-funroll-loops")
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e3 + 4;
int f[maxn][maxn][3], g[maxn][maxn][3], a[maxn][3];
void maximize(int& a, int b) { a < b ? a = b : a; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T-- > 0) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < 3; ++j) cin >> a[i][j];
    f[0][0][0] = a[1][0];
    f[0][0][1] = a[1][1];
    f[0][0][2] = a[1][2];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i; ++k) {
          for (int p = 0; p < 3; ++p) {
            const int x[] = {
                (p == 0 ? i : (p == 1 ? k : j)),
                (p == 0 ? j : (p == 1 ? i : k)),
                (p == 0 ? k : (p == 1 ? j : i)),
            };
            for (int q = 0; q < 3; ++q) {
              if (p == q) {
                maximize(g[j][k][q], f[j][k][p] - (j ? i - j + 1 : 0) -
                                         (k ? i - k + 1 : 0) + a[i + 1][q]);
              } else {
                int t = f[j][k][p];
                for (int s = 0; s < 3; ++s) {
                  t += (s == q ? a[i + 1][q] : -(x[s] ? i - x[s] + 1 : 0));
                }
                // if (i == 1 && j == 0 && k == 0 && p == 2 && q == 1)
                //   cerr << x[2] << endl;
                maximize(
                    g[q == (p + 1) % 3 ? k : i][q == (p + 1) % 3 ? i : j][q],
                    t);
              }
            }
          }
        }
      }
      for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= i; ++k) {
          for (int s = 0; s < 3; ++s) {
            f[j][k][s] = g[j][k][s];
            // cerr << f[j][k][s] << ' ';
            g[j][k][s] = 0;
          }
          // cerr << endl;
        }
        // cerr << endl;
      }
      // cerr << endl;
    }
    int ans = 0;
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k)
        for (int s = 0; s < 3; ++s) maximize(ans, f[j][k][s]);
    cout << ans << endl;
  }
  return 0;
}