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
unsigned int a[1000005], Pri[100005], m, n, Cnt(0), A, B, C, D, t;
bool b[1000005];
char s[10005];
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  memset(b, 0, sizeof(b));
  memset(Pri, 0, sizeof(Pri));
  sort(a + 1, a + n + 1);
  b[2] = 0;
  for (register unsigned i(2); i <= a[n]; ++i) {
    if(!b[i]) {
      Pri[++Cnt] = i;
    }
    for (register unsigned j(1); j <= Cnt && i * Pri[j] <= a[n]; ++j) {
//      printf("Do %u %u\n", i, Pri[j]);
      b[i * Pri[j]] = 1;
      if(!(i % Pri[j])) {//保证 Pri[j] 小于等于 i 的最小质因数 
        break;
      }
    }
//    printf("%u %u\n", i, b[i]);
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!b[a[i]]) {
      printf("%u ", a[i]);
    }
  }
  putchar('\n');
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


