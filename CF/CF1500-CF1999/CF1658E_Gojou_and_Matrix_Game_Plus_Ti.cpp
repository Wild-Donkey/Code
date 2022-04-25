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
unsigned Pos[4000005][2];
unsigned a[2005][2005];
char Ans[2005][2005];
unsigned m, n;
unsigned A, B, C, D, t, Up, Down, Left, Right;
unsigned Cnt(0), Tmp(0);
char Cur, Pre;
inline char Inrg() {
  if(C > Up) return 0;
  if(C < Down) return 0;
  if(D > Right) return 0;
  if(D < Left) return 0;
  return 1;
}
inline void Udt() {
  if(C > m) Down = max(C - m, Down);
  Up = min(C + m, Up);
  if(D > m) Left = max(D - m, Left);
  Right = min(D + m, Right);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), A = n * n, Down = Left = 1, Up = Right = (n << 1);
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) Pos[a[i][j] = RD()][0] = i, Pos[a[i][j]][1] = j;
  for (unsigned i(A); i; --i) {
    C = Pos[i][0] + Pos[i][1], D = n + Pos[i][1] - Pos[i][0];
    if(Inrg()) Udt(), Ans[Pos[i][0]][Pos[i][1]] = 1;
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) putchar(Ans[i][j] ? 'M' : 'G'); 
    putchar(0x0A);
  }
//  }
  return Wild_Donkey;
}
/*
3 1
1 2 4
6 8 3
9 5 7
*/
