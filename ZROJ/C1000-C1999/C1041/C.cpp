#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
vector <unsigned> Contain[500005];
bitset<500005> Own;
unsigned a[500005], Range[500005][2];
unsigned Log[500005], Bin[20];
unsigned Pre[500005][20], Suf[500005][20], Last[500005]; 
unsigned m, n, q;
unsigned A, B, C, D, t;
unsigned Ans(0), Cnt(0), Tmp(0);
char Flg(0);
inline unsigned FindPre(unsigned x, unsigned y) {
  unsigned LgLen(Log[y - x + 1]);
  return min(Pre[x][LgLen], Pre[y - Bin[LgLen] + 1][LgLen]);
}
inline unsigned FindSuf(unsigned x, unsigned y) {
  unsigned LgLen(Log[y - x + 1]);
  return max(Suf[x][LgLen], Suf[y - Bin[LgLen] + 1][LgLen]);
}
//  inline void Clr() {}
signed main() {
//  freopen("C4.in", "r", stdin);
//  freopen("C4.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(RD()); j; --j) Contain[i].push_back(RD());
  for (unsigned i(1); i < n; ++i) {
    for (auto j:Contain[i]) Last[j] = i;
    Pre[i + 1][0] = Last[a[i]];
  }
  memset(Last, 0x3f, (n + 1) << 2);
  for (unsigned i(n); i > 1; --i) {
    for (auto j:Contain[i]) Last[j] = i;
    Suf[i - 1][0] = Last[a[i - 1]];
  }
//  for (unsigned i(1); i < n; ++i) printf("%u [%u, %u]\n", i, Pre[i][0], Suf[i][0]); 
  for (unsigned i(1), j(0); (i << 1) <= n; i <<= 1, ++j) for (unsigned k(n - (i << 1) + 1); k; --k)
    Pre[k][j + 1] = min(Pre[k][j], Pre[k + i][j]), Suf[k][j + 1] = max(Suf[k][j], Suf[k + i][j]);
  for (unsigned i(1), j(0); i <= n; i <<= 1, ++j) Log[i] = j, Bin[j] = i;
  for (unsigned i(1); i <= n; ++i) Log[i] = max(Log[i], Log[i - 1]);
  for (unsigned i(1); i <= n; ++i) {
    Range[i][0] = Range[i][1] = i;
    if(Range[i - 1][1] < i) {
      while (1) {
        Flg = 0;
        if(Range[i][0] > 1) {
          unsigned BL(1), BR(Range[i][0]), BMid;
          while (BL < BR) {
            BMid = (BL + BR) >> 1;
            if(FindSuf(BMid, Range[i][0] - 1) > Range[i][1]) BL = BMid + 1;
            else BR = BMid;
          }
          if(BL ^ Range[i][0]) Range[i][0] = BL, Flg = 1;
        }
        if(Range[i][1] < n) {
          unsigned BL(Range[i][1]), BR(n), BMid;
          while (BL < BR) {
            BMid = (BL + BR + 1) >> 1;
            if(FindPre(Range[i][1] + 1, BMid) < Range[i][0]) BR = BMid - 1;
            else BL = BMid;
          }
          if(BL ^ Range[i][1]) Range[i][1] = BL, Flg = 1;
        }
        if(!Flg)break;
      }
    } else {
      unsigned BR(n), BMid;
      while (Range[i][1] < BR) {
        BMid = (Range[i][1] + BR + 1) >> 1;
        if(FindPre(i + 1, BMid) < i) BR = BMid - 1;
        else Range[i][1] = BMid;
      }
      if(Suf[i - 1][0] <= Range[i][1]) Range[i][0] = Range[i - 1][0], Range[i][1] = Range[i - 1][1];
    }
  }
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    printf(((Range[A][0] <= B) && (B <= Range[A][1])) ? "YES\n" : "NO\n");
  }
  return Wild_Donkey;
}
/*
7
6 3 4 1 2 5
1 1
1 5
1 1
1 1
2 2 3
1 4
1 6
3
4 1
5 3
4 7
*/
