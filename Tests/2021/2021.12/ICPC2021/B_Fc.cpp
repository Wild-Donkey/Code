#include<iostream>
#include<cstdio>
using namespace std;
inline unsigned RD() {
  unsigned RTmp(0);
  char Rch(getchar());
  while (Rch < '0' || Rch > '9') Rch = getchar();
  while (Rch >= '0' && Rch <= '9') RTmp = (RTmp << 3) + (RTmp << 1) + Rch - '0', Rch = getchar();
  return RTmp;
}
const unsigned Mod(998244353);
unsigned n, m, t, Ans(0), a[1000005];
unsigned STop(0), Fist[1000005], HTop(0);
unsigned His[10000005], HisP[10000005];
unsigned A, B, C, D;
signed main() {
  freopen("B.in", "r", stdin);
  freopen("B.ans", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) {
    D = RD();
//    for (unsigned j(0); j < 30; ++j) printf("%u %u\n", j, N[0].Val[j]);
    switch (D) {
      case(1): {
        A = RD(), B = RD();
        Fist[++STop] = HTop + 1;
        for (unsigned i(A); i <= B; ++i) {
          HisP[++HTop] = i, His[HTop] = a[i];
          a[i] = (a[i] & (a[i] >> 1));
        }
        break;
      }
      case(2): {
        A = RD(), B = RD(), Ans = 0;
        for (unsigned i(A); i <= B; ++i) Ans += a[i];
        printf("%u\n", Ans);
        break;
      }
      case(3): {
        for (; HTop >= Fist[STop]; --HTop) a[HisP[HTop]] = His[HTop];
        --STop;
        break;
      }
    }
  }
  return 0;
}
/*
10 2
1 2 3 4 5 6 7 8 9 10
1 5 10
2 1 5
3
1 2 10
3
*/
