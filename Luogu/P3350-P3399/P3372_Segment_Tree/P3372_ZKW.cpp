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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long T[262144], Tag[262144];  //>= 2 (n + 2)
unsigned m, n, N;
unsigned long long A, B, C, D;
void Build() {
  for (unsigned i(N - 1); ~i; --i) T[i] = T[i << 1] + T[(i << 1) + 1];
}
void Edit(unsigned L, unsigned R, unsigned long long V) {
  L = L - 1 + N, R = R + 1 + N;
  unsigned long long LLen(0), RLen(0);
  for (unsigned Len(1); L ^ R ^ 1; L >>= 1, R >>= 1, Len <<= 1) {
    T[L] += V * LLen, T[R] += V * RLen;
    if (!(L & 1)) Tag[L ^ 1] += V, LLen += Len;
    if (R & 1) Tag[R ^ 1] += V, RLen += Len;
  }
  while (L) T[L] += LLen * V, T[R] += RLen * V, L >>= 1, R >>= 1;
}
unsigned long long Qry(unsigned L, unsigned R) {
  L = L - 1 + N, R = R + 1 + N;
  unsigned long long Rt(0), LLen(0), RLen(0);
  for (unsigned Len(1); L ^ R ^ 1; L >>= 1, R >>= 1, Len <<= 1) {
    Rt += Tag[L] * LLen, Rt += Tag[R] * RLen;
    if (!(L & 1)) Rt += T[L ^ 1] + Tag[L ^ 1] * Len, LLen += Len;
    if (R & 1) Rt += T[R ^ 1] + Tag[R ^ 1] * Len, RLen += Len;
  }
  while (L) Rt += Tag[L] * LLen, Rt += Tag[R] * RLen, L >>= 1, R >>= 1;
  return Rt;
}
signed main() {
  n = RD(), m = RD(), N = 1;
  while (N < n + 2) N <<= 1;
  memset(T + N, N << 3, 0), memset(Tag, N << 4, 0);
  for (unsigned i(1); i <= n; ++i) T[N + i] = RD();
  Build();
  for (unsigned i(1); i <= m; ++i) {
    D = RD(), A = RD(), B = RD();
    if (D & 1) {  //[A, B] += C;
      C = RD();
      Edit(A, B, C);
    } else {  // Qry [A, B]
      printf("%llu\n", Qry(A, B));
    }
  }
  return Wild_Donkey;
}