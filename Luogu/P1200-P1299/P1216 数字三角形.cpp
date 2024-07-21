#include <cstring>
#include <iostream>
using namespace std;
int n, k, f[1005][1005], a[1005][1005], ans = -0x3fffffff;
int main() {
  memset(f, 0xaf, sizeof(f));
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) cin >> a[i][j];
  f[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
  for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
  cout << ans << endl;
  return 0;
}
