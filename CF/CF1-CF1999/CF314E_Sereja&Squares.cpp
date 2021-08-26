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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned m, n, Cnt(0), Ans(0), f[150005], L, R;
char a;
int main() {
  n = RD(), m = n >> 1;
  if(n & 1) {
    printf("0\n");
    return 0;
  }
  L = n, R = n + m, f[L] = 1;
  while (((a < 'a') || (a > 'z')) && (a ^ '?')) a = getchar();
  for (register unsigned i(1); i <= n; ++i) {
    --L, --R;
    if(a == '?') {
      ++Cnt;
      for (register unsigned j(L); j < R; ++j)
        f[j] += f[j + 2];
    }
    a = getchar();
  }
  if(Cnt < m) {
    printf("0\n");
    return 0;
  }
  Cnt += m - n;
  Ans = f[L];
  for (register unsigned i(1); i <= Cnt; ++i) Ans *= 25;
  printf("%u\n", Ans);
  return Wild_Donkey;
}

