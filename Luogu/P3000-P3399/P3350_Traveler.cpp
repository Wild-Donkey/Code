#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned DistPool[3000005], *ListPool[20005], LinePool[20005], *TopLine(LinePool), a[10005], m, n, q, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
unsigned Pos (short x, short y) {
  return (x - 1) * m + y - 1;
}
struct Node {
  short Globalx, Globaly, Len;
  unsigned *ButDis;
}N[20005];
struct Square{
  Square *LS, *RS;
  short Width, Height, LUx, LUy, Mid;
  Node *Line;
  inline short Cut() {
    return (Width < Height) ? Width : Height;
  }
  unsigned **List;
  inline short Num(const short x, const short y) {
    return (x - LUx) * Width + y - LUy;
  }
}S[20005];
void Div(Square *Now, short x, short y, short _x, short _y) {
  Now->LUx = x, Now->Luy = y;
  Now->Height = _x - x + 1, Now->Width = _y - y + 1;
  if((Now->Height == 1) && (Now->Width == 1)) return;
  *Line = ++TopLine;
  if(Width < Height) {
    Mid = (LUx + Height) >> 1;
    Div();
    Div();
  } else {
    Mid = (LUy + Width) >> 1;
  }
  for (register unsigned )
  Dijkstra();
}
void Qry(Square *Now) {
  if(Width < Height) {
    
  }
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  Div(S, 1, 1, n, m);
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  q = RD();
  for (register unsigned i(1); i <= q; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    if((A == C) && (B == D)) {printf("0\n");continue;}
    if(A > C) swap(A, C), swap(B, D); 
    Ans = 0, Qry(S), printf("%u\n", Ans);
  }
//  }
  return Wild_Donkey;
}

