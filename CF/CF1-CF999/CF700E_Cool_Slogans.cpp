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
unsigned m, n, Cnt(0), Final, A, B, C, D, t, Ans(0), Tmp(0);
char aP[200005], * a(aP);
struct Seg {
  Seg* LS, * RS;
  char Val;
}S[10000005], * CntS(S);
void Insert(Seg* x, unsigned L, unsigned R) {
  x->Val = 1;
  if (L == R) { x->Val = 1; return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) Insert(x->LS = ++CntS, L, Mid);
  else Insert(x->RS = ++CntS, Mid + 1, R);
}
void Qry(Seg* x, unsigned L, unsigned R) {
  // printf("Qry %u [%u, %u] LS %u RS %u\n", x - S, L, R, x->LS - S, x->RS - S);
  if ((A <= L) && (R <= B)) { Ans |= x->Val;  return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) if (x->LS) Qry(x->LS, L, Mid);
  if (B > Mid) if (x->RS) Qry(x->RS, Mid + 1, R);
}
Seg* Merge(Seg* x, Seg* y, unsigned L, unsigned R) {
  // printf("Merge %u<-%u [%u, %u]\n", x - S, y - S, L, R);
  unsigned Mid((L + R) >> 1);
  if (y->LS) {
    if (x->LS) { if (x->LS < x) *(++CntS) = *(x->LS), x->LS = CntS; x->LS = Merge(x->LS, y->LS, L, Mid); }
    else x->LS = ++CntS, * CntS = *(y->LS);
  }
  if (y->RS) {
    if (x->RS) { if (x->RS < x) *(++CntS) = *(x->RS), x->RS = CntS; x->RS = Merge(x->RS, y->RS, Mid + 1, R); }
    else x->RS = ++CntS, * CntS = *(y->RS);
  }
  if (x->LS) x->Val |= x->LS->Val;
  if (x->RS) x->Val |= x->RS->Val;
  return x;
}
struct Node {
  Node* Fa[18], * Bro, * Son, * To[26];
  Seg* Root;
  unsigned Len, Right, f;
}N[400005], * CntN(N), * Last(N);
void Add(const char x) {
  // printf("Add %c Last %u\n", x + 'a', Last - N);
  Last->To[x] = ++CntN, CntN->Len = Last->Len + 1;
  Node* Back(Last->Fa[0]);
  Last = CntN;
  while (Back) {
    if (Back->To[x]) { break; }
    Back->To[x] = Last;
    Back = Back->Fa[0];
  }
  // printf("Add %c Back %u\n", x + 'a', Back - N);
  if (!Back) Last->Fa[0] = N;
  else {
    // printf("Back->To[%c] = %u (%u == %u)? \n", x + 'a', Back->To[x] - N, Back->Len, Back->To[x]->Len);
    if (Back->To[x]->Len == Back->Len + 1) Last->Fa[0] = Back->To[x];
    else {
      Node* Bfr(Back->To[x]);
      (++CntN)->Fa[0] = Bfr->Fa[0], CntN->Len = Back->Len + 1, Bfr->Fa[0] = CntN, Last->Fa[0] = CntN;
      // printf("%u 's Fa %u, %u 's Fa %u, %u 's Fa %u Back->Len %u, CntN->Len %u\n", CntN - N, CntN->Fa[0] - N, Bfr - N, Bfr->Fa[0] - N, Last - N, Last->Fa[0] - N, Back->Len, CntN->Len);
      memcpy(CntN->To, Bfr->To, sizeof(Bfr->To));
      while (Back) {
        if (Back->To[x] == Bfr) Back->To[x] = CntN;
        else break;
        Back = Back->Fa[0];
      }
    }
  }
}
void DFS1(Node* x) {
  Node* Now(x->Son);
  if (!(x->Root)) x->Root = ++CntS;
  while (Now) {
    for (char i(0); Now->Fa[i]; ++i) Now->Fa[i + 1] = Now->Fa[i]->Fa[i];
    DFS1(Now);
    x->Root = Merge(x->Root, Now->Root, 1, n);
    x->Right = max(x->Right, Now->Right);
    Now = Now->Bro;
  }
}
void DFS2(Node* x) {
  // printf("Node %u Len %u Right %u Root %u Fa0 %u\n", x - N, x->Len, x->Right, x->Root - S, x->Fa[0] - N);
  Node* Now(x->Son), * Jump(x);
  for (char i(17); i >= 0; --i) {
    if (Jump->Fa[i] > N) {
      Ans = 0, A = x->Right - x->Len + Jump->Fa[i]->Fa[0]->Len + 1, B = x->Right - 1, Qry(Jump->Fa[i]->Root, 1, n);
      // printf("Qry [%u, %u]\n", A, B);
      if (!Ans) Jump = Jump->Fa[i];
    }
  }
  // printf("Now Jump %u\n", Jump - N);
  if (Jump->Fa[0]) Final = max(Final, x->f = Jump->Fa[0]->f + 1);
  // printf("This F %u\n", x->f);
  while (Now) {
    DFS2(Now);
    Now = Now->Bro;
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  fread(a + 1, 1, n + 3, stdin);
  while (a[1] < 'a') ++a;
  for (unsigned i(1); i <= n; ++i) Add(a[i] -= 'a'), A = i, Insert(Last->Root = ++CntS, 1, n), Last->Right = i;
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fa[0]->Son, i->Fa[0]->Son = i;
  DFS1(N), DFS2(N);
  printf("%u\n", Final);
  //   system("pause");
  return Wild_Donkey;
}
/*
6
cababa
*/