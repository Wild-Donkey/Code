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
//#define int long long
#define Wild_Donkey 0
using namespace std;
inline unsigned int RD() {
  unsigned int intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned int m, n;
int a[200005], b[200005], Min[200005], Max(-0x3f3f3f3f), Ans(-0x3f3f3f3f);
char s[10005];
inline void Clr() {
//  Ans = -0x3f3f3f3f;
  n = RD();
}
signed main() {
  // double Ti(clock()), Mti(0);
//   freopen("P1115_1.in", "r", stdin);
  // freopen(".out", "w", stdout);
  Clr();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RDsg();
  }
  Max = a[1];
  for (register unsigned int i(2); i <= n; ++i) {
    if(Max < 0) {
      Max = 0;
    }
    Max += a[i];
    Ans = max(Max, Ans);
  }
  printf("%d\n", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
*/
