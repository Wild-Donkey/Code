#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define Wild_Donkey 0
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
unsigned a[500005], Fst[500005], Scd[500005], Square[1005], Ans[500005], m, n;
signed main() {
//   freopen("SP9070_7.in", "r", stdin);
//   freopen("SP9070.out", "w", stdout);
  n = RD();
  for (register unsigned i(0x1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(0x1); Square[i - 0x1] <= n; ++i) Square[i] = i * i;
  memcpy(Fst, a, (n + 0x1) << 0x2);
  for (register unsigned i(0x1), j; i <= n; ++i) {
    Scd[i] = std::max(Scd[i - 0x1], Fst[i]), j = 0x0;
    for (; Square[j] + 0x1 < i; ++j)
      Scd[i] = std::max(Scd[i], ++Fst[i - Square[j] - 0x1]);
  }
  memcpy(Fst, a, (n + 0x1) << 0x2);
  memcpy(Ans, Scd, (n + 0x1) << 0x2);
  for (register unsigned i(n), j; i; --i) {
    Scd[i] = Scd[i + 0x1], j = 0x0;
    for (; i + Square[j] < n; ++j)
      Scd[i] = std::max(Scd[i], ++Fst[i + Square[j] + 0x1]);
    Ans[i] = std::max(Scd[i], Ans[i]);
  }
  for (register unsigned i(0x1); i <= n; ++i)
    printf("%u\n", Ans[i] - a[i]);
  return Wild_Donkey;
}
