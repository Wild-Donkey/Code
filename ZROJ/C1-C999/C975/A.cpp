#include <algorithm>
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
unsigned a[20][4], m, n, Cnt(0), A, B, C, D, t, Tmp(0);
char Ans[100000];
void Solve(unsigned Le, unsigned Ri, unsigned R, unsigned P, unsigned S) {
  if (Le == Ri) { Ans[Ri] = (R ^ P) ? (R ? ('R') : ('P')) : ('S');return; }
  unsigned Mid((Le + Ri) >> 1), Len((Ri - Le + 1) >> 1), i(Le), NewR, NewP, NewS;
  if (R ^ P) NewR = R >> 1, NewP = P >> 1, NewS = (S + 1) >> 1;
  else NewR = R >> 1, NewP = (P + 1) >> 1, NewS = S >> 1;
  Solve(Le, Mid, NewR, NewP, NewS), Solve(Mid + 1, Ri, R - NewR, P - NewP, S - NewS);
  for (; i <= Mid; ++i) {
    if (Ans[i] ^ Ans[Len + i]) break;
  }
  if (Ans[i] > Ans[Len + i])
    for (;i <= Mid; ++i) swap(Ans[i], Ans[Len + i]);
}
void Print(unsigned Len) {
  for (unsigned i(0); i < Len; ++i) putchar(Ans[i]);
  putchar('\n');
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), a[1][2] = 1;
  for (unsigned i(2); i <= 15; ++i) {
    a[i][0] = a[i - 1][0] + a[i - 1][2];
    a[i][1] = a[i - 1][1] + a[i - 1][0];
    a[i][2] = a[i - 1][2] + a[i - 1][1];
    sort(a[i] + 0, a[i] + 3);
    // printf("%u: %u %u %u\n", i, a[i][0], a[i][1], a[i][2]);
  }
  for (register unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), C = RD(), m = A + B + C;
    if (((A == m / 3) || (A == (m / 3) + 1)) && ((B == m / 3) || (B == (m / 3) + 1)) && ((C == m / 3) || (C == (m / 3) + 1)))
      Solve(0, m - 1, A, B, C), Print(m);
    else { printf("-1\n"); continue; }
  }
  system("pause");
  return Wild_Donkey;
}
/*
0 0 1
0 1 1
1 1 2
2 3 3
5 5 6
2 3 3
3 2 3
*/