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
//   freopen("SP9070_13.in", "r", stdin);
//   freopen("SP9070.out", "w", stdout);
  n = RD();
  for (register unsigned i(0x1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(0x1); Square[i - 0x1] <= n; ++i) Square[i] = i * i;
  memcpy(Fst, a, (n + 0x1) << 0x2);
  for (register unsigned i(0x1), j, But(1); i <= n; ++i) {
    Scd[i] = std::max(Scd[i - 0x1], Fst[i]), j = 0x0;
    for (; But + Square[j] < i; ++j)
      if(Scd[i] < ++Fst[i - Square[j] - 0x1])
        But = i - Square[j] - 0x1, Scd[i] = Fst[But];      
    if(Fst[i] == Scd[i]) But = i;
  }
  memcpy(Fst, a, (n + 0x1) << 0x2);
  memcpy(Ans, Scd, (n + 0x1) << 0x2);
  for (register unsigned i(n), j, But(n); i; --i) {
    Scd[i] = Scd[i + 0x1], j = 0x0;
    for (; i + Square[j] < But; ++j)
      if(Scd[i] < ++Fst[i + Square[j] + 0x1])
        But = i + Square[j] + 0x1, Scd[i] = Fst[But];
    Ans[i] = std::max(Scd[i], Ans[i]);
  }
  for (register unsigned i(0x1); i <= n; ++i)
    printf("%u\n", Ans[i] - a[i]);
  return Wild_Donkey;
}
