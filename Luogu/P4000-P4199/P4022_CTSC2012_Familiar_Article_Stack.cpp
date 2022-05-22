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
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned a[1100005], f[1100005], Stack[1100005], *STop(Stack);
unsigned m, n, Len;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Match;
char SPool[1100005], *S(SPool);
inline char Judge (unsigned x) {
  if(!x) return 1;
  unsigned Cur(0);
  memset(f + 1, 0x3f, Len << 2);
  f[0] = 0;
  for (unsigned i(1); i <= Len; ++i) {
    if(i >= x) {
      while ((STop > Stack) && (f[i - x] <= f[*STop])) --STop;
      *(++STop) = i - x;
    }
    f[i] = f[i - 1] + 1;
    if(a[i] >= x)
      f[i] = min(f[i], f[*lower_bound(Stack + 1, STop + 1, i - a[i])]);
//    printf("%u ", f[i]);
  }
//  putchar(0x0A);
  return f[Len] <= (Len * 0.1);
}
inline void Solve () {
  unsigned L(0), R(Len), Mid;
  while (L ^ R) {
    Mid = ((L + R + 1) >> 1);
//    printf("[%u %u] %u\n", L, R, Mid);
    if(Judge(Mid)) L = Mid;
    else R = Mid - 1; 
  }
  printf("%u\n", L);
}
struct Node{
  Node *E[2], *Fail;
  unsigned Len;
  inline void Prt();
  inline Node*Find(char c);
  inline Node*Add(char c);
}N[2200005], *CntN(N);
inline void Node::Prt() {
  printf("Node%u: Sons %u %u Fail %u Len %u\n", this - N, E[0] - N, E[1] - N, Fail - N, Len);
}
inline Node* Node::Find(char c) {
//  printf("Find %u on %u Matched %u\n", c, this - N, Match);
  if(E[c]) {++Match; return E[c];}
  Node* Back(Fail);
//  printf("Fail %u\n", Back - N);
  while (Back && (!Back->E[c])) Back = Back->Fail;
  Match = Back ? (Back->Len + 1) : 0;
  return Back ? Back->E[c] : N;
}
inline Node* Node::Add(char c) {
//  printf("%u Add %u\n", this - N, c);
  if(E[c]) {
    if(E[c]->Len == Len + 1) return E[c];
    Node* Copy(++CntN), *Back(this), *Ori(E[c]);
    *Copy = *E[c], Copy->Len = Len + 1, Ori->Fail = Copy;
    while (Back && (Back->E[c] == Ori)) Back->E[c] = Copy, Back = Back->Fail;
    return Copy;
  }
  Node*Cur(++CntN), *Back(this);
  Cur->Len = Len + 1;
  while (Back && (!Back->E[c])) Back->E[c] = Cur, Back = Back->Fail;
//  printf("Back %u\n", Back - N);
  if(!Back) {Cur->Fail = N; return Cur;}
  if(Back->E[c]->Len == Back->Len + 1) {Cur->Fail = Back->E[c]; return Cur;}
  Node*Copy(++CntN), *Ori(Back->E[c]);
  *Copy = *Ori, Copy->Len = Back->Len + 1;
  Cur->Fail = Ori->Fail = Copy;
  while (Back && (Back->E[c] == Ori)) Back->E[c] = Copy, Back = Back->Fail;
  return Cur;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    scanf("%s", S), Len = strlen(S);
    Node* Cur(N);
    for (unsigned j(0); j < Len; ++j) Cur = Cur->Add(S[j] - '0');
//    for (Node* j(N); j <= CntN; ++j) j->Prt();
    S = S + Len;
  }
  for (unsigned i(1); i <= n; ++i) {
    Node* Cur(N);
    scanf("%s", S), Len = strlen(S), Match = 0;
    for (unsigned j(0); j < Len; ++j)
      Cur = Cur->Find(S[j] - '0'), a[j + 1] = Match;
    S = S + Len;
//    for (unsigned j(1); j <= Len; ++j) printf("%u ", a[j]); putchar(0x0A);
    Solve();
  }
//  }
  return Wild_Donkey;
}

