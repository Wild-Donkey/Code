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
unsigned m, n, Cnt(0), Hd(0), Tl(0), A, B, C, D, t, Ans(0), Tmp(0);
char AddC, Opt;
struct Node {
  Node* To[26], * Fail, * Son, * Bro;
  unsigned long long Size;
  unsigned Len, EndPos, Idg;
}N[1000005], * Topo[1000005], * CntN(N), * Last(N);
void Add() {
  Node* Back(Last);
  Last = ++CntN, Last->Len = Back->Len + 1, Last->EndPos = 1;
  while (Back && (!(Back->To[AddC]))) { Back->To[AddC] = Last, Back = Back->Fail; }
  if (Back) {
    if (Back->To[AddC]->Len ^ (Back->Len + 1)) {
      Node* Bfr(Back->To[AddC]);
      *(++CntN) = *Bfr, CntN->Len = Back->Len + 1, Bfr->Fail = Last->Fail = CntN, CntN->EndPos = 0;
      while (Back && (Back->To[AddC] == Bfr)) Back->To[AddC] = CntN, Back = Back->Fail;
    }
    else Last->Fail = Back->To[AddC];
  }
  else Last->Fail = N;
}
void DFS(Node* x) {
  Node* Now(x->Son);
  while (Now) DFS(Now), x->EndPos += Now->EndPos, Now = Now->Bro;
}
void Qry(Node* x) {
  if (x->EndPos >= A) { putchar('\n'); return; } A -= x->EndPos;
  for (char i(0); i < 26; ++i) if (x->To[i]) { if (x->To[i]->Size >= A) { putchar(i + 'a'); return Qry(x->To[i]); } A -= x->To[i]->Size; }
}
signed main() {
  // freopen("P3975_21.in", "r", stdin);
  // freopen("P3975.out", "w", stdout);
  AddC = getchar();
  while (AddC < 'a') AddC = getchar();
  while (AddC >= 'a') AddC -= 'a', Add(), AddC = getchar();
  for (Node* i(N); i <= CntN; ++i) for (char j(0); j < 26; ++j) if (i->To[j]) ++(i->To[j]->Idg);
  Topo[++Tl] = N, n = CntN - N;
  while (Hd ^ Tl) for (char i(!(++Hd)); i < 26; ++i) if (Topo[Hd]->To[i]) if (!(--(Topo[Hd]->To[i]->Idg))) Topo[++Tl] = Topo[Hd]->To[i];
  Opt = RD(), A = RD();
  if (Opt) {
    for (Node* i(N + 1); i <= CntN; ++i) i->Bro = i->Fail->Son, i->Fail->Son = i;
    DFS(N), N->EndPos = 0;
  }
  else for (Node* i(N + 1); i <= CntN; ++i) i->EndPos = 1;
  for (unsigned i(n + 1); i; --i) {
    Topo[i]->Size = Topo[i]->EndPos;
    for (char j(0); j < 26; ++j) if (Topo[i]->To[j]) Topo[i]->Size += Topo[i]->To[j]->Size;
  }
  if (N->Size < A) { printf("-1\n"); return 0; }
  Qry(N);
  // system("pause");
  return Wild_Donkey;
}
/*
aaaaaaa
1 14
abcdbcd
1 14
banana
1 10
aaaaaa
1 10
*/