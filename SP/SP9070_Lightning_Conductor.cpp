#include <cstdio>
#include <cmath>
#include <cstring>
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
unsigned a[500005], SqRoot[500005], Ans[500005], m, n;
double Max[500005];
char Flg(0); 
void Merge(unsigned L, unsigned R, unsigned DL, unsigned DR) {
  if(L == R) {
    if(Flg) {
      DL = std::max(L, DL);
      for (register unsigned i(DL); i <= DR; ++i)
        Max[L] = std::max(Max[L], a[i] + sqrt(i - L));
    } else {
      DR = std::min(L, DR);
      for (register unsigned i(DL); i <= DR; ++i)
        Max[L] = std::max(Max[L], a[i] + sqrt(L - i));
    }
    Ans[L] = std::max((unsigned)(Max[L] + 0.999999), Ans[L]);
  } else {
    register unsigned Mid((L + R) >> 0x1), mid, Border;
    if(Flg) {
      Border = std::max(Mid, DL);
      for (register unsigned i(Border); i <= DR; ++i)
        if(Max[Mid] < a[i] + sqrt(i - Mid))
          Max[Mid] = a[i] + sqrt(i - Mid), mid = i;
    } else {
      Border = std::min(Mid, DR);
      for (register unsigned i(Border); i >= DL; --i)
        if(Max[Mid] < a[i] + sqrt(Mid - i))
          Max[Mid] = a[i] + sqrt(Mid - i), mid = i;
    }
    Ans[Mid] = std::max((unsigned)(Max[Mid] + 0.999999), Ans[Mid]);
    if(L ^ Mid) Merge(L, Mid - 0x1, DL, mid);
    Merge(Mid + 0x1, R, mid, DR);
  }
}
signed main() {
//   freopen("SP9070_2.in", "r", stdin);
//   freopen("SP9070.out", "w", stdout);
  n = RD();
  for (register unsigned i(0x1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(0x1); i * i <= n; ++i) SqRoot[i * i + 0x1] = i + 0x1;
  for (register unsigned i(0x1); i <= n;++i) SqRoot[i] = std::max(SqRoot[i - 0x1], SqRoot[i]);
  Merge(0x1, n, 0x1, n);
  memset(Max, 0x00, (n + 0x1) << 0x3);
  Flg = 0x1;
  Merge(0x1, n, 0x1, n);
  for (register unsigned i(0x1); i <= n; ++i)
    printf("%u\n", Ans[i] - a[i]);
  return Wild_Donkey;
}
