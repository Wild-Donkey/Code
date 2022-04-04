/*









-1
-1
2
-1
2
3 
2
-1
2
4
2
3
2
4
2
-1
2
3
2
5
2
4
2
3
2
4
2
7
2
3
2
-1
2
4
2
3
2
4
2
5
2
3
2
8
2
4
2
3
2
4
2
8
2
3
2
7
2
4
2
3
2
4
2
-1
2
3
2
8
2
4
2
3
2
4
2
8
2
3
2
5
2
4
2
3
2
4
2
11
2
3
2
8
2
4
2
3
2
4
2
5
*/
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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long m, n;
unsigned long long A, B, C, D;
unsigned t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), A = 1;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    if(n & 1) {printf("2\n"); continue;}
    while (!(n & 1)) n >>= 1, A <<= 1;
    if(n == 1) {printf("-1\n"); continue;}
    A <<= 1, printf("%llu\n", min(n, A));
  }
  return Wild_Donkey;
}
