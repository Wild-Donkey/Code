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
int n, m, k, t, hl, A;
long long ans;
bool b[100005];
char ch, s[100005];
inline void Clr() {
  n = RD();
  k = RD();
  m = n * k;
  hl = (n - 1) >> 1;
  ans = 0;
  return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    for (register int i(1); i <= hl * k; ++i) {
      A = RD();
    }
    for (register int i(1); i <= k; ++i) {
      ans += RD();
      for (register int j(1); j <= (n >> 1); ++j) {
        A = RD();
      }
    }
    printf("%I64d\n", ans);
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