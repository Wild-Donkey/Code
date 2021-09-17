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
unsigned long long  Ans[100005];
unsigned m, n, Cnt(0), B, C, D, t, Calc;
unsigned LCS, Pointer(0), DFSCnt(0), Tmp(0);
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
  // printf("[%u, %u]\n", L, R);
  x->Mx = max(x->Mx, C);
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  if (B <= Mid) { if (!(x->LS)) x->LS = ++CntS; Insert(x->LS, L, Mid); }
  else { if (!(x->RS)) x->RS = ++CntS;  Insert(x->RS, Mid + 1, R); }
}
void Qry(Seg* x, unsigned L, unsigned R) {
  if ((B <= L) && (R <= C)) { D = max(D, x->Mx);return; }
  unsigned Mid((L + R) >> 1);
  if ((B <= Mid) && (x->LS)) Qry(x->LS, L, Mid);
  if ((Mid < C) && (x->RS)) Qry(x->RS, Mid + 1, R);
}
struct Node {
  Node* To[26], * Fail, * Son, * Bro;
  unsigned Len, DFSr, Size;
}N[2000005], * Prefix[500005], * CntN(N), * Last(N), * DelLine(N), * Search, * Choice;
void Add() {
  Node* Back(Last);
  Last = ++CntN, CntN->Len = Back->Len + 1, memset(Last->To, 0, sizeof(Last->To));
  while (Back && (!(Back->To[CTmp]))) Back->To[CTmp] = Last, Back = Back->Fail;
  if (Back) {
    if ((Back->To[CTmp]->Len) ^ (Back->Len + 1)) {
      Node* Bfr(Back->To[CTmp]);
      *(++CntN) = *Bfr, CntN->Len = Back->Len + 1, Bfr->Fail = Last->Fail = CntN;
      while (Back && (Back->To[CTmp] == Bfr)) Back->To[CTmp] = CntN, Back = Back->Fail;
    }
    else Last->Fail = Back->To[CTmp];
  }
  else Last->Fail = DelLine;
}
void DFS(Node* x) {
  Node* Now(x->Son);
  x->DFSr = ++DFSCnt, x->Size = 1;
  while (Now) {
    DFS(Now), x->Size += Now->Size, Now = Now->Bro;
  }
}
signed main() {
  // freopen("name.in", "r", stdin);
  // freopen("name.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  CTmp = getchar(); while (CTmp < 'a')  CTmp = getchar();
  while (CTmp >= 'a') CTmp -= 'a', Add(), Prefix[++n] = Last, CTmp = getchar();
  DelLine = Prefix[n] + 2, m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A[i].Frm = Pointer + 1, CTmp = getchar(); while (CTmp < 'a') CTmp = getchar();
    while (CTmp >= 'a') b[++Pointer] = CTmp - 'a', CTmp = getchar();
    A[i].L = RD(), A[i].R = RD(), A[i].To = Pointer, A[i].AsNum = i;
  }
  for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fail->Son, i->Fail->Son = i;
  A[m + 1].R = A[m].R, sort(A + 1, A + m + 1), DFS(N);
  for (unsigned i(1); i <= A[1].R; ++i) B = Prefix[i]->DFSr, C = i, Insert(S, 1, Prefix[n] - N + 2);
  for (unsigned i(1); i <= m; ++i) {
    LCS = 0, Search = N, Last = CntN = DelLine, memset(DelLine, 0, sizeof(Node)), Tmp = 0;
    for (unsigned j(A[i].Frm); j <= A[i].To; ++j) {
      Calc = 0, Choice = NULL;
      while (Search && (Search->Len >= Calc)) {
        if (Search->To[b[j]]) {
          B = Search->To[b[j]]->DFSr, C = B + Search->To[b[j]]->Size - 1, D = 0, Qry(S, 1, Prefix[n] - N + 2);
          if (D >= A[i].L) {
            if (D >= A[i].L + Search->Len) {
              if (Calc < Search->Len + 1) Calc = Search->Len + 1, Choice = Search->To[b[j]]; break;
            }
            if (Calc < min(Search->Len + 1, D - A[i].L + 1))
              Calc = min(Search->Len + 1, D - A[i].L + 1), Choice = Search->To[b[j]];
          }
        }
        Search = Search->Fail;
      }
      Search = (Choice) ? Choice : (N + 1);
      LCS = min((unsigned)LCS + 1, Calc), CTmp = b[j], Add(), Tmp += (Last->Fail->Len <= LCS) ? (LCS - Last->Fail->Len) : 0;
    }
    for (Node* j(DelLine + 1); j <= CntN; ++j) Ans[A[i].AsNum] += j->Len - j->Fail->Len;
    Ans[A[i].AsNum] -= Tmp;
    for (unsigned j(A[i].R + 1); j <= A[i + 1].R; ++j) B = Prefix[j]->DFSr, C = j, Insert(S, 1, Prefix[n] - N + 2);
  }
  for (unsigned i(1); i <= m; ++i) printf("%llu\n", Ans[i]);
  // system("pause");
  return Wild_Donkey;
}