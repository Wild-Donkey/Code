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
#define Lbt(x) ((x)&((~(x)) + 1))
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
bitset<200005> Now;
unsigned List[200005][2], Tr[200005];
unsigned long long Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
inline void Find(unsigned x) { while (x) D += Tr[x], x -= Lbt(x); }
inline void Del(unsigned x) { while (x <= m) --Tr[x], x += Lbt(x); }
inline void Pls(unsigned x) { while (x <= m) ++Tr[x], x += Lbt(x); }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  m = (n = RD()) << 1, t = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    List[A][0] = List[C][0] = B;
    List[A][1] = List[C][1] = D;
  }
  Ans = 1;
  for (unsigned i(1); i <= m; ++i) {
    A = List[i][0], B = List[i][1];
    if (Now[A]) {
      Del(A), Del(B), D = 0, Find(B), C = D, D = 0, Find(A - 1), C -= D;
      // if (D & 1) --C;
      Ans += (C >> 1), Now[A] = Now[B] = 0;
      // printf("Del %u\n", C);
    }
    else {
      D = 0, Find(B), C = D, D = 0, Find(A - 1), C -= D;
      Ans += C + 1, Pls(A), Pls(B), Now[A] = Now[B] = 1;
      // printf("Add %u\n", C);
    }
  }
  if (t & 1) printf("%llu\n", Ans);
  else printf("%llu %llu\n", Ans >> 1, Ans - (Ans >> 1));
  //  }
  //  system("pause");
  return Wild_Donkey;
}