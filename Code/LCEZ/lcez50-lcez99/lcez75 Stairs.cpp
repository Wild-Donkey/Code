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
unsigned int f[10005], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
//inline void Clr() {
//  n = RD();
//  memset(a, 0, sizeof(a));
//}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  f[1] = 1;
  f[2] = 2;
  for (register unsigned int i(3); i <= n; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  printf("%u\n", f[n]);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


