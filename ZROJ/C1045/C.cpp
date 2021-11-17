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
bitset<300005> Used;
pair<unsigned, unsigned> End[600005];
unsigned Beg[300005];
unsigned n, m;
unsigned A, B, C, D, t;
unsigned Ans(1), TmpC(0), TmpM(0);
struct Node {
  Node* LS, * RS;
  unsigned Mx, Cnt;
  inline void Add(unsigned L, unsigned R) {
    if(L == R) {Mx = L, ++Cnt; return;}
    unsigned Mid((L + R) >> 1);
    if(B <= Mid) LS->Add(L, Mid);
    else RS->Add(Mid + 1, R);
    Mx = max(LS->Mx, RS->Mx);
    Cnt = LS->Cnt + RS->Cnt;
  }
  inline void Del(unsigned L, unsigned R) {
    if(L == R) {if(!(--Cnt)) Mx = 0; return;} 
    unsigned Mid((L + R) >> 1);
    if(Beg[A] <= Mid) LS->Del(L, Mid);
    else RS->Del(Mid + 1, R);
    Mx = max(LS->Mx, RS->Mx);
    Cnt = LS->Cnt + RS->Cnt;
  }
  inline void Qry(unsigned L, unsigned R) {
    if(L == R) return;
    unsigned Mid((L + R) >> 1), Len(max(LS->Mx, D));
    if(LS->Cnt + C <= B - Len + 1) {
      Ans = max(Ans, LS->Cnt + C);
      C += LS->Cnt, D = Len;
      RS->Qry(Mid + 1, R);
    } else {
      Ans = max(Ans, B - Len + 1);
      LS->Qry(L, Mid);
    }
  }
}N[600005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  m = (n = RD()) << 1;
  for (unsigned i(1); i <= n; ++i)
    End[i << 1] = make_pair(Beg[i] = RD(), i), End[(i << 1) - 1] = make_pair(RD(), i);
  sort(End + 1, End + m + 1), Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    A = End[i].second, B = End[i].first;
    if(Used[A]) C = D = 0, N->Qry(1, n), N->Del(1, n);
    else Used[A] = 1, N->Add(1, n);
//    printf("%u Ans %u\n", i, Ans);
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

