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
inline int RD() {
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
int n, m, k, t, hl, cnt1;
long long ans;
bool b[105][105];
char ch, s[100005];
inline void Clr() {
  n = RD();
  m = RD();
  cnt1 = 0;
  return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    for (register int i(1); i <= n; ++i) {
      gets(s);
      for (register int j(1); j <= m; ++j) {
        b[i][j] = s[j - 1] - '0';
        if (b[i][j]) {
          ++cnt1;
        }
      }
    }
    printf("%d\n", cnt1 * 3);
    for (register int i(1); i <= n; ++i) {
      for (register int j(1); j <= m; ++j) {
        // printf("%d ", int(b[i][j]));
        if (b[i][j]) {
          if (i == 1 && j == 1) {
            printf("1 1 1 2 2 1\n");
            printf("1 1 1 2 2 2\n");
            printf("1 1 2 1 2 2\n");
            continue;
          }
          if (i == 1) {
            printf("1 %d 1 %d 2 %d\n", j, j - 1, j - 1);
            printf("1 %d 1 %d 2 %d\n", j, j - 1, j);
            printf("1 %d 2 %d 2 %d\n", j, j - 1, j);
            continue;
          }
          if (j == 1) {
            printf("%d 1 %d 1 %d 2\n", i, i - 1, i - 1);
            printf("%d 1 %d 1 %d 2\n", i, i - 1, i);
            printf("%d 1 %d 2 %d 2\n", i, i - 1, i);
            continue;
          }
          printf("%d %d %d %d %d %d\n", i, j, i - 1, j, i - 1, j - 1);
          printf("%d %d %d %d %d %d\n", i, j, i - 1, j, i, j - 1);
          printf("%d %d %d %d %d %d\n", i, j, i - 1, j - 1, i, j - 1);
        }
      }
    }
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
7
2 4
0 24 34 58 62 64 69 78
2 2
27 61 81 91
4 3
2 4 16 18 21 27 36 53 82 91 92 95
3 4
3 11 12 22 33 35 38 67 69 71 94 99
2 1
11 41
1 9
1 1 1 1 1 1 1 1 1
1 1
1
*/