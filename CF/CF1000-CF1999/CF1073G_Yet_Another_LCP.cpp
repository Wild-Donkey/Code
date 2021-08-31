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
inline const char cmp(const unsigned& x, const unsigned& y) { return SA[x] < SA[y]; }
unsigned Height[200005], SA[200005], RK[200005], m, n, SzA, SzB, A[200005], B[200005], C, D, t, Ans(0), Tmp(0);
char a[200005];
struct Node {
  Node* LS, * RS;
  unsigned Sum, Cnt;
  void Udt() {
    this->Sum = this->LS->Sum + this->RS->Sum;
    this->Cnt = this->LS->Cnt + this->RS->Cnt;
  }
  void Build(unsigned L, unsigned R) {
    if (L == R) {
      return;
    }
    register unsigned Mid((L + R) >> 1);
    (x->LS = ++CntN)->Build(L, Mid);
    (x->RS = ++CntN)->Build(Mid + 1, R);
    x->Udt();
  }
  void Add(unsigned L, unsigned R) {
    if (L == R) {

    }
    return;
  }
}N[400005], * CntN(N);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  scanf("%s", a + 1);
  for (register unsigned i(1); i <= n; i <<= 1) {

  }
  for (register unsigned i(n); i; --i)
    Height[SA[i]] = ((a[i] ^ a[SA[RK[i] - 1]]) ? 0 : Height[SA[i + 1]] + 1);
  for (register unsigned i(1); i <= m; ++i) {
    SzA = RD(), SzB = RD();
    for (register unsigned i(1); i <= SzA; ++i) A[i] = RD();
    for (register unsigned i(1); i <= SzB; ++i) B[i] = RD();
    sort(A + 1, A + SzA + 1, cmp);
    sort(B + 1, B + SzB + 1, cmp);
    for (register unsigned i(1), j(1); i <= SzA, j <= SzB;) {
      if () {
        Add();
      }
      else {

      }
    }
  }
  //  system("pause");
  return Wild_Donkey;
}