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
inline unsigned long long RD() {
  unsigned long long intmp (0);
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
unsigned long long m, n, LCM, G1, G2, G, Ans(0xffffffffffffffff), TmpC;
unsigned long long Gcd(unsigned long long x, unsigned long long y){
  register unsigned long long Tmpx;
  while (y) Tmpx = x, x = y, y = Tmpx % x;
  return x;
}
struct Per{
  unsigned long long T, X, Y; 
}P[1005];
int main() {
//   freopen("A.in", "r", stdin);
//   freopen("A.out", "w", stdout);
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= m; ++i) 
    P[i].T = RD(), P[i].X = RD() % n, P[i].Y = RD() % n;
  for (register unsigned i(2); i <= m; ++i) {
    for (register unsigned j(1); j < i; ++j) {
      G = Gcd(P[i].T, P[j].T);
      G1 = P[i].T / G;
      G2 = P[j].T / G;
      LCM = G1 * P[j].T;
      TmpC = G1;
      G1 = ((G2 - 1) * P[i].Y) % n; 
      G2 = ((TmpC - 1) * P[j].Y) % n;
      if(((P[i].X + G1) % n) != ((P[j].X + G2) % n)) {
        Ans = min(LCM, Ans);
        continue;
      }
      G1 = ((G1 << 1) + P[i].Y) % n;
      G2 = ((G2 << 1) + P[j].Y) % n; 
//      printf("%llu %llu %llu %llu\n", G1, G2, (P[i].X + G1) % n, (P[j].X + G2) % n);
      if(((P[i].X + G1) % n) != ((P[j].X + G2) % n)) {
        Ans = min(LCM << 1, Ans);
      }
    }
  }
  if(Ans == 0xffffffffffffffff) {
    printf("Mystia will cook forever...\n");
    return 0;
  }
  printf("%llu\n", Ans - 1);
//    }
  return Wild_Donkey;
}
/*

*/
