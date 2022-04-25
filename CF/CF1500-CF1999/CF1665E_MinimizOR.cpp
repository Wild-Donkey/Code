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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
vector <unsigned> Out;
struct Node {
  Node *LS, *RS;
  vector<unsigned> Mn; 
  inline void Build(unsigned L, unsigned R);
  inline void Qry(unsigned L, unsigned R) {
//    printf("Qry [%u, %u]\n", L, R);
    if((A <= L) && (R <= B)) { for (auto i:Mn) Out.push_back(i); return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid) LS->Qry(L, Mid);
    if(B > Mid) RS->Qry(Mid + 1, R);
  }
}N[200005], *CntN(N);
inline void Clr() {
  memset(N, 0, (CntN - N + 1) * sizeof(Node));
  n = RD(), CntN = N;
}
inline void Node::Build(unsigned L, unsigned R) {
  if(L == R) { Mn.push_back(RD()); return; }
  unsigned Mid((L + R) >> 1);
  (LS = ++CntN)->Build(L, Mid);
  (RS = ++CntN)->Build(Mid + 1, R);
  for (auto i:LS->Mn) Mn.push_back(i);
  for (auto i:RS->Mn) Mn.push_back(i);
  sort(Mn.begin(), Mn.end());
  while (Mn.size() > 31) Mn.pop_back();
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr(), N->Build(1, n); 
    m = RD();
    for (unsigned i(1); i <= m; ++i) {
      Out.clear(), A = RD(), B = RD(), N->Qry(1, n);
      sort(Out.begin(), Out.end()), Ans = 0xffffffff;
//      printf("Cur:"); for (auto j:Out) printf("%u ", j); putchar(0x0A);
      for (unsigned j(min(30, (int)(Out.size() - 1))); ~j; --j)
        for (unsigned k(0); k < j; ++k) Ans = min(Ans, Out[j] | Out[k]);
      printf("%u\n", Ans);
    }
  }
  return Wild_Donkey;
}

