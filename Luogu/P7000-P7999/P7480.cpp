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
#include <string>
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
unsigned m, n, Frm, Lst;
int T;
unsigned StkL[100005], StkR[100005], Top1(0), Top2(0);
unsigned List[100005];
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Sta {
  unsigned Val, Pos;
  const unsigned char operator < (const Sta &x) { return Pos < x.Pos; }
}S[100005], FindT;
struct Edge {
  Node* To;
  Edge* Nxt;
  unsigned long long Val;
}E[100005], * CntE(E);
struct Node {
  Edge* Fst;
  unsigned long long Dis;
}N[100005];
inline void Link(const unsigned &x, const unsigned &y, const unsigned long long &z) {
  (++CntE)->Nxt = N[x].Fst, N[x].Fst = CntE, CntE->To = N + y, CntE->Val = z; 
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD() + 1, FindT.Pos = RDsg() + 1000000000, S[n].Pos = RDsg() + 1000000000;
  for (unsigned i(1); i < n; ++i) S[i].Val = RD(), S[i].Pos = 1000000000 + RDsg();
  sort(S + 1, S + n + 1), Frm = lower_bound(S + 1, S + n + 1, FindT) - S;
  for (unsigned i(Frm), j(Frm), k(S[Frm].Val);;) {
    while(i && (S[i].Val >= k)) --i;
    while((j <= n) && (S[j].Val >= k)) ++j;
    if(S[i].Val > S[j].Val) k = S[i].Val, StkL[++Top1] = i;
    else k = S[j].Val, StkR[++Top2] = j;
    if(!k) break;
  }
  if(S[StkR[Top2 - 1]].Pos == S[StkR[Top2]].Pos) StkR[Top2 - 1] = StkR[Top2], --Top2;
  for (unsigned i(1), j(1), k(Frm); j <= Top2;) {
    List[++Cnt] = k;
//    printf("%u, %u <- %u\n", StkL[i], StkR[j], k);
    Link(k, StkL[i], (unsigned long long)S[k].Val * (S[k].Pos - S[StkL[i]].Pos));
    Link(k, StkR[j], (unsigned long long)S[k].Val * (S[StkR[j]].Pos - S[k].Pos));
    if(S[StkL[i]].Val > S[StkR[j]].Val) k = StkL[i++];
    else k = StkR[j++];
  }
  for (unsigned i(1); i <= n; ++i) N[i].Dis = 0x3f3f3f3f3f3f3f3f;
  N[Frm].Dis = 0;
  for (unsigned i(1); i <= Cnt; ++i) {
    Node* Cur(N + List[i]);
    Edge* Sid(Cur->Fst);
    while (Sid) {
//      printf("%u -> %u\n", Cur - N, Sid->To - N);
      Sid->To->Dis = min(Sid->To->Dis, Cur->Dis + Sid->Val);
      Sid = Sid->Nxt;
    }
  }
//  printf("StkL:\n");
//  for (unsigned i(1); i <= Top1; ++i) printf("%u ", StkL[i]);
//  printf("\nStkR:\n");
//  for (unsigned i(1); i <= Top2; ++i) printf("%u ", StkR[i]);
//  putchar('\n');
  printf("%llu\n", N[StkR[Top2]].Dis);
//  }
  return Wild_Donkey;
}

