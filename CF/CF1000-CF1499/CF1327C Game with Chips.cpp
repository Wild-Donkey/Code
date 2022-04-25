#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, m, k, a, ans = 0;
bool flg;
char s[50005];
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &a, &a);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &a, &a);
  }
  for (int i = 2; i <= n; i++) {  //都到上面
    s[ans] = 'U';
    ans++;
  }
  for (int i = 2; i <= m; i++) {  //到左上角
    s[ans] = 'L';
    ans++;
  }
  bool faq = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      if (faq) {
        s[ans] = 'L';
        ans++;
      } else {
        s[ans] = 'R';
        ans++;
      }
    }
    faq = !faq;
    s[ans] = 'D';
    ans++;
  }
  for (int j = 2; j <= m; j++) {
    if (faq) {
      s[ans] = 'L';
      ans++;
    } else {
      s[ans] = 'R';
      ans++;
    }
  }
  printf("%d\n", ans);
  printf("%s\n", s);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
