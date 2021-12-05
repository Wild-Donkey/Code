#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline unsigned RD() {
  unsigned RTmp(0);
  char Rch(getchar());
  while (Rch < '0' || Rch > '9') Rch = getchar();
  while (Rch >= '0' && Rch <= '9') RTmp = (RTmp << 3) + (RTmp << 1) + Rch - '0', Rch = getchar();
  return RTmp;
}
const unsigned Mod(998244353);
unsigned n, m, t, Ans(0), Mx;
unsigned STop(0), Fist[1000005], HTop(0);
unsigned A, B, C, D;
struct Node {
  Node* LS, * RS;
  unsigned Tag, Val[30];
  inline void PsDw() {
    LS->Tag += Tag;
    RS->Tag += Tag;
    for (unsigned i(Tag); i < 30; ++i) LS->Val[i - Tag] = LS->Val[i];
    for (unsigned i(Tag); i < 30; ++i) RS->Val[i - Tag] = RS->Val[i];
    if(Tag > 30) memset(LS->Val, 0, 120), memset(RS->Val, 0, 120);
    else for (unsigned i(30 - Tag); i < 30; ++i) LS->Val[i] = RS->Val[i] = 0;
    Tag = 0;
  }
}N[2000005], His[10000005], *HisP[10000005], * CntN(N), * Now(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) {
    x->Val[0] = RD();
    if(x->Val[0] >= Mod) x->Val[0] -= Mod;
    for (unsigned i(0); x->Val[i]; ++i) x->Val[i + 1] = (x->Val[i] & (x->Val[i] >> 1));
    return;
  }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  for (unsigned i(0); i < 30; ++i) {x->Val[i] = x->LS->Val[i] + x->RS->Val[i]; if(x->Val[i] >= Mod) x->Val[i] -= Mod;}
}
inline void Pls(Node* x, unsigned L, unsigned R) {
//  printf("Edit [%u %u]\n", L, R);
  if(A <= L && R <= B) {
    His[++HTop] = *x, HisP[HTop] = x, ++(x->Tag);
    for (unsigned i(1); i < 30; ++i) x->Val[i - 1] = x->Val[i];
    x->Val[29] = 0;
//    printf("%u\n", x->Val[0]);
    return;
  }
  unsigned Mid((L + R) >> 1);
  His[++HTop] = *(x->LS), HisP[HTop] = x->LS;
  His[++HTop] = *(x->RS), HisP[HTop] = x->RS;
  if(x->Tag) {
    His[++HTop] = *(x->LS), HisP[HTop] = x->LS;
    His[++HTop] = *(x->RS), HisP[HTop] = x->RS;
    x->PsDw();
    if(A <= Mid) Pls(x->LS, L, Mid);
    if(B > Mid) Pls(x->RS, Mid + 1, R);
  }
  else {
    if(A <= Mid) His[++HTop] = *(x->LS), HisP[HTop] = x->LS, Pls(x->LS, L, Mid);
    if(B > Mid) His[++HTop] = *(x->RS), HisP[HTop] = x->RS, Pls(x->RS, Mid + 1, R);
  }
  for (unsigned i(0); i < 30; ++i) {x->Val[i] = x->LS->Val[i] + x->RS->Val[i]; if(x->Val[i] >= Mod) x->Val[i] -= Mod;}
}
inline void Find(Node* x, unsigned L, unsigned R) {
//  printf("Find [%u %u]\n", L, R);
  if(A <= L && R <= B) {
    Ans += x->Val[0];
    if(Ans >= Mod) Ans -= Mod;
//    printf("Found %u\n", x->Val[0]);
    return;
  }
  unsigned Mid((L + R) >> 1);
  if(x->Tag) {
    His[++HTop] = *(x->LS), HisP[HTop] = x->LS;
    His[++HTop] = *(x->RS), HisP[HTop] = x->RS;
    x->PsDw();
    if(A <= Mid) Find(x->LS, L, Mid);
    if(B > Mid) Find(x->RS, Mid + 1, R);
  }
  else {
    if(A <= Mid) His[++HTop] = *(x->LS), HisP[HTop] = x->LS, Find(x->LS, L, Mid);
    if(B > Mid) His[++HTop] = *(x->RS), HisP[HTop] = x->RS, Find(x->RS, Mid + 1, R);
  }
}
signed main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  n = RD(), m = RD(), Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    D = RD();
//    for (unsigned j(0); j < 30; ++j) printf("%u %u\n", j, N[0].Val[j]);
    switch (D) {
      case(1): {
        A = RD(), B = RD();
        if(A > B) { Fist[++STop] = HTop + 1; break; }
        HisP[Fist[++STop] = ++HTop] = N, His[HTop] = N[0], Pls(N, 1, n);
        break;
      }
      case(2): {
        A = RD(), B = RD();
        if(A > B) {printf("0\n");break;}
        Ans = 0, Find(N, 1, n), printf("%u\n", Ans);
        break;
      }
      case(3): {
        for (; HTop >= Fist[STop]; --HTop) *(HisP[HTop]) = His[HTop];
        --STop;
        break;
      }
    }
    Mx = max(Mx, HTop);
  }
  fprintf(stderr, "HTopMx %u\n", Mx);
  return 0;
}
/*
10 2
2 6 14 11 9 2 13 5 5 1 
1 4 8
2 5 7
*/
