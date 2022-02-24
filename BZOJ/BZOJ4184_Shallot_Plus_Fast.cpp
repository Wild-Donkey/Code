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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
map<unsigned, unsigned> a;
unsigned Val[500005], Out[500005], Bin[32], B[32], b[32], n;
unsigned C(0), D, Rk;
unsigned Cnt(0), Ans(0);
int A;
signed main() {
  // freopen("P4184_1.in", "r", stdin);
  // freopen("P4184.my", "w", stdout);
  n = RD(), Bin[0] = 1; for (unsigned i(1); i <= 30; ++i) Bin[i] = (Bin[i - 1] << 1);
  memset(Out, 0x3f, (n + 1) << 2);
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), Ans = 0;
    if (A < 0)  Out[Val[i] = Out[i] = a[D = -A]] = i - 1;
    else a[Val[i] = D = A] = i;
  }
  for (unsigned i(1); i <= n; ++i) if (Out[i] == 0x3f3f3f3f) Out[i] = n;
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Out[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) {
    if (!(i % 50000)) fprintf(stderr, "Now %u\n", i);
    Ans = 0, D = Val[i];
    // printf("Now %u %u %u\n", i, Out[i], i > Out[i]);
    if (i > Out[i]) { for (unsigned j(0); j <= 30; ++j) if (b[j] == D) { B[j] = b[j] = 0; break; } }
    else {
      // printf("Add %u\n", i);
      unsigned Cur(i);
      for (unsigned j(30); (~j) && D; --j) if (D & Bin[j]) {
        if (B[j]) { if (Out[b[j]] < Out[Cur]) swap(D, B[j]), swap(Cur, b[j]); D ^= B[j]; }
        else { b[j] = Cur, B[j] = D; break; }
      }
    }
    // printf("Linear Basis:");
    // for (unsigned j(0); j <= 30; ++j) if (B[j]) printf("%u ", B[j]); putchar(0x0A);
    // printf("BSet:");
    // for (unsigned j(0); j <= 30; ++j) if (BSet[j]) printf("%u ", BSet[j]); putchar(0x0A);
    // printf("Now Have:");
    // for (unsigned j(1); j <= Cnt; ++j) if ((List[j].In <= i) && (List[j].Out >= i)) printf("%u ", List[j].Val); putchar(0x0A);
    for (unsigned j(30); ~j; --j) if (B[j] && (!(Ans & Bin[j]))) Ans ^= B[j];
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
645

4
3
2
-3
1

12
13
10
-13
7
14
8
12
-7
8
-8
11
-10

13
13
10
13
14
15
15
14
14
14
15
15
*/