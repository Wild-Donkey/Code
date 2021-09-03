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
unsigned m, n, Cnt(0), A, B, C, D, Ans(0), QrL, QrR;
char aP[100005], * a(aP), Tmp(0);
struct Seg {
  Seg* LS, * RS;
  char Val;
}S[10000005], * CntS(S);
void Insert(Seg* x, unsigned L, unsigned R) {
  // printf("Insert %u to %u [%u, %u]\n", A, x - S, L, R);
  x->Val = 1;
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) Insert(x->LS = ++CntS, L, Mid);
  else Insert(x->RS = ++CntS, Mid + 1, R);
}
void Qry(Seg* x, unsigned L, unsigned R) {
  // printf("Qry %u [%u, %u] Val %u\n", x - S, L, R, x->Val);
  if ((QrL <= L) && (R <= QrR)) { /*printf("Leaf [%u %u]\n", L, R); */Tmp |= x->Val;  return; }
  unsigned Mid((L + R) >> 1);
  if ((QrL <= Mid) && (x->LS)) Qry(x->LS, L, Mid);
  if ((Mid < QrR) && (x->RS)) Qry(x->RS, Mid + 1, R);
}
void Merge(Seg* x, Seg* y, unsigned L, unsigned R) {
  // printf("Merge %u <- %u [%u, %u]\n", x - S, y - S, L, R);
  unsigned Mid((L + R) >> 1);
  if (y->LS) {
    if (x->LS) *(++CntS) = *(x->LS), x->LS = CntS, Merge(CntS, y->LS, L, Mid);
    else x->LS = ++CntS, * (CntS) = *(y->LS);
  }
  if (y->RS) {
    if (x->RS) *(++CntS) = *(x->RS), x->RS = CntS, Merge(CntS, y->RS, Mid + 1, R);
    else x->RS = ++CntS, * (CntS) = *(y->RS);
  }
  if (x->LS) x->Val |= x->LS->Val;
  if (x->RS) x->Val |= x->RS->Val;
}
struct Node {
  Node* To[26], * Son, * Bro, * Fa[17];
  Seg* Root;
  unsigned Len;
}N[200005], * CntN(N), * Last(N), * Pos[100005];
void Add(const char x) {
  // printf("Add %c After %u\n", x + 'a', Last - N);
  (++CntN)->Len = Last->Len + 1;
  Node* Back(Last);
  Last = CntN;
  while (Back) {
    if (!(Back->To[x])) Back->To[x] = Last;
    else break;
    Back = Back->Fa[0];
  }
  // printf("Jumped %u\n", Back - N);
  if (!Back) Last->Fa[0] = N;
  else {
    if (Back->Len + 1 == Back->To[x]->Len) Last->Fa[0] = Back->To[x];
    else {
      Node* Bfr(Back->To[x]);
      *(++CntN) = *Bfr, Bfr->Fa[0] = CntN, Last->Fa[0] = CntN, CntN->Len = Back->Len + 1, CntN->Root = NULL;
      while (Back) {
        if (Back->To[x] == Bfr) Back->To[x] = CntN;
        else break;
        Back = Back->Fa[0];
      }
    }
  }
}
void DFS(Node* x) {
  // printf("Node %u Len %u Fa %u\n", x - N, x->Len, x->Fa[0] - N);
  Node* Now(x->Son);
  // printf("%u:%u CntS %u\n", x - N, x->Root - S, CntS - S);
  if (!(x->Root)) x->Root = ++CntS;
  // printf("%u:%u CntS %u\n", x - N, x->Root - S, CntS - S);
  while (Now) {
    for (int i = 0; (Now->Fa[i]) && (i <= 16); ++i) Now->Fa[i + 1] = Now->Fa[i]->Fa[i];
    DFS(Now);
    // printf("Merge %u:%u <- %u:%u\n", x - N, x->Root - S, Now - N, Now->Root - S);
    Merge(x->Root, Now->Root, 1, n);
    Now = Now->Bro;
  }
}
signed main() {
  freopen("P3975_21.in", "r", stdin);
  freopen("P3975.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), scanf("%s", a + 1), Pos[0] = N;
  while (a[1] < 'a') ++a;
  for (unsigned i(1); i <= n; ++i) Add(a[i] -= 'a'), Pos[i] = Last, A = i, /*printf("Insert %u to %u\n", i, Last - N),*/ Insert(Last->Root = ++CntS, 1, n);
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fa[0]->Son, i->Fa[0]->Son = i;
  DFS(N);
  for (unsigned i(1); i <= m;++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    unsigned BL(1), BR(min(D - C + 1, B - A + 1)), BMid;
    while (BL ^ BR) {
      BMid = (BL + BR + 1) >> 1;
      // printf("[%u, %u] Mid %u\n", BL, BR, BMid);
      Node* Jump(Pos[C + BMid - 1]);
      for (char i(16); i >= 0; --i) if ((Jump->Fa[i]) && (Jump->Fa[i]->Len >= BMid)) Jump = Jump->Fa[i];
      // printf("Jump %u Len %u Need %u\n", Jump - N, Jump->Len, BMid);
      // if (Jump->Fa[0]) printf("Jump more %u %u\n", Jump->Fa[0] - N, Jump->Fa[0]->Len);
      Tmp = 0, QrL = A + BMid - 1, QrR = B, Qry(Jump->Root, 1, n);
      // printf("Qry [%u, %u] Got %u\n", QrL, QrR, Tmp);
      if (Tmp) BL = BMid;
      else BR = BMid - 1;
    }
    printf("%u\n", BL);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
6 3
banana
1 4 5 6
1 4 3 6
1 6 2 6

2
2
5
*/