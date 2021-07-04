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
inline unsigned RD() {
  unsigned intmp = 0;
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
unsigned ST[20][500005], Square[1005], Bin[20], Log[500005], m, n;
const unsigned _1(1);
inline unsigned Qry(unsigned L, unsigned R) {
  register unsigned LogLen(Log[R - L + _1]);
  return std::max(ST[LogLen][L], ST[LogLen][R - Bin[LogLen] + 1]);
}
int main() {
//   freopen("SP9070_7.in", "r", stdin);
//   freopen("SP9070.out", "w", stdout);
  n = RD();
  for (register unsigned i(_1); i <= n; ++i) ST[0][i] = RD();
  for (register unsigned i(_1), j(0); i <= n; i <<= 1, ++j) Bin[j] = i, Log[i] = j;
  for (register unsigned i(_1); i <= n; ++i) Log[i] = std::max(Log[i], Log[i - _1]);
  for (register short i(_1); Square[i - _1] <= n; ++i) Square[i] = i * i;
  for (register unsigned i(_1); i <= Log[n]; ++i)
    for (register unsigned j(_1); j + Bin[i - _1] <= n; ++j) 
      ST[i][j] = std::max(ST[i - _1][j], ST[i - _1][j + Bin[i - _1]]);
  for (register unsigned i(_1), j, Tmp, Ans; i <= n; ++i) {
    Ans = ST[0][i];
    if(i ^ _1) {
      j = _1, Tmp = i - _1;
      for (; Square[j] < i - _1; Tmp = i - Square[j] - _1, ++j)
        Ans = std::max(Ans, j + Qry(i - Square[j], Tmp));
      Ans = std::max(Ans, j + Qry(_1, Tmp));
    }
    if(i ^ n) {
      j = _1, Tmp = i + _1;
      for (; i + Square[j] < n; Tmp = i + Square[j] + _1, ++j)
        Ans = std::max(Ans, j + Qry(Tmp, i + Square[j]));
      Ans = std::max(Ans, j + Qry(Tmp, n));
    }
    printf("%u\n", ((Ans < ST[0][i]) ? 0 : Ans - ST[0][i]));
  }
  return Wild_Donkey;
}
