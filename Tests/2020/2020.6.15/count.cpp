#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int w, n, a[10005], ans = 0;
bool flg;
char s, t;
string st;
bool Max(string x) {
  if (x[w - 1] == t) {
    int I = 1;
    while (I < w) {
      if (x[I] != x[I - 1] + 1) {
        return 0;
      }
      I++;
    }
  } else {
    return 0;
  }
  return 1;
}
int main() {
  //   freopen("count.in", "r", stdin);
  //    freopen("count.out", "w", stdout);
  scanf("%d", &w);
  s = w + 'a' - 1;
  scanf("%d", &w);
  t = w + 'a' - 1;
  scanf("%d", &w);
  cin >> st;
  for (int i = 1; i <= 5; i++) {
    if (Max(st)) {
      return 0;
    } else {
      for (int j = w - 1; j >= 0; j--) {
        if (st[j] == t) {  //这一位到头了
          continue;
        }
        if (j == w - 1) {  //最后一位自己增
          st[j]++;
          break;
        }
        if (st[j] < st[j + 1] - 1) {  //这一位自增满足规则
          st[j]++;
          for (int k = j + 1; k < w; k++) {  //后面保证最小
            st[k] = st[k - 1] + 1;
          }
          break;
        }
      }
      cout << st << endl;
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
2 10 5
bdfij
1 7 5
bcdfg
1 26 25
abcdefghijklmnopqrstuvwxy
1 26 10
arstuvwxyz
*/