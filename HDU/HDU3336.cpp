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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
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
unsigned Nxt[200005], Dep[200005], n, Ans(0), t;
const unsigned MOD(10007);
char A[200005];
inline void Clr() {
  memset(A, 0, n + 2);
  memset(Nxt, 0, ((n + 2) << 2));
  memset(Dep, 0, ((n + 2) << 2));
  n = RD(), Ans = n % MOD;
  scanf("%s", A + 1);
}
int main() {
  // double Ti(clock()), Mti(0);
  //   freopen("P3375_11.in", "r", stdin);
  //   freopen("P3375.out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(2), k(1); i <= n; ++i) {  // Origin_Len
      while (((A[k] ^ A[i]) && k > 1) || k > i) {
        k = Nxt[k - 1] + 1;
      }
      if (A[k] == A[i]) {
        Nxt[i] = k;
        Dep[i] = Dep[k] + 1;
        Ans = (Ans + Dep[i]) % MOD;
        ++k;
      }
      //      printf("%u %u\n", Nxt[i], Dep[i]);
    }
    printf("%u\n", Ans);
  }
  return Wild_Donkey;
}
/*
ABCABCDABABCDABCDABDE
*/
