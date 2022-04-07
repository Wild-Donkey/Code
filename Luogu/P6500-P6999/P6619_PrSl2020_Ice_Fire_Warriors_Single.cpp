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
struct Infor {
  unsigned x, y;
  char Ty;
}Tip[2000005];
struct Node {
  Node *LS, *RS;
  unsigned Val;
  inline void Add (unsigned L, unsigned R);
  inline void Del (unsigned L, unsigned R);
}N[20000005], *CntN(N + 1);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Node::Add(unsigned L, unsigned R) {
//  printf("Add %u [%u, %u]\n", this - N, L, R);
  Val += B;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) {if(!LS) LS = ++CntN; LS->Add(L, Mid);}
  else { if(!RS) RS = ++CntN; RS->Add(Mid + 1, R);}
}
inline void Node::Del(unsigned L, unsigned R) {
  Val -= B;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) LS->Del(L, Mid);
  else RS->Del(Mid + 1, R);
}
inline void Qry1(Node* x, Node* y, unsigned L, unsigned R) {
  if(L == R) {
    unsigned L1(min(A, B + (y ? y->Val : 0))), L0(min(A + (x ? x->Val : 0), B));
    if(L1 > L0) D = 1, Ans = L - 1, C = L1;
    else D = 0, Ans = L, C = L0;
    return;
  }
  unsigned Mid((L + R) >> 1), CurA(A), CurB(B);
  if(x && x->LS) CurA += x->LS->Val;
  if(y && y->RS) CurB += y->RS->Val;
  if(CurA <= CurB) A = CurA, Qry1(x ? x->RS : NULL, y ? y->RS : NULL, Mid + 1, R);
  else B = CurB, Qry1(x ? x->LS : NULL, y ? y->LS : NULL, L, Mid);
}
inline void Qry2(Node* x, unsigned L, unsigned R) {
  if(L == R) {Ans = L - 1; return;}
  unsigned Mid((L + R) >> 1), CurA(A + ((x && (x->RS)) ? (x->RS->Val) : 0));
  if(CurA < C) A = CurA, Qry2(x ? x->LS : NULL, L, Mid);
  else Qry2(x ? x->RS : NULL, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    if(RD() & 1) {
      C = Tip[i].Ty = RD(), A = Tip[i].x = (RD() + C), B = Tip[i].y = RD();
      (N + C)->Add(1, 2000000001);
    } else {
      C = Tip[D = RD()].Ty, A = Tip[D].x, B = Tip[D].y;
      (N + C)->Del(1, 2000000001);
    }
    A = B = C = Ans = 0;
    Qry1(N, N + 1, 1, 2000000001);
    if(!D) A = 0, Qry2(N + 1, 1, 2000000001);
    if(!C) printf("Peace\n");
    else printf("%u %u\n", Ans, C << 1);
  }
//  }
  return Wild_Donkey;
}

