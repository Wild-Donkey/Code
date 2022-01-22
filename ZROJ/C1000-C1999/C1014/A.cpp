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
#include <string>
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
unsigned long long m, n, Ans(0), A, B;
unsigned t;
char Flg(0);
inline void Clr() {
  n = RD(), m = RD(), A = RD(), B = RD();
  Ans = Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    if(n / m < A) {printf("%u\n", n / m);continue;}
    if(B / m >= A) {printf("-1\n"); continue;}
    if (n >= m * A) n -= m * A, Ans += A;
    Ans += A * (n / ((m * A) - B));
    n %= ((m * A) - B), n += B;
    Ans += n / m;
    printf("%lld\n", Flg ? -1 : Ans);
  }
  return Wild_Donkey;
}
/*
4
4 2 2 2
4 2 2 4
200000000 100000000 1 99999999
1000000000 500000000 1 499999999
*/
