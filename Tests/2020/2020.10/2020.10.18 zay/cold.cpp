#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp(0), insig;
  char inchar(getchar());
  while ((inchar > '9' || inchar < '0') && (inchar != '-')) {
    inchar = getchar();
  }
  if (inchar == '-') {
    insig = -1;
    inchar = getchar();
  } else {
    insig = 1;
  }
  while (inchar <= '9' && inchar >= '0') {
    intmp *= 10;
    intmp += inchar - '0';
    inchar = getchar();
  }
  return intmp * insig;
}
int ans(0), n, m, t, tmp, a[15][100005], b[15][100005], cnt[100005],
    cst[15][15], f[15][15][30005] /*已有 i 条线, 第 j 层状态为 k 时最少花费*/;
bool Cant[15][15], Can_t[15][30005];
bool Chck(int sta, int x) {
  for (register int i(1); i <= n; ++i) {
    if (sta ^ (1 << i)) {
      if (Cant[i][x]) {
        return 0;
      }
    }
  }
  return 1;
}
int DFS(int x, int dep, int stati[15], int val) {
  if (x == n) {
    return val + cst[x][dep];
  }
  stati[dep] += 1 << x;
  for (register int i(1); i <= n; ++i) {
    if (Chck(stati[dep], i)) {
      DFS(i, dep + 1, stati, val + cst[x][dep]);
    }
  }
  val += cst[x][dep];
  return val;
}
int main() {
  freopen("cold.in", "r", stdin);
  freopen("cold.out", "w", stdout);
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j <= m; ++j) {
      a[i][j] = RD();
    }
  }
  memset(cst, 0, sizeof(cst));
  for (register int i(1); i <= n; ++i) {  //处理 cst
    b[i][0] = RD();
    for (register int j(1); j <= b[i][0]; ++j) {
      b[i][j] = RD();
      ++cnt[b[i][j]];
      for (register int k(1); k <= n; ++k) {  // i 线在 k 层总花费
        cst[i][k] += a[k][j];
      }
    }
    sort(b[i] + 1, b[i] + b[i][0] + 1);
  }
  if (n == 1) {
    printf("%d\n", cst[1][1]);
    return 0;
  }
  if (n <= 10) {
    DFS(0, 0);
  }
  for (register int i(1); i < n; ++i) {  //处理Cant
    for (register int j(i + 1); j <= n; ++j) {
      register int ii(1), ji(1);
      while (ii <= b[i][0] && ji <= b[j][0]) {
        if (b[i][ii] == b[j][ji]) {
          Cant[i][j] = 1;
          Cant[j][i] = 1;
          break;
        }
        if (b[i][ii] < b[j][ji]) {
          ++ii;
        } else {
          ++ji;
        }
      }
    }
  }
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j <= n; ++j) {
      printf("%d ", Cant[i][j]);
    }
    printf("\n");
  }
  memset(f, 0, sizeof(f));
  for (register int i(1); i <= n; ++i) {            //第 i 条线
    for (register int j(1); j <= n; ++j) {          //放第 j 层
      for (register int k(0); k < 1 << (i); ++k) {  //第 j 层原状态 k, i 放 j 上
        if (!Can_t[i][k]) {
          f[i][j][k + (1 << i)] = f[i - 1][j][k] + cst[i][j];
        }
      }
      for (register int k(0); k < 1 << (i); ++k) {  // i 不放 j 上
        f[i][j][k] = f[i - 1][j][k];
      }
    }
  }
  // DFS() {}
  // system("pause");
  return 0;
}