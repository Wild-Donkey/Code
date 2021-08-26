#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, s[10005], cnt[10005], a[10005], ans = 0;
bool flg[10005];
char ch;
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n;
    ans = 0;
    s[0] = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(flg, 0, sizeof(flg));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      s[i] = s[i - 1] + a[i];
      cnt[a[i]]++;
      // printf("%d ", s[i]);
    }
    /*printf("\n");
    for (int i = 1; i <= n; i++) {
      printf("%d ", cnt[i]);
    }
    printf("\n");*/
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i - 2; j++) {
        int tmp = s[i] - s[j];
        if (tmp <= n) {
          if (!(flg[tmp])) {
            ans += cnt[tmp];
            // printf("%d %d %d %d %d\n", i, j, s[i], s[j], ans);
          }
          flg[tmp] = true;
        }
      }
    }
    printf("%d\n", ans);
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
