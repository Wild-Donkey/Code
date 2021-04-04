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
#define Wild_Donkey 0
using namespace std;
inline unsigned int RD() {
  char ich(getchar());
  unsigned int intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  //  printf("RD %d\n", intmp);
  return intmp;
}
unsigned int n, t, m, c, L, R;
double a[105], ans(0), rat;
void Clr() {
  ans = 0;
  n = RD();
  c = RD();
  m = RD();
  rat = (c - 1) * c / 2;
  rat /= c;
  rat += 1;
  rat /= 2;
  for (register int i(1); i <= n; ++i) {
    a[i] = 1.0;
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  freopen("elephant.in", "r", stdin);
  freopen("elephant.out", "w", stdout);
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    // printf("Rat = %lf\n", rat);
    for (register int i(1); i <= m; ++i) {
      L = RD();
      R = RD();
      for (register int j(L); j <= R; ++j) {
        a[j] *= rat;
      }
    }
    for (register int i(1); i <= n; ++i) {
      ans += a[i];
    }
    printf("%.9lf\n", ans);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
3 2 2
2 2
1 3
1 3 1
1 1
5 2 2
3 4
2 4

2.062500000
1.000000000
3.875000000
*/