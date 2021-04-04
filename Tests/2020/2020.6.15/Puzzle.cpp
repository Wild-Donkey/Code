#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, a[105], ans = 0, f[105][105];
bool flg;
char ch;
string s;
int IN() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int main() {
  freopen("Puzzle.in", "r", stdin);
  freopen("Puzzle.out", "w", stdout);
  n = IN();
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    a[i] = IN();
    f[1][i] = 0;
    f[2][i] = 0;
  }
  for (int len = 3; len <= n; len++) {
    for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
      for (int k = l + 1; k < r; k++) {
        f[len][l] = min(f[k - l + 1][l] + f[r - k + 1][k] + a[l] * a[k] * a[r],
                        f[len][l]);
      }
      // printf("%d %d		%d\n", l, r, f[len][l]);
    }
  }
  printf("%d\n", f[n][1]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
/*
6
10 1 50 50 20 5
3650
*/