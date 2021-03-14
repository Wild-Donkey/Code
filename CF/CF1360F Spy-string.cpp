#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, m, ans = 0, cnt = 0, a, b;
bool flg[105];
char ch;
string s[105];
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n >> m;
    memset(flg, 0, sizeof(flg));
    ans = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    s[0][a] = s[1][0];
    for (int i = 0; i < m; i++) {
      for (int j = 2; j <= n; j++) {
        if (s[j][i] != s[j][i - 1]) {
          flg[j] = 1;
          cnt++;
          break;
        }
      }
    }
    if (cnt >= 3) {
      printf("0\n");
      continue;
    }
    if (cnt < 2) {
      cout << s[1] << endl;
      continue;
    }
    for (int i = 0; i < m; i++) {
      if (flg[i]) {
        a = i;
      }
    }
    for (int i = a + 1; i < n; i++) {
      if (flg[i]) {
        b = i;
      }
    }
    s[0] = s[1];
    for (int i = 2; i <= n; i++) {
      if (s[i][a] == s[i - 1][a]) {
        if (s[i][b] != s[i - 1][b]) {
          s[0][a] = s[i][a];
        }
      }
      if (s[i][a] != s[i - 1][a]) {
        if (s[i][b] != s[i - 1][b]) {
          printf("-1\n");
          flg[0] = true;
          break;
        }
        s[0][b] = s[i][b];
      }
    }
    if (!flg[0]) {
      cout << s[0] << endl;
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
