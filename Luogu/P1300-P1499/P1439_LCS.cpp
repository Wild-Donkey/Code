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
  while (rdch < '0' || rdch > '9') { rdch = getchar(); }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) { rdch = getchar(); }
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
unsigned a[100005], b[100005], f[100005], n;
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  for (unsigned i(1); i <= n; ++i) b[RD()] = i;
  for (unsigned i(1); i <= n; ++i) a[i] = b[RD()];
  memset(f, 0x3f, (n + 2) << 2);
  f[0] = 0;
  for (unsigned i(1); i <= n; ++i) {
    unsigned *Tmp(lower_bound(f, f + n + 1, a[i]));
    if (*(Tmp - 1) < a[i]) *Tmp = a[i];
  }
  for (unsigned i(n); i; --i)
    if (f[i] < 0x3f3f3f3f) {
      printf("%u\n", i);
      return 0;
    }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
