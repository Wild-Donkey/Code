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
unsigned a[100005], b[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Last[100005], Round[100005];
char Flg(0);
inline void Clr() {
  memset(Last, 0, (Cnt + 2) << 2);
  memset(Round, 0, (Cnt + 2) << 2);
  n = RD(), Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
    sort(b + 1, b + n + 1);
    Cnt = unique(b + 1, b + n + 1) - b;
    for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + Cnt, a[i]) - b;
    for (unsigned i(1); i <= n; ++i) {
      if(Last[a[i]]) {
        if(Round[a[i]]) {if((i - Last[a[i]]) ^ Round[a[i]]) {Flg = 1; break;}}
        else {
          Round[a[i]] = i - Last[a[i]];
          for (unsigned j(i + Round[a[i]]); j <= n; j += Round[a[i]])
            if(a[j] ^ a[i]) {Flg = 1; break;}
          if(Flg) break;
          for (unsigned j(Round[a[i]]); i > j; j += Round[a[i]])
            if(a[i - j] ^ a[i]) {Flg = 1; break;}
          if(Flg) break;
        }
      }
      Last[a[i]] = i;
    }
    if(Flg) {printf("No\n");continue;}
    for (unsigned i(1); i <= n; ++i) {
      
    }
    printf(Flg ? "No\n" : "Yes\n");
  } 
  return Wild_Donkey;
}
/*
1 3 5 2 4 6 1 3 7 2 4 5 1 3 6 2 4 7
6 6 6 6 9 9 9
*/
