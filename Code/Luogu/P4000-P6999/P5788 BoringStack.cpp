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
unsigned int a[3000005], Stk[3000005], *Hd(Stk), f[3000005];
unsigned int n, Cnta(0), Lst, Now;
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3834_3.in", "r", stdin);
  // freopen("P3834.out", "w", stdout);
  n = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  memset(f, 0, sizeof(f));
  for (register unsigned int i(1); i <= n; ++i) {
    while (a[i] > a[*Hd] && Hd > Stk) {
      f[*Hd] = i;
      --Hd;
    }
    if (a[i] < a[i + 1]) {
      f[i] = i + 1;
      continue;
    }
    *(++Hd) = i;
  }
  for (register unsigned int i(1); i <= n; ++i) {
    printf("%u ", f[i]);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
10
1 5 3 2 4 6 3 2 1 5

2 6 5 5 6 0 10 10 10 0
*/