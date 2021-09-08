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
#define Lowbit(x) ((x)&((~(x))+1)) 
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
unsigned long long Ans[100005], Sum;
unsigned Map[100005], Qry[100005][3], Edit[1000005], CntE(0);
unsigned m, n, DFSCnt(0), Cnt(0);
unsigned A, B, D, t, Tmp(0);
unsigned TrArray[200005], ULimit;
char C;
void Chg(unsigned x) { while (x <= ULimit) ++TrArray[x], x += Lowbit(x); }
void Que(unsigned x) { while (x) Tmp += TrArray[x], x -= Lowbit(x); }
struct Node {
  Node* To[26], * Fail, * Bro, * Son;
  unsigned Len, DFSr, Size;
}N[200005], * CntN(N), * Search, * Last;
void Add() {
  if (Last->To[C]) {
    if (Last->To[C]->Len == Last->Len + 1) { Map[B] = Last->To[C] - N;return; }
    Node* Bfr(Last->To[C]), * x(++CntN);
    x->Fail = Bfr->Fail, Bfr->Fail = x, x->Len = Last->Len + 1, Map[B] = x - N;
    for (char i(0); i < 26; ++i) if ((Bfr->To[i]) && (Bfr->To[i]->Len)) x->To[i] = Bfr->To[i];
    while (Last && (Last->To[C] == Bfr)) Last->To[C] = x, Last = Last->Fail;
    return;
  }
  Node* x(++CntN);
  x->Len = Last->Len + 1, Map[B] = x - N;
  while (Last) {
    if (Last->To[C]) break; else Last->To[C] = x;
    Last = Last->Fail;
  }
  if (Last) {
    if (Last->To[C]->Len == Last->Len + 1) { x->Fail = Last->To[C], Sum += x->Len - Last->To[C]->Len; return; }
    Node* Bfr(Last->To[C]);
    (++CntN)->Len = Last->Len + 1, CntN->Fail = Bfr->Fail, Bfr->Fail = x->Fail = CntN, Sum += x->Len - CntN->Len;
    for (char i(0); i < 26; ++i) if ((Bfr->To[i]) && (Bfr->To[i]->Len)) CntN->To[i] = Bfr->To[i];
    while (Last && (Last->To[C] == Bfr)) Last->To[C] = CntN, Last = Last->Fail;
  }
  else x->Fail = N + 1, Sum += x->Len;
}
void DFS_Final(Node* x) {
  x->DFSr = ++DFSCnt, x->Size = 1;
  Node* Now(x->Son);
  while (Now) DFS_Final(Now), x->Size += Now->Size, Now = Now->Bro;
}
signed main() {
  // freopen("4545/8.in", "r", stdin);
  // freopen("4545.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  RD(), n = RD(), memset(Ans, 0x3f, sizeof(Ans)), Map[1] = ++CntN - N;
  for (register unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = getchar(); while (C < 'a') C = getchar();
    if (A > B) swap(A, B);
    C -= 'a', Last = N + Map[A], Add(), Edit[++CntE] = Map[B];
  }
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    D = RD();
    if (D == 1) Ans[i] = Sum;
    else {
      if (D & 1) {
        C = getchar(), Search = N + 1;
        while (C < 'a') C = getchar();
        while (C >= 'a') {
          if (!(Search->To[C - 'a'])) { Ans[i] = 0; while (C >= 'a') C = getchar(); break; }
          Search = Search->To[C - 'a'], C = getchar();
        }
        if (Ans[i]) Qry[++Cnt][1] = Search - N, Qry[Cnt][0] = i, Qry[Cnt][2] = CntE;
      }
      else {
        RD(), D = RD();
        for (unsigned j(1); j < D; ++j) {
          A = RD(), B = RD(), C = getchar(); while (C < 'a') C = getchar();
          if (A > B) swap(A, B);
          C -= 'a', Last = N + Map[A], Add(), Edit[++CntE] = Map[B];
        }
      }
    }
  }
  for (Node* i(N + 2); i <= CntN; ++i) i->Bro = i->Fail->Son, i->Fail->Son = i;
  DFS_Final(N + 1), ULimit = CntN - N;
  for (unsigned i(1), j(1); i <= Cnt; ++i) {
    while (j <= Qry[i][2]) { Chg(N[Edit[j]].DFSr), ++j; }
    Tmp = 0, Que(N[Qry[i][1]].DFSr + N[Qry[i][1]].Size - 1), Ans[Qry[i][0]] = Tmp, Tmp = 0, Que(N[Qry[i][1]].DFSr - 1), Ans[Qry[i][0]] -= Tmp;
  }
  for (unsigned i(1); i <= m; ++i) if (Ans[i] < 0x3f3f3f3f3f3f3f3f) printf("%llu\n", Ans[i]);
  return Wild_Donkey;
}
/*
1
4
1 2 a
1 3 b
2 4 b
6
1
2 2 4
2 5 b
2 6 c
5 7 b
1
3 ab
2 6 3
6 8 a
6 9 b
1
*/