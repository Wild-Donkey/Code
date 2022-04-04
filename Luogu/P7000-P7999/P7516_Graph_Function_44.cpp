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
unsigned a[1005][1005], Sid[200005][2], Prt[200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Udt(unsigned x, unsigned y) {
  unsigned Cur(a[x][y]), To;
  for (unsigned j(1), k(min(j, y)); j <= n; ++j, k = min(j, y)) if(a[j][y] < (To = min(a[j][x], Cur)))
    {if(min(a[j][y], a[y][j]) < k && min(a[y][j], To) >= k) ++Ans; a[j][y] = To, Udt(j, y);}
  for (unsigned j(1), k(min(j, x)); j <= n; ++j, k = min(j, x)) if(a[x][j] < (To = min(a[y][j], Cur)))
    {if(min(a[x][j], a[j][x]) < k && min(a[j][x], To) >= k) ++Ans; a[x][j] = To, Udt(x, j);}
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Ans = n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) Sid[i][0] = RD(), Sid[i][1] = RD();
  for (unsigned i(1); i <= n; ++i) a[i][i] = i;
  Prt[m + 1] = Ans;
  for (unsigned i(m); i; --i) {
//    printf("%u:\n", i); 
    A = Sid[i][0], B = Sid[i][1], C = min(A, B);
    if(min(a[A][B], a[B][A]) < C && min(a[B][A], C) >= C) ++Ans;
    a[A][B] = max(a[A][B], C), Udt(A, B);
    Prt[i] = Ans;
//    for (unsigned j(1); j <= n; ++j) {
//      for (unsigned k(1); k <= n; ++k) printf("%u ", a[j][k]); putchar(0x0A);
//    }
  }
  for (unsigned i(0); i <= m; ++i) printf("%u ", Prt[i + 1]);
  putchar(0x0A);
//  }
  return Wild_Donkey;
}

