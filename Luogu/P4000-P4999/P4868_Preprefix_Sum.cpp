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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned n, m, A;
long long a[100005], Sum[100005], B, C, Ans(0);
char Op[10];
struct Node {
  Node *LS, *RS;
  long long Val, Tag;
}N[200005], *CntN(N);
void PsDw(Node *x, unsigned Len) {
  if(x->Tag) {
    x->LS->Tag += x->Tag;
    x->LS->Val += x->Tag * ((Len + 1) >> 1);
    x->RS->Tag += x->Tag;
    x->RS->Val += x->Tag * (Len >> 1);
    x->Tag = 0;
  }
}
void Build(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->Val = Sum[L];
    return;
  }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Val = x->LS->Val + x->RS->Val;
  return;
}
void Chg(Node *x, unsigned L, unsigned R) {
  if(A <= L) {
    x->Tag += C;
    x->Val += (R - L + 1) * C;
    return;
  }
  PsDw(x, R - L + 1);
  register unsigned Mid((L + R) >> 1);
  Chg(x->RS, Mid + 1, R);
  if(Mid >= A) {
    Chg(x->LS, L, Mid);
  }
  x->Val = x->LS->Val + x->RS->Val;
}
void Qry(Node *x, unsigned L, unsigned R) {
  if(A >= R) {
    Ans += x->Val;
    return;
  }
  PsDw(x, R - L + 1);
  register unsigned Mid((L + R) >> 1);
  Qry(x->LS, L, Mid);
  if(Mid < A) {
    Qry(x->RS, Mid + 1, R);
  }
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + (a[i] = RD());
  Build(N, 1, n);
  for (register unsigned i(1); i <= m; ++i) {
    scanf("%s", &Op);
    if(Op[0] ^ 'Q') {
      A = RD(), B = RD();
//      printf("Chg %llu %llu << %llu\n", A, B, a[A]);
      C = B - a[A], a[A] = B;
//      printf("Chg %llu = %llu - a[i]\n", C, B);
      Chg(N, 1, n);
    } else {
      A = RD(), Ans = 0;
      Qry(N, 1, n);
      printf("%lld\n", Ans);
    }
  }
  return Wild_Donkey;
}
/*
5 3
1 2 3 4 5
Query 5
Modify 3 2
Query 4
*/
