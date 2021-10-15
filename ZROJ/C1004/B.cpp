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
unsigned Last[100005], Round[100005], Bel[100005];
char Flg(0);
inline void Clr() {
  memset(Bel, 0, (Cnt + 2) << 2);
  memset(Last, 0, (Cnt + 2) << 2);
  memset(Round, 0, (Cnt + 2) << 2);
  n = RD(), Flg = 0;
}
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return x;
}
inline char Judge (const unsigned x, const unsigned y) {
//  printf("Do %u %u\n", x, y);
  if(x > n) return 1;
  for (unsigned i(x); i <= n; i += y) Bel[a[i]] = Last[a[i]] = Round[a[i]] = 0;
  for (unsigned i(x); i <= n; i += y) {
    if((Last[a[i]]) && (!Round[a[i]])) Round[a[i]] = i - Last[a[i]]; 
    Last[a[i]] = i;
  }
  unsigned k(0);
  for (unsigned i(x); i <= n; i += y) if(Round[a[i]])
    {if(k) k = Gcd(k, Round[a[i]]); else k = Round[a[i]];}
  if(!k) return 1;
  if(k == y) {
    unsigned Lasta(0);
    for (unsigned i(x); i <= n; i += y) 
      if(!Lasta) Lasta = a[i]; else if(Lasta ^ a[i]) return 0;
    return 1;
  }
  for (unsigned i(x); i <= n; i += y){
//    printf("At %u Val %u Bel %u To %u\n", i, a[i], Bel[a[i]], (i % k) + 1);
    if(!Bel[a[i]]) Bel[a[i]] = (i % k) + 1;
    else if(Bel[a[i]] ^ ((i % k) + 1)) return 0;
  }
  for (unsigned i(0); i < k; i += y) if(!(Judge(x + i, k))) return 0;
  return 1;
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
    sort(b + 1, b + n + 1);
    Cnt = unique(b + 1, b + n + 1) - b;
    for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + Cnt, a[i]) - b;
    printf(Judge(1, 1) ? "Yes\n" : "No\n");
  } 
  return Wild_Donkey;
}
/*
1
6
1 3 1 1 1 3
*/
