#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <queue>
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
unsigned m, n, NowD(0), Now(0);
unsigned C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Edge {
  unsigned Val[2];
}E[1000005], * CntE(E);
struct Node {
  unordered_map<Node*, Edge*> To;
  Edge* Up[20];
  Node* Fa[20];
  unsigned ToFa[20][4];
  unsigned Dep;
}N[500005], * A, * B;
inline void Merge(unsigned* ToV, unsigned* FromD, unsigned* FromU, Edge* x, Edge* y) {
  if(!x) {memcpy(ToV, FromU, 16); return;}
  if(x->Val[0] == y->Val[0]) {
    ToV[0] = max(ToV[0], FromD[0] + FromU[0] - 1);
    ToV[1] = max(ToV[1], FromD[0] + FromU[1] - 1);
    ToV[2] = max(ToV[2], FromD[2] + FromU[0] - 1);
    ToV[3] = max(ToV[3], FromD[2] + FromU[1] - 1);
  } else {
    ToV[0] = max(ToV[0], FromD[0] + FromU[0]);
    ToV[1] = max(ToV[1], FromD[0] + FromU[1]);
    ToV[2] = max(ToV[2], FromD[2] + FromU[0]);
    ToV[3] = max(ToV[3], FromD[2] + FromU[1]);
  }
  if(x->Val[0] == y->Val[1]) {
    ToV[0] = max(ToV[0], FromD[0] + FromU[2] - 1);
    ToV[1] = max(ToV[1], FromD[0] + FromU[3] - 1);
    ToV[2] = max(ToV[2], FromD[2] + FromU[2] - 1);
    ToV[3] = max(ToV[3], FromD[2] + FromU[3] - 1);
  } else {
    ToV[0] = max(ToV[0], FromD[0] + FromU[2]);
    ToV[1] = max(ToV[1], FromD[0] + FromU[3]);
    ToV[2] = max(ToV[2], FromD[2] + FromU[2]);
    ToV[3] = max(ToV[3], FromD[2] + FromU[3]);
  }
  if(x->Val[1] == y->Val[0]) {
    ToV[0] = max(ToV[0], FromD[1] + FromU[0] - 1);
    ToV[1] = max(ToV[1], FromD[1] + FromU[1] - 1);
    ToV[2] = max(ToV[2], FromD[3] + FromU[0] - 1);
    ToV[3] = max(ToV[3], FromD[3] + FromU[1] - 1);
  } else {
    ToV[0] = max(ToV[0], FromD[1] + FromU[0]);
    ToV[1] = max(ToV[1], FromD[1] + FromU[1]);
    ToV[2] = max(ToV[2], FromD[3] + FromU[0]);
    ToV[3] = max(ToV[3], FromD[3] + FromU[1]);
  }
  if(x->Val[1] == y->Val[1]) {
    ToV[0] = max(ToV[0], FromD[1] + FromU[2] - 1);
    ToV[1] = max(ToV[1], FromD[1] + FromU[3] - 1);
    ToV[2] = max(ToV[2], FromD[3] + FromU[2] - 1);
    ToV[3] = max(ToV[3], FromD[3] + FromU[3] - 1);
  } else {
    ToV[0] = max(ToV[0], FromD[1] + FromU[2]);
    ToV[1] = max(ToV[1], FromD[1] + FromU[3]);
    ToV[2] = max(ToV[2], FromD[3] + FromU[2]);
    ToV[3] = max(ToV[3], FromD[3] + FromU[3]);
  }
}
inline void PreDFS(Node* x) {
//  printf("PreDFS %u From %u\n", x - N, x->Fa[0] - N);
//  if(x->Up[0]) {
//    printf("%u %u\n", x->Up[0]->Val[0], x->Up[0]->Val[1]);
//  }
  x->ToFa[0][0] = x->ToFa[0][1] = x->ToFa[0][2] = x->ToFa[0][3] = 1;
  for (unsigned i(1); x->Fa[i - 1]; i++) {
    x->Fa[i] = x->Fa[i - 1]->Fa[i - 1];
    if(!x->Fa[i]) break;
    x->Up[i] = x->Fa[i - 1]->Up[i - 1];
    Merge(x->ToFa[i], x->ToFa[i - 1], x->Fa[i - 1]->ToFa[i - 1], x->Up[i - 1], x->Fa[i - 1]->Up[0]);
  }
  for (auto i:x->To) if(i.first != x->Fa[0]) {
    i.first->Fa[0] = x, i.first->Up[0] = i.second, i.first->Dep = x->Dep + 1, PreDFS(i.first);
  }
}
inline void Calc (Node* x, Node* y) {
  unsigned Le[4], Ri[4], TmpL[4], TmpR[4];
  Edge* Last(NULL), * LastR(NULL);
  memset(Le, 0, 16);
  memset(Ri, 0, 16);
  if(x->Dep < y->Dep) swap(x, y);
  if(x->Dep > y->Dep) {
    for (unsigned i(18); ~i; --i) if((x->Fa[i]) && (x->Fa[i]->Dep >= y->Dep)) {
      memset(TmpL, 0, 16);
      Merge(TmpL, Le, x->ToFa[i], Last, x->Up[0]);
      memcpy(Le, TmpL, 16);
      Last = x->Up[i], x = x->Fa[i];
    }
  }
  if(x == y) {
    Ans = max(max(Le[0], Le[0]), max(Le[2], Le[3]));
    return;
  }
  for (unsigned i(18); ~i; --i) if((x->Fa[i] != y->Fa[i])) {
    memset(TmpL, 0, 16);
    Merge(TmpL, Le, x->ToFa[i], Last, x->Up[0]);
    memcpy(Le, TmpL, 16);
    Last = x->Up[i], x = x->Fa[i];
    memset(TmpR, 0, 16);
    Merge(TmpR, Ri, y->ToFa[i], LastR, y->Up[0]);
    memcpy(Ri, TmpR, 16);
    LastR = y->Up[i], y = y->Fa[i];
  }
  memset(TmpL, 0, 16);
  Merge(TmpL, Le, x->ToFa[0], Last, x->Up[0]);
  memcpy(Le, TmpL, 16);
  Last = x->Up[0];
  memset(TmpR, 0, 16);
  Merge(TmpR, Ri, y->ToFa[0], LastR, y->Up[0]);
  memcpy(Ri, TmpR, 16);
  LastR = y->Up[0];
  if(Last->Val[0] == LastR->Val[0]) {
    Ans = max(Ans, Le[0] + Ri[0] - 1);
    Ans = max(Ans, Le[0] + Ri[2] - 1);
    Ans = max(Ans, Le[2] + Ri[0] - 1);
    Ans = max(Ans, Le[2] + Ri[2] - 1);
  } else {
    Ans = max(Ans, Le[0] + Ri[0]);
    Ans = max(Ans, Le[0] + Ri[2]);
    Ans = max(Ans, Le[2] + Ri[0]);
    Ans = max(Ans, Le[2] + Ri[2]);
  }
  if(Last->Val[0] == LastR->Val[1]) {
    Ans = max(Ans, Le[0] + Ri[1] - 1);
    Ans = max(Ans, Le[0] + Ri[3] - 1);
    Ans = max(Ans, Le[2] + Ri[1] - 1);
    Ans = max(Ans, Le[2] + Ri[3] - 1);
  } else {
    Ans = max(Ans, Le[0] + Ri[1]);
    Ans = max(Ans, Le[0] + Ri[3]);
    Ans = max(Ans, Le[2] + Ri[1]);
    Ans = max(Ans, Le[2] + Ri[3]);
  }
  if(Last->Val[1] == LastR->Val[0]) {
    Ans = max(Ans, Le[1] + Ri[0] - 1);
    Ans = max(Ans, Le[1] + Ri[2] - 1);
    Ans = max(Ans, Le[3] + Ri[0] - 1);
    Ans = max(Ans, Le[3] + Ri[2] - 1);
  } else {
    Ans = max(Ans, Le[1] + Ri[0]);
    Ans = max(Ans, Le[1] + Ri[2]);
    Ans = max(Ans, Le[3] + Ri[0]);
    Ans = max(Ans, Le[3] + Ri[2]);
  }
  if(Last->Val[1] == LastR->Val[1]) {
    Ans = max(Ans, Le[1] + Ri[1] - 1);
    Ans = max(Ans, Le[1] + Ri[3] - 1);
    Ans = max(Ans, Le[3] + Ri[1] - 1);
    Ans = max(Ans, Le[3] + Ri[3] - 1);
  } else {
    Ans = max(Ans, Le[1] + Ri[1]);
    Ans = max(Ans, Le[1] + Ri[3]);
    Ans = max(Ans, Le[3] + Ri[1]);
    Ans = max(Ans, Le[3] + Ri[3]);
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Cnt = m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD(), C = RD();
    Edge* Cur(A->To[B]);
    if(!(Cur)) Cur = A->To[B] = B->To[A] = ++CntE;
    if (Cur->Val[0] > m) continue;
    if ((Cur->Val[0] == C) || (Cur->Val[1] == C)) continue; 
    if (Cur->Val[0]) {
      if(Cur->Val[1]) Cur->Val[0] = ++Cnt;
      else Cur->Val[1] = C;
    } else Cur->Val[0] = C;
  }
  for (Edge* i(CntE); i > E; --i) {
    if(!(i->Val[1])) i->Val[1] = i->Val[0];
  }
  N[1].Dep = 1, PreDFS(N + 1), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD();
    if(A == B) {
      printf("0\n");
      continue;
    }
    Ans = 0, Calc(A, B);
    printf("%u\n", Ans - 1);
  }
//  }
  return Wild_Donkey;
}

