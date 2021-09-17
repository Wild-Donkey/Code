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
}S[5000005], * CntS(S);
void Insert(Seg* x, unsigned L, unsigned R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) Insert(x->LS = ++CntS, L, Mid);
  else Insert(x->RS = ++CntS, Mid + 1, R);
}
void Qry(Seg* x, unsigned L, unsigned R) {
  if ((QrL <= L) && (R <= QrR)) { Tmp |= 1;  return; }
  unsigned Mid((L + R) >> 1);
  if ((QrL <= Mid) && (x->LS)) Qry(x->LS, L, Mid);
  if (Tmp) return;
  if ((Mid < QrR) && (x->RS)) Qry(x->RS, Mid + 1, R);
}
void Merge(Seg* x, Seg* y, unsigned L, unsigned R) {
  unsigned Mid((L + R) >> 1);
  if (y->LS) {
    if (x->LS) *(++CntS) = *(x->LS), x->LS = CntS, Merge(CntS, y->LS, L, Mid);
    else x->LS = y->LS;
  }
  if (y->RS) {
    if (x->RS) *(++CntS) = *(x->RS), x->RS = CntS, Merge(CntS, y->RS, Mid + 1, R);
    else x->RS = y->RS;
  }
}
struct Node {
  Node* To[26], * Son, * Bro, * Fa[16];
  Seg* Root;
  unsigned Len;
}N[200005], * CntN(N), * Last(N), * Pos[100005];
void Add(const char x) {
  (++CntN)->Len = Last->Len + 1;
  Node* Back(Last);
  Last = CntN;
  while (Back) {
    if (!(Back->To[x])) Back->To[x] = Last;
    else break;
    Back = Back->Fa[0];
  }
  if (!Back) Last->Fa[0] = N;
  else {
    if (Back->Len + 1 == Back->To[x]->Len) Last->Fa[0] = Back->To[x];
    else {
      Node* Bfr(Back->To[x]);
      /*注意这里, Root 也会被复制, 要记得清除, 调了一上午的教训*/
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
  Node* Now(x->Son);
  if (!(x->Root)) x->Root = ++CntS;
  while (Now) {
    for (int i = 0; Now->Fa[i]; ++i) Now->Fa[i + 1] = Now->Fa[i]->Fa[i];
    DFS(Now);
    Merge(x->Root, Now->Root, 1, n);
    Now = Now->Bro;
  }
}
signed main() {
  // freopen("P3975_21.in", "r", stdin);
  // freopen("P3975.out", "w", stdout);
  n = RD(), m = RD(), scanf("%s", a + 1), Pos[0] = N;
  while (a[1] < 'a') ++a;
  for (unsigned i(1); i <= n; ++i) Add(a[i] -= 'a'), Pos[i] = Last, A = i, Insert(Last->Root = ++CntS, 1, n);
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fa[0]->Son, i->Fa[0]->Son = i;
  DFS(N);
  for (unsigned i(1); i <= m;++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    unsigned BL(1), BR(min(D - C + 1, B - A + 1)), BMid;
    while (BL ^ BR) {
      BMid = (BL + BR + 1) >> 1;
      Node* Jump(Pos[C + BMid - 1]);
      for (char i(15); i >= 0; --i) if ((Jump->Fa[i]) && (Jump->Fa[i]->Len >= BMid)) Jump = Jump->Fa[i];
      Tmp = 0, QrL = A + BMid - 1, QrR = B, Qry(Jump->Root, 1, n);
      if (Tmp) BL = BMid;
      else BR = BMid - 1;
    }
    printf("%u\n", BL);
  }
  // system("pause");
  return Wild_Donkey;
}