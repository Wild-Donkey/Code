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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
struct Juice {
  unsigned Val, Cost, Limit;
  inline const char  operator< (const Juice* x)const {
    return this->Val < x->Val;
  }
}J[100005];
struct Node {
  Node* LS, * RS;
  unsigned Val, Cost;
}N[4000005], * Root[100005], * CntN(N);
void Add(Node* x, Node* y, unsigned L, unsigned R) {
  if (L == R) {
    y->Val = J[L].Cost * J[L].Limit;
    y->Cost = J[L].Cost;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  y->Val = 0;
  if (x) y->Val += x->Val;
  if (A <= Mid) {
    if (x) {

    }
  }
  else {
    if (x) {

    }
  }
}
void Qry() {

}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    J[i].Val = RD(), J[i].Cost = RD(), J[i].Limit = RD();
  }
  sort(J + 1, J + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    Add(Root[i - 1], Root[i] = ++CntN, 1, n);
  }
  for (register unsigned i(1); i <= m; ++i) {

  }
  //  system("pause");
  return Wild_Donkey;
}