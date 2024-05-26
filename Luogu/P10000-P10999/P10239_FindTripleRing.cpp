#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
double Eps = 0.0000001;
unsigned long long n, Ans6(0), Ans3(0);
unsigned m, t;
unsigned Cnt(0), Tmp(0);
signed main() {
  n = RDll(), m = pow(n, (double)1 / 3) + Eps;
  for (unsigned i(1); i <= m; ++i) {
    unsigned long long nn(n / i);
    unsigned mm(sqrt(nn) + Eps);
    for (unsigned j(i + 1); j <= mm; ++j) Ans6 += (nn / j) - j;
  }
  for (unsigned i(1); i <= m; ++i) Ans3 += ((n / i) / i) - i;
  for (unsigned i(1); i <= m; ++i) Ans3 += (unsigned)sqrt(n / i) + Eps - i;
  printf("%llu\n", Ans6 * 6 + Ans3 * 3 + m);
  return Wild_Donkey;
}