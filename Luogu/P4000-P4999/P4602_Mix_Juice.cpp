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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned a[100005], m, n, Cnt(0), t, Ans(0), Tmp(0);
unsigned long long A, B, C, D;
struct Juice {
  unsigned Val, Cost, Limit;
  inline const char operator< (const Juice& x)const {
    return this->Val < x.Val;
  }
}J[100005];
struct Node {
  Node* LS, * RS;
  unsigned long long Cost, V;
}N[4000005], * Root[100005], * CntN(N);
void Udt(Node* x) {
  x->V = x->Cost = 0;
  if (x->LS) x->V += x->LS->V, x->Cost += x->LS->Cost;
  if (x->RS) x->V += x->RS->V, x->Cost += x->RS->Cost;
}
void Add(Node* x, Node* y, unsigned L, unsigned R) {
  if (L == R) {
    y->Cost = B * C;
    y->V = C;
    if (x) y->V += x->V, y->Cost += x->Cost;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if (A <= Mid) {
    if (x) {
      y->RS = x->RS;
      Add(x->LS, y->LS = ++CntN, L, Mid);
    }
    else {
      Add(NULL, y->LS = ++CntN, L, Mid);
    }
  }
  else {
    if (x) {
      y->LS = x->LS;
      Add(x->RS, y->RS = ++CntN, Mid + 1, R);
    }
    else {
      Add(NULL, y->RS = ++CntN, Mid + 1, R);
    }
  }
  return Udt(y);
}
void Qry(Node* x, unsigned L, unsigned R) {
  if (L == R) {
    C += A * x->Cost / x->V;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if (x->LS) {
    if (x->LS->V >= A) {
      return Qry(x->LS, L, Mid);
    }
    else {
      A -= x->LS->V;
      C += x->LS->Cost;
    }
  }
  Qry(x->RS, Mid + 1, R);
}
signed main() {
  // freopen("P4602_21.in", "r", stdin);
  // freopen("P4602.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Root[0] = N;
  for (register unsigned i(1); i <= n; ++i) {
    J[i].Val = RD(), a[i] = J[i].Cost = RD(), J[i].Limit = RD();
  }
  sort(J + 1, J + n + 1), sort(a + 1, a + n + 1), Cnt = unique(a + 1, a + n + 1) - a - 1;
  for (register unsigned i(n); i; --i)
    A = lower_bound(a + 1, a + Cnt + 1, J[i].Cost) - a, B = J[i].Cost, C = J[i].Limit, Add(Root[i + 1], Root[i] = ++CntN, 1, Cnt);
  for (register unsigned i(1); i <= m; ++i) {
    B = RD(), D = RD();
    register unsigned BL(0), BR(n), BMid;
    while (BL ^ BR) {
      BMid = (BL + BR + 1) >> 1, A = D, C = 0;
      // printf("[%u, %u], Mid %u\n", BL, BR, BMid);
      if (Root[BMid]->V < A) {
        BR = BMid - 1;
        continue;
      }
      Qry(Root[BMid], 1, Cnt);
      // printf("Cost %u\n", C);
      if (C > B) {
        BR = BMid - 1;
      }
      else {
        BL = BMid;
      }
    }
    if (!BL) printf("-1\n");
    else printf("%u\n", J[BL].Val);
  }
  // system("pause");
  return Wild_Donkey;
}