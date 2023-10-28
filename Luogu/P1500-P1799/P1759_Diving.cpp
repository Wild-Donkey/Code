#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int n, m, a[105], b[105], c[105], f[205][205], fa[205][205][105];
char ch;
string s;
inline int IN() {
  char ich(getchar());
  int intmp(0), insign(1);
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) ich = getchar();
  if (ich == '-') insign = -1, ich = getchar();
  while ((ich <= '9') && (ich >= '0'))
    intmp *= 10, intmp += ich - '0', ich = getchar();
  return intmp * insign;
}
inline char Cmp(int *x, int *y) {
  unsigned len(min(x[0], y[0]));
  for (unsigned i(1); i <= len; ++i)
    if (x[i] ^ y[i]) return x[i] < y[i];
  return 0;
}
signed main() {
  a[0] = IN(), b[0] = IN(), n = IN();
  for (int i = 1; i <= n; ++i) a[i] = IN(), b[i] = IN(), c[i] = IN();
  for (int k(1); k <= n; ++k) {
    for (int i(a[0]); i >= a[k]; --i) {
      for (int j(b[0]); j >= b[k]; --j) {
        int dela(i - a[k]), delb(j - b[k]), Cur(f[dela][delb] + c[k]);
        fa[dela][delb][++fa[dela][delb][0]] = k;
        if (Cur > f[i][j] ||
            (Cur == f[i][j] && Cmp(fa[dela][delb], fa[i][j]))) {
          f[i][j] = Cur;
          for (int h(0); h <= fa[dela][delb][0]; ++h)
            fa[i][j][h] = fa[dela][delb][h];
        }
        --fa[dela][delb][0];
      }
    }
  }
  printf("%d\n", f[a[0]][b[0]]);
  for (int h(1); h <= fa[a[0]][b[0]][0]; ++h) printf("%d ", fa[a[0]][b[0]][h]);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
