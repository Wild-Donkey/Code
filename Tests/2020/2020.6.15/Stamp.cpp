#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int m, n, ma = 0, a[10005], ans[10005], f[100005];
int judge(int x) {  // x种邮票凑
  int sum = 0;
  f[0] = 0;
  while (f[sum] <= n) {  //用n张以内邮票凑出sum
    // cout << sum << endl;
    sum++;
    f[sum] = 0x3f3f3f3f;
    for (int i = 1; i <= x; i++) {  //转移
      if (sum - a[i] >= 0) {        //防止越界
        f[sum] = min(f[sum - a[i]] + 1, f[sum]);
      }
    }
  }
  sum--;
  return sum;
}
void dfs(int x, int y) {  //第x种, 前x-1有y个
  // printf("%d\n", x);
  if (x > m) {
    int sum = judge(m);
    if (sum > ma) {  //更新答案
      ma = sum;
      for (int ii = 1; ii <= m; ii++) {
        ans[ii] = a[ii];
      }
    }
    return;
  }
  int tm = judge(x - 1);
  for (int j = a[x - 1] + 1; j <= tm + 1; j++) {
    a[x] = j;
    dfs(x + 1, judge(x));
  }
  return;
}
int main() {
  // freopen("Stamp.in", "r", stdin);
  // freopen("Stamp.out", "w", stdout);
  a[1] = 1;
  scanf("%d%d", &n, &m);
  dfs(2, n);
  /*
  a[1] = 1;
  a[2] = 8;
  a[3] = 13;
  */
  for (int ii = 1; ii <= m; ii++) {
    printf("%d ", ans[ii]);
  }
  printf("\nMAX=%d\n", ma);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
3 2

7 3
1 8 13 69

7 4
1 5 24 37 165

10 3
1 10 26 146

5 5
1 4 9 31 51 126

*/
/*
  n 1 2   3   4   5 6
m
1   1 2   3   4   5   6
2   0 4   7   10  14  18
3   0 0   12  20  29  40
4   0 0   0   33  54  78
5   0 0   0   0   88  143
6   0 0   0   0   0   ?
*/