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
unsigned E[205][205], Stack[405];
unsigned DFSr[405], Low[405], Bel[405], Col[405];
unsigned Fa[205], Setak[205], STop(0);
unsigned m, n, n2;
unsigned A, B, C, D, Mx(0);
unsigned Cnt(0), SCC(0), Ans(0x3f3f3f3f), Tmp(0), Top(0);
unsigned char ToFa[205];
char InS[405], Flg(0);
struct Edge {
  unsigned Frm, To, Val;
  const inline char operator <(const Edge& x) const {return Val < x.Val;}
}List[20005];
inline void Tarjan(unsigned x) {
//  printf("Tar %u\n", x);
  Low[x] = DFSr[x] = ++Cnt, Stack[++Top] = x, InS[x] = 1;
  if(x & 1) {
    for (unsigned i(0); i < n; ++i) {
      if(E[x >> 1][i] > D) {
        unsigned Cur(i << 1);
        if (DFSr[Cur]) {if(InS[Cur]) Low[x] = min(Low[x], Low[Cur]);}
        else Tarjan(Cur), Low[x] = min(Low[x], Low[Cur]);
      }
    }
  }else {
    for (unsigned i(0); i < n; ++i) {
      if(E[x >> 1][i] > C) {
        unsigned Cur((i << 1) ^ 1);
        if (DFSr[Cur]) {if(InS[Cur]) Low[x] = min(Low[x], Low[Cur]);}
        else Tarjan(Cur), Low[x] = min(Low[x], Low[Cur]);
      }
    }
  }
  if(Low[x] == DFSr[x]) {
    ++SCC;
    do Bel[Stack[Top]] = SCC, InS[Stack[Top]] = 0;
    while(Stack[Top--] ^ x);
  }
//  printf("Out of %u\n", x);
}
inline char Judge () {
  memset(Low, 0, ((n + 1) << 3));
  memset(DFSr, 0, ((n + 1) << 3));
  Cnt = 0, SCC = 0;
  for (unsigned i(0); i < n2; ++i) if(!DFSr[i]) Tarjan(i);
//  for (unsigned i(0); i < n2; ++i) printf("%u ", Bel[i]);
//  putchar('\n');
  for (unsigned i(0); i < n; ++i) if(Bel[i << 1] == Bel[(i << 1) ^ 1]) return 0;
  return 1;
}
inline unsigned Find(unsigned x) {
  unsigned char AddUp(0);
  while (Fa[x] ^ x) Setak[++STop] = x, x = Fa[x];
  while (STop) AddUp += ToFa[Setak[STop]], Fa[Setak[STop]] = x, ToFa[Setak[STop--]] = AddUp & 1;
  return x;
}
inline void Binary() {
//  printf("This Time %u\n", D);
  A = 0, B = D + 1;
  while (A ^ B) {
    C = (A + B) >> 1;
//    printf("[%u, %u] %u\n", A, B, C);
    if(Judge()) B = C;
    else A = C + 1;
  }
  if(A ^ (D + 1)) Ans = min(Ans, D + A);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n2 = ((n = RD()) << 1), m = (n * (n + 1)) >> 1;
  for (unsigned i(0); i < n; ++i) Fa[i] = i;
  for (unsigned i(0); i < n; ++i) {
    E[i][i] = 0;
    for (unsigned j(i + 1); j < n; ++j)
      Mx = max(Mx, List[++Cnt].Val = E[i][j] = E[j][i] = RD()),
      List[Cnt].Frm = i, List[Cnt].To = j;
    List[++Cnt].Val = 0, List[Cnt].Frm = List[Cnt].To = i;
  }
  sort(List + 1, List + m + 1);
  for (unsigned i(m); i; --i) {
//    printf("%u -> %u\n", List[i].Frm, List[i].To);
    D = List[i].Val, A = Find(List[i].Frm), B = Find(List[i].To); 
//    printf("means %u -> %u (%u & %u)\n", A, B, ToFa[List[i].Frm], ToFa[List[i].To]);
//    for (unsigned j(0); j < n; ++j) printf("%u ", ToFa[j]);
//    putchar('\n');
    if(A ^ B) {
      Fa[A] = B, ToFa[A] = ToFa[List[i].Frm] ^ ToFa[List[i].To] ^ 1, Binary();
    } else {
      if(ToFa[List[i].Frm] ^ ToFa[List[i].To]) continue;
      else {Binary();break;}
    }
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
