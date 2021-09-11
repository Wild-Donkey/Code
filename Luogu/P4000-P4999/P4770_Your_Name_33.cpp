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
unsigned long long LCS, Ans[100005], Tmp(0);
unsigned m, n, Cnt(0), B, C, D, t, Calc;
unsigned Pointer(0), Prefix[500005], DFSCnt(0);
char b[1000005], CTmp;
struct Ask {
  unsigned Frm, To, L, R, AsNum;
  inline const char operator <(const Ask& x) { return this->R < x.R; }
}A[100005];
struct Seg {
  Seg* LS, * RS;
  unsigned Mx;
}S[2000005], * CntS(S);
void Insert(Seg* x, unsigned L, unsigned R) {
  // printf("Insert %u at %u [%u, %u]\n", C, B, L, R);
  x->Mx = max(x->Mx, C);
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  if (B <= Mid) { if (!(x->LS)) x->LS = ++CntS; Insert(x->LS, L, Mid); }
  else { if (!(x->RS)) x->RS = ++CntS;  Insert(x->RS, Mid + 1, R); }
}
void Qry(Seg* x, unsigned L, unsigned R) {
  // printf("[%u, %u] %u at [%u, %u] LS %u, RS %u\n", B, C, x->Mx, L, R, x->LS - S, x->RS - S);
  if ((B <= L) && (R <= C)) D = max(D, x->Mx);
  unsigned Mid((L + R) >> 1);
  if ((B <= Mid) && (x->LS)) Qry(x->LS, L, Mid);
  if ((Mid < C) && (x->RS)) Qry(x->RS, Mid + 1, R);
}
struct Node {
  unsigned To[26], Fail, Len, DFSr, Son, Bro, Size;
}N[2000005], * CntN(N + 1), * Last, * DelLine, * Search, * Choice;
void Add() {
  Node* Back(Last);
  Last = ++CntN, CntN->Len = Back->Len + 1, memset(Last->To, 0, sizeof(Last->To));
  while ((Back > N) && (!(Back->To[CTmp]))) Back->To[CTmp] = Last - N, Back = N + Back->Fail;
  if (Back > N) {
    if ((N[Back->To[CTmp]].Len) ^ (Back->Len + 1)) {
      Node* Bfr(N + Back->To[CTmp]);
      *(++CntN) = *Bfr, CntN->Len = Back->Len + 1, Bfr->Fail = Last->Fail = CntN - N;
      while ((Back > N) && (Back->To[CTmp] == Bfr - N)) Back->To[CTmp] = CntN - N, Back = N + Back->Fail;
    }
    else Last->Fail = Back->To[CTmp];
  }
  else Last->Fail = DelLine - N;
}
void DFS(Node* x) {
  Node* Now(N + x->Son);
  x->DFSr = ++DFSCnt, x->Size = 1;
  while (Now > N) {
    DFS(Now), x->Size += Now->Size, Now = N + Now->Bro;
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  CTmp = getchar(), DelLine = Last = N + 1; while (CTmp < 'a') CTmp = getchar();
  while (CTmp >= 'a') CTmp -= 'a', Add(), Prefix[++n] = Last - N, CTmp = getchar();
  DelLine = N + Prefix[n] + 2, m = RD();
  for (unsigned i(1); i <= m; ++i) {
    CTmp = getchar(); while (CTmp < 'a') CTmp = getchar();
    A[i].Frm = Pointer + 1;
    while (CTmp >= 'a') b[++Pointer] = CTmp - 'a', CTmp = getchar();
    A[i].L = RD(), A[i].R = RD(), A[i].To = Pointer, A[i].AsNum = i;
  }
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = N[i->Fail].Son, N[i->Fail].Son = i - N;
  A[m + 1].R = A[m].R, sort(A + 1, A + m + 1), DFS(N + 1);
  for (unsigned i(1); i <= A[1].R; ++i) B = N[Prefix[i]].DFSr, C = i,/* printf("Insert %u to %u\n", C, B),*/ Insert(S, 1, Prefix[n] + 1);
  for (unsigned i(1); i <= m; ++i) {
    // printf("Ansering %u\n", A[i].AsNum);
    LCS = 0, Search = N + 1, Last = CntN = DelLine, *DelLine = *N, Tmp = 0, CntN->Len = 0;
    for (unsigned j(A[i].Frm); j <= A[i].To; ++j) {
      Calc = 0, Choice = NULL;
      while ((Search > N) && (Search->Len >= Calc)) {
        // printf("Search %u %u\n", Search - N, Search->Fail);
        if (Search->To[b[j]]) {
          B = N[Search->To[b[j]]].DFSr, C = B + N[Search->To[b[j]]].Size - 1, D = 0, Qry(S, 1, Prefix[n] + 1);
          // printf("Search->To[%c]->Len = %u D = %u\n", b[j] + 'a', N[Search->To[b[j]]].Len, D);
          if (D >= A[i].L + Search->Len - 1) {
            if (Calc < Search->Len + 1)
              Calc = Search->Len + 1, Choice = N + Search->To[b[j]];
            break;
          }
          if (Calc < min(Search->Len + 1, ((D >= A[i].L) ? (D - A[i].L + 1) : 0)))
            Calc = min(Search->Len + 1, D - A[i].L + 1), Choice = N + Search->To[b[j]];
        }
        Search = N + Search->Fail;
      }
      if (!Choice) Search = N + 1; else Search = Choice;
      LCS = min((unsigned)LCS + 1, Calc), CTmp = b[j], Add(), Tmp += (N[Last->Fail].Len <= LCS) ? (LCS - N[Last->Fail].Len) : 0;
      // printf("Calc %u LCS %llu Last %u LFail %u\n", Calc, LCS, Last - N, Last->Fail);
    }
    for (Node* j(DelLine + 1); j <= CntN; ++j) Ans[A[i].AsNum] += j->Len - N[j->Fail].Len;
    Ans[A[i].AsNum] -= Tmp;
    for (unsigned j(A[i].R + 1); j <= A[i + 1].R; ++j) B = N[Prefix[j]].DFSr, C = j, Insert(S, 1, Prefix[n] + 1);
  }
  for (unsigned i(1); i <= m; ++i) printf("%llu\n", Ans[i]);
  system("pause");
  return Wild_Donkey;
}