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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline long long RDsg() {
  long long rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
long long Dis(long long x, long long y) { return (x < y) ? y - x : x - y; }
char Jud(long long x, long long y, long long z) {
  return (x < y) ? (y < z) : (z < y);
}
long long A, B, C, D, E, F;
long long Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  A = RDsg(), B = RDsg(), C = RDsg(), D = RDsg(), E = RDsg(), F = RDsg();
  Ans = Dis(A, C) + Dis(B, D) + Dis(C, E) + Dis(D, F) - 1;
  if (C ^ E) {
    long long Bns(2 + (((B == D) && (D == F)) ? 2 : 0));
    if ((C < E) && (A >= C)) Ans += Bns;
    if ((C > E) && (A <= C)) Ans += Bns;
  }
  if (D ^ F) {
    long long Bns(2 + (((A == C) && (C == E)) ? 2 : 0));
    if ((D < F) && (B >= D)) Ans += Bns;
    if ((D > F) && (B <= D)) Ans += Bns;
  }
  if ((C ^ E) && (D ^ F) && (A ^ C) && (B ^ D)) {
    Ans += 2 * (Jud(A, C, E) && Jud(B, D, F));
  }
  printf("%lld\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
0 0 1 1 -1 -1
9
0 1 1 0 -1 -1
6
0 0 1 0 -1 0
6
0 0 1 0 -1 -1
7
-1 0 1 0 0 0
6
-1 0 0 0 1 0
1
0 1 0 0 1 0
3
-1 0 -1 1 0 0
6
1 0 0 1 0 0
4
1 0 0 1 -1 0
5
1 0 -1 1 0 0
8
1 0 2 1 0 0
8
1 0 -1 0 0 1
7
1 0 0 0 -1 1
4
1 0 0 0 2 1
7
0 1 -1 0 1 0
5
-1 1 0 0 1 0
2
2 1 0 0 1 0
5
-1 1 0 0 1 -1
5
0 1 0 0 1 -1
4
*/