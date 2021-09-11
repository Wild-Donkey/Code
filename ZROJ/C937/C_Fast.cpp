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
unsigned m, n, A, B, C, D, t, Ans(0), Tmp(0), NofS;
unsigned CntE(0), CntD(0), Pos[100005];
char a[300005], NowC;
struct Edit {
  unsigned Nid, Opt;
}E[1200005];
struct Seg {
  Seg* LS, * RS;
  unsigned long long DiCnt2, DiCnt, Di;
  unsigned TagofPCnt;
}S[1200005], * CntS(S);
void PsDw(Seg* x) {
  if (x->TagofPCnt) {
    unsigned long long Sq(x->TagofPCnt * x->TagofPCnt);
    (x->LS->TagofPCnt) += x->TagofPCnt, (x->RS->TagofPCnt) += x->TagofPCnt;
    x->LS->DiCnt2 += ((x->LS->DiCnt << 1) * x->TagofPCnt) + Sq * x->LS->Di;
    x->RS->DiCnt2 += ((x->RS->DiCnt << 1) * x->TagofPCnt) + Sq * x->RS->Di;
    x->LS->DiCnt += x->LS->Di * x->TagofPCnt;
    x->RS->DiCnt += x->RS->Di * x->TagofPCnt;
    x->TagofPCnt = 0;
  }
}
void PsUp(Seg* x) {
  x->DiCnt2 = x->LS->DiCnt2 + x->RS->DiCnt2;
  x->DiCnt = x->LS->DiCnt + x->RS->DiCnt;
  x->Di = x->LS->Di + x->RS->Di;
}
void Build(Seg* x, unsigned L, unsigned R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid), Build(x->RS = ++CntS, Mid + 1, R);
}
void ChgCnt(Seg* x, unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) { x->DiCnt2 += (x->DiCnt << 1) + x->Di, x->DiCnt += x->Di, ++(x->TagofPCnt);return; }
  unsigned Mid((L + R) >> 1);
  PsDw(x);
  if (A <= Mid) ChgCnt(x->LS, L, Mid);
  if (Mid < B) ChgCnt(x->RS, Mid + 1, R);
  PsUp(x);
}
void ChgDif(Seg* x, unsigned L, unsigned R) {
  if (L == R) { x->DiCnt = x->TagofPCnt * B, x->DiCnt2 = x->TagofPCnt * x->DiCnt, x->Di = B;return; }
  unsigned Mid((L + R) >> 1);
  PsDw(x);
  if (A <= Mid) ChgDif(x->LS, L, Mid);
  else ChgDif(x->RS, Mid + 1, R);
  PsUp(x);
}
struct Node {
  Node* To[26], * Fail, * Son, * Bro, * Heavy, * Top;
  unsigned Len, DFSr, Size;
}N[600005], * CntN(N), * Last(N);
void Add() {
  register Node* Back(Last);
  if (Back->To[NowC]) {
    if (Back->To[NowC]->Len == Back->Len + 1) Last = Back->To[NowC];
    else {
      Node* Bfr(Back->To[NowC]);
      *(Last = ++CntN) = *Bfr, Last->Len = Back->Len + 1, Bfr->Fail = Last;
      E[++CntE].Nid = Bfr - N, E[CntE].Opt = Bfr->Len - Last->Len;
      E[++CntE].Nid = Last - N, E[CntE].Opt = Last->Len - Last->Fail->Len;
      while (Back && (Back->To[NowC] == Bfr)) Back->To[NowC] = Last, Back = Back->Fail;
    }
    return;
  }
  Last = ++CntN, Last->Len = Back->Len + 1;
  while (Back && (!(Back->To[NowC])))  Back->To[NowC] = Last, Back = Back->Fail;
  if (Back) {
    if ((Back->To[NowC]->Len) ^ (Back->Len + 1)) {
      Node* Bfr(Back->To[NowC]);
      *(++CntN) = *Bfr, CntN->Len = Back->Len + 1, Bfr->Fail = Last->Fail = CntN;
      E[++CntE].Nid = Bfr - N, E[CntE].Opt = Bfr->Len - CntN->Len;
      E[++CntE].Nid = Last - N, E[CntE].Opt = Last->Len - CntN->Len;
      E[++CntE].Nid = CntN - N, E[CntE].Opt = CntN->Len - CntN->Fail->Len;
      while (Back && (Back->To[NowC] == Bfr)) Back->To[NowC] = CntN, Back = Back->Fail;
    }
    else Last->Fail = Back->To[NowC], E[++CntE].Nid = Last - N, E[CntE].Opt = Last->Len - Last->Fail->Len;
  }
  else Last->Fail = N, E[++CntE].Nid = Last - N, E[CntE].Opt = Last->Len;
}
void ChgAp(Node* x) {
  while (x) A = x->Top->DFSr, B = x->DFSr, ChgCnt(S, 1, NofS), x = x->Top->Fail;
}
void PreDFS(Node* x) {
  Node* Now(x->Son);
  unsigned Mx(0);
  x->Size = 1;
  while (Now) {
    PreDFS(Now);
    x->Size += Now->Size;
    if (Now->Size > Mx) x->Heavy = Now, Mx = Now->Size;
    Now = Now->Bro;
  }
  return;
}
void DFS(Node* x) {
  x->DFSr = ++CntD;
  if (!(x->Heavy)) return;
  Node* Now(x->Son);
  x->Heavy->Top = x->Top, DFS(x->Heavy);
  while (Now) {
    if (Now != x->Heavy) { Now->Top = Now, DFS(Now); }
    Now = Now->Bro;
  }
  return;
}
int main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1), j(1); i <= n; ++i, j = 1, Last = N) {
    scanf("%s", a + 1);
    while (a[j] < 'a') ++j;
    while (a[j] >= 'a') NowC = a[j] -= 'a', Add(), a[j++] = 0, E[++CntE].Nid = Last - N, E[CntE].Opt = 0;
    Pos[i] = CntE;
  }
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fail->Son, i->Fail->Son = i;
  N->Top = N, PreDFS(N), DFS(N), NofS = CntN - N + 1, Build(S, 1, NofS);
  for (unsigned i(1), j(1); i <= n; ++i) {
    for (;j <= Pos[i]; ++j) {
      if (E[j].Opt) A = N[E[j].Nid].DFSr, B = E[j].Opt, ChgDif(S, 1, NofS);
      else ChgAp(N + E[j].Nid);
    }
    printf("%llu\n", S->DiCnt2);
  }
  system("pause");
  return Wild_Donkey;
}
/*
1
diana
*/