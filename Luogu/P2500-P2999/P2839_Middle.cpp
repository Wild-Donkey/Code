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
unsigned a[20005], b[20005], Pos[20005], Cnt[20005], Ask[4];
unsigned m, n, Cntn, A, B, C, D, t, Tmp(0), Last(0);
int QrySum, LMin, RMax;
char QryMin(0);
struct Node {
  Node* LS, * RS;
  int Max, Min, Tag;
}N[10000005], * Order[20005], * CntN(N), * Lst(N);
void Udt(Node* x) {
  x->Max = x->Tag + max(x->LS->Max, x->RS->Max);
  x->Min = x->Tag + min(x->LS->Min, x->RS->Min);
}
void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) {
    x->Max = x->Min = -L;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  Udt(x);
}
Node* Add(Node* x, Node* y, unsigned L, unsigned R) {
  if (A <= L) {
    if (y > Lst) {
      y->Tag += 2;
      y->Max += 2;
      y->Min += 2;
    }
    else {
      y = ++CntN;
      y->Tag = x->Tag + 2;
      y->Max = x->Max + 2;
      y->Min = x->Min + 2;
      y->LS = x->LS;
      y->RS = x->RS;
    }
    return y;
  }
  register unsigned Mid((L + R) >> 1);
  if (y <= Lst) y = ++CntN, y->Tag = x->Tag, y->LS = x->LS, y->RS = x->RS;
  if (!(y->LS)) y->LS = x->LS;
  if (A <= Mid) y->LS = Add(x->LS, y->LS, L, Mid);
  y->RS = Add(x->RS, y->RS, Mid + 1, R);
  Udt(y);
  return y;
}
void Qry(Node* x, unsigned L, unsigned R, int TagSum) {
  if ((A <= L) && (R <= B)) {
    if (QryMin) QrySum = min(QrySum, TagSum + x->Min);
    else QrySum = max(QrySum, TagSum + x->Max);
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if (A <= Mid) Qry(x->LS, L, Mid, TagSum + x->Tag);
  if (B > Mid) Qry(x->RS, Mid + 1, R, TagSum + x->Tag);
}
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = b[i] = RD();
  sort(b + 1, b + n + 1);
  Cntn = unique(b + 1, b + n + 1) - b - 1;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + Cntn + 1, a[i]) - b;
    ++Cnt[a[i]];
    // printf("a[%u] = %u\n", i, a[i]);
  }
  for (register unsigned i(1); i <= Cntn; ++i) Cnt[i] += Cnt[i - 1];
  for (register unsigned i(1); i <= n; ++i) Pos[Cnt[a[i]]--] = i;
  // printf("All %u\n", Cntn);
  Build(Order[Cntn + 1] = ++CntN, 0, n), Cnt[Cntn + 1] = n;
  for (register unsigned i(Cntn); i; --i) {
    Lst = CntN, Order[i] = ++CntN;
    for (register unsigned j(Cnt[i + 1]); j >= Cnt[i] + 1; --j)
      A = Pos[j], Add(Order[i + 1], Order[i], 0, n);
  }
  // for (register unsigned i(1); i <= n; ++i) {
  //   printf("Pos[%u] = %u\n", i, Pos[i]);
  // }
  m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    for (register unsigned j(0); j < 4; ++j) Ask[j] = 1 + ((RD() + Last) % n);
    sort(Ask, Ask + 4);
    register unsigned BL(1), BR(Cntn), BMid;
    while (BL ^ BR) {
      BMid = (BL + BR + 1) >> 1;
      QryMin = 1, A = Ask[0] - 1, B = Ask[1] - 1, QrySum = 0x3f3f3f3f, Qry(Order[BMid], 0, n, 0);
      QryMin = 0, LMin = QrySum, QrySum = 0xafafafaf, A = Ask[2], B = Ask[3], Qry(Order[BMid], 0, n, 0);
      // printf("[%u, %u] Qry %u Got RMax %d LMin %d\n", BL, BR, BMid, QrySum, LMin);
      if (QrySum >= LMin) BL = BMid;
      else BR = BMid - 1;
    }
    Last = b[BL], printf("%u\n", Last);
  }
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
10
8 7 8 7 6 7 6 8 9 9
3
3 1 0 2
2 3 1 4
3 1 4 0

1 2 3 4
1 2 10 3
1 2 3 10
2 10 3 9
2 3 9 10
*/