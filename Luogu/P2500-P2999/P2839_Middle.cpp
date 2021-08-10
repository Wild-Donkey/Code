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
unsigned a[20005], b[20005], Pos[20005], Cnt[20005], RangeL, RangeR, m, n, Cntn, A, B, C, D, t, Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, LVal, RVal; 
}N[800005], *Order[20005];
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = b[i] = RD();
  }
  sort(b + 1, b + n + 1);
  Cntn = unique(b + 1, b + n + 1) - b - 1;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + Cntn + 1, a[i]) - b;
    ++Cnt[a[i]];
  }
  for (register unsigned i(1); i <= n; ++i) {
    Cnt[i] += Cnt[i - 1];
  }
  for (register unsigned i(1); i <= n; ++i) {
    Pos[Cnt[a[i]]--] = i;
  }
  for (register unsigned i(1), j(1), Last(0); i <= n; ++i) {
    if(i > Pos[j + 1]) {Last = j;}
    while (i > Pos[j + 1]) {++j;}
    A = a[Pos[i]];
    Add(Order[Last], Order[j], 1, n);
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!(Order[i])) Order[i] = Order[i - 1];
  }
  m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    
  }
//  }
  return Wild_Donkey;
}

