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
unsigned a[15];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Ans[15][15][2];
inline void Copy(unsigned x, char* y) {
  unsigned z(strlen(y));
  a[x] = (z >> 1);
  for (unsigned i(0); i < z; ++i) Ans[x][i >> 1][i & 1] = y[i];
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Copy(2, "b1b3c2c6");//Not b3c2c6 Done
  Copy(3, "b2b3c2");//Done
  Copy(4, "b1b3");//Done
  Copy(5, "a1");//Done
  Copy(8, "d1");//Done
  Copy(9, "d1");//Done
  Copy(10, "d1");//Done
  Copy(1, "c1c3c4");/*
      Done c1c3c4
      Not c4 c3c4 b3c4 
      b3c3c4 c3c4c6 b1b3c4 c1c3c4
      b1c3c4c6 b1b3c3c4 b3c1c4c6 b3c3c4c6 c1c3c4c6
      b1b3c3c4c6 b1b3b5c3c4c6 b1b5c3c4c6 b3b5c3c4c6 b3c1c3c4c6
      b3c1c3c4c6 b1b3c1c2c3c4c6 b3c1c2c3c4c6
  */
  Copy(6, "b2c1c2");/*
    Must b2(Useless) b3(No Solusion) c1 (No Latex) c2(Space) c5 (Title) c6 (English Dot)
    Not b2c1c5 b2b3c1c2 b2b3c1c2c6 b1b2b3c1c2 b1b2b3c1c2c6
    b2b3c1c2c5c6 b1b2b3c1c2c5c6 b1b2b3c1c2c4c5c6
  */
  Copy(7, "b2c1c2c3c5");/*
    Not b2c1c3c5 b2b7c1c2c3 b2c1c3c5c6 b2b7c1c2c3c5 b2b7c1c3c5c6 b2b7c1c2c3c5c6 b2b7c1c2c3c4c5c6
  */
  
  Copy(11, "b6b7c1c2c5");/*
    Not b6b7c5 b3b6b7c1c2c3c5c6 b6c1c2c3c5c6 b6c1c2c3c5 b2b6c1c2c3c5 b6b7c2c3c4c b2b3b6c2c3c4c5 b1b3b6c1c2c3c5
    b2b3b6b7c2c3c4c5 b2b3b6b7c2c3c4c5 b1b3b6c1c2c3c5c6 b2b3b6b7c1c2c3c5c6
  */
  Copy(12, "b2b3c1c6");//Not b2b3 b2b3c4c6 b1b 2b3c4c6c7
  n = RD();
  for (unsigned i(0); i < a[n]; ++i) putchar(Ans[n][i][0]), putchar(Ans[n][i][1]), putchar(' ');
//  }
  return Wild_Donkey;
}

