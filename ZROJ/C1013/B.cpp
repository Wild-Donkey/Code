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
#include <string>
#include <vector>
#define Wild_Donkey 0
#define Rsid 10000000000000
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long A, B, m, Ans(0);
unsigned n, t;
struct Node {
  Node* LS, * RS;
  unsigned long long Ml, Mr;
  unsigned Tag, Mx;
}N[12000005], * CntN(N);
inline void Clr() {
  Ans = n = RD(), m = RDll();
  CntN = N, N->Ml = 1, N->Mr = Rsid, N->Mx = N->Tag = 0, N->LS = N->RS = NULL;
}
inline void PsDw (Node* x, unsigned long long L, unsigned long long R, unsigned long long Mid) {
  if(x->Tag) {
    if(!(x->LS)) {
      x->LS = ++CntN, x->LS->Mx = x->LS->Tag = x->Tag;
      x->LS->Ml = L, x->LS->Mr = Mid, x->LS->LS = x->LS->RS = NULL;
    }
    else x->LS->Mx += x->Tag, x->LS->Tag += x->Tag;
    if(!(x->RS)) {
      x->RS = ++CntN, x->RS->Mx = x->RS->Tag = x->Tag;
      x->RS->Ml = Mid + 1, x->RS->Mr = R, x->RS->LS = x->RS->RS = NULL;
    }
    else x->RS->Mx += x->Tag, x->RS->Tag += x->Tag;
    x->Tag = 0;
  } else {
    if(!(x->LS)) {
      x->LS = ++CntN, x->LS->Mx = x->LS->Tag = 0;
      x->LS->Ml = L, x->LS->Mr = Mid, x->LS->LS = x->LS->RS = NULL;
    }
    if(!(x->RS)) {
      x->RS = ++CntN, x->RS->Mx = x->RS->Tag = 0;
      x->RS->Ml = Mid + 1, x->RS->Mr = R, x->RS->LS = x->RS->RS = NULL;
    }
  }
}
inline void Udt(Node* x, unsigned long long L, unsigned long long R, unsigned long long Mid) {
  x->Mx = max(x->LS->Mx, x->RS->Mx);
  if(x->LS->Mx == x->RS->Mx) {
    if((x->LS->Mr == Mid) && (x->RS->Ml == Mid + 1)) x->Ml = x->LS->Ml, x->Mr = x->RS->Mr;
    else x->Ml = x->LS->Ml, x->Mr = x->LS->Mr;
  } else {
    if(x->LS->Mx < x->RS->Mx) x->Ml = x->RS->Ml, x->Mr = x->RS->Mr;
    else x->Ml = x->LS->Ml, x->Mr = x->LS->Mr;
  }
}
inline void Ins (Node* x, unsigned long long L, unsigned long long R) {
//  printf("Ins [%llu %llu] at %u\n", L, R, x - N);
  if((A <= L) && (R <= B)) {
//    printf("Tag\n");
    ++(x->Tag), ++(x->Mx); return;
  }
  unsigned long long Mid((L + R) >> 1);
  PsDw(x, L, R, Mid);
  if(A <= Mid) Ins(x->LS, L, Mid);
  if(B > Mid) Ins(x->RS, Mid + 1, R);
  Udt(x, L, R, Mid);
  return;
}
inline void Chg (Node* x, unsigned long long L, unsigned long long R) {
//  printf("Change[%llu, %llu] Mx %u [%llu, %llu] Tag %u\n", L, R, x->Mx, x->Ml, x->Mr, x->Tag); 
  if((A <= L) && (R <= B)) {x->Mx = 0; return;}
  unsigned long long Mid((L + R) >> 1);
  PsDw(x, L, R, Mid);
  if(A <= Mid) Chg(x->LS, L, Mid);
  if(B > Mid) Chg(x->RS, Mid + 1, R);
  Udt(x, L, R, Mid);
//  printf("Changed[%llu, %llu] Mx %u [%llu, %llu]\n", L, R, x->Mx, x->Ml, x->Mr);
  return;
}
signed main() {
//  freopen("B_1.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      A = RDll() + 1, B = RDll() - 1;
      if(A <= B) Ins(N, 1, Rsid);
    }
    while (m && (N->Mx)) {
      unsigned long long Len(min(m, N->Mr - N->Ml + 1));
//      printf("Dec %u Len %llu [%llu, %llu]\n", N->Mx, Len, N->Ml, N->Mr);
      Ans += N->Mx * Len, m -= Len;
      A = N->Ml, B = A + Len - 1, Chg(N, 1, Rsid);
//      printf("Change [%llu, %llu]\n", A, B);
    }
    printf("Case #%u: %llu\n", T, Ans);
//    printf("Pnts %u\n", CntN - N); 
  }
  return Wild_Donkey;
}
/*
4
3 100000000000000
10000 10000000000001
10 50000000001
400000000000 1000000000001
3 1
1 3
2 4
1 4
3 3
1 3
2 4
1 4
3 100000000000000
9999 10000000000001
9 50000000001
399999999999 1000000000001

*/
