#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
#define Lbt(x) ((x)&((~(x))+1))
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned N, m, n, A, B, C, t, Ans(0);
unsigned f[5005][15], E[15][15], Min[5005][15], Log[5005];
int main() {
  // freopen("P3959_9.in", "r", stdin);
  //  freopen("P3959.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  N = 1 << (n = RD()), m = RD();
  memset(E, 0x3f, sizeof(E));
  memset(f, 0x3f, sizeof(f));
  memset(Min, 0x3f, sizeof(Min));
  for (unsigned i(1); i <= m; ++i) {
    A = RD() - 1, B = RD() - 1;
    E[A][B] = E[B][A] = min(E[B][A], RD());
  }
  for (unsigned i(0); i < n; ++i) Log[1 << i] = i;
  for (unsigned i(1); i <= N; ++i) Log[i] = max(Log[i - 1], Log[i]);
  for (unsigned i(0); i < N; ++i) {
    unsigned TL(i ^ (N - 1));
    for (unsigned j(i); j; j -= Lbt(j)) {
      unsigned Frm(Log[Lbt(j)]);
      for (unsigned k(TL); k; k -= Lbt(k)) {
        unsigned To(Log[Lbt(k)]);
        Min[i][To] = min(Min[i][To], E[Frm][To]);
      }
    }
  }
  // for (unsigned i(0); i < N; ++i) {
  //   printf("Now %u:", i);
  //   for (unsigned j(0); j < n; ++j) printf("%u ", Min[i][j]);
  //   putchar(0x0A);
  // }
  f[0][0] = 0;
  for (unsigned i(0); i < n; ++i) f[1 << i][0] = 0;
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(0); j < N; ++j) {
      for (unsigned k(j); ; k = (j & (k - 1))) {
        unsigned TL(j ^ k), Sum(0);
        for (unsigned l(TL); l; l -= Lbt(l)) {
          unsigned To(Log[Lbt(l)]);
          Sum += Min[k][To];
        }
        f[j][i] = min(f[j][i], f[k][i - 1] + i * Sum);
        if (!k) break;
      }
    }
  }
  printf("%u\n", f[N - 1][n - 1]);
  //  }
  return Wild_Donkey;
}

