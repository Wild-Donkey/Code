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
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned m, n;
unsigned A, B, C, D, t;
unsigned long long Ans(0), Tmp(0);
signed main() {
  n = RD(), m = RD(), C = RD(), D = m / (C + 1);
  for (unsigned i(1); i <= n; ++i) {
    B = max(B, RD());
    if (A < B) swap(A, B);
  }
  Tmp = ((unsigned long long)C * A) + B;
  Ans = Tmp * D + (unsigned long long)A * (m % (C + 1));
  printf("%llu\n", Ans);
  return Wild_Donkey;
}