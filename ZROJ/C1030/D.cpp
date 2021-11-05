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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned SA[1000005], Rank[1000005], Pos[1000005];
unsigned Backet[1000005], MaxB(0);
char a[1000005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  scanf("%s", a + 1);
  for (unsigned i(2); i <= n; ++i) if(a[i] ^ a[i - 1]) {Flg = 1; break;}
  if(!Flg) {
    for (unsigned i())
    return 0;
  }
  for (unsigned i(1); i < n; ++i) a[i + n] = a[i]; n <<= 1, n -= 1; 
  for (unsigned i(1); i <= n; ++i) 
  for (unsigned i(1); i <= n; ++i) ++Backet[a[i] -= '`'], MaxB = max(MaxB, a[i]);
  for (unsigned i(1); i <= 26; ++i) {
    
  }
//  }
  return Wild_Donkey;
}

