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
unsigned Cnt(0), Tmp(0);
unsigned Sz[100005], List[100005], Fa[100005], Stack[100005], *ST(Stack);
unsigned SzBC[100005][4];
unsigned long long Ans[100005], End(0);
struct Node {
  vector<Node *> E, IE;
  unsigned DFSr, Low;
  char Tag;
  inline void Tarjan();
  inline void DFS();
} N[100005], *Stk[100005], **STop(Stk);
inline void Node::DFS() {
  // printf("DFS %u\n", this - N);
  if (!Tag) Tag = 1;
  char Nxt(((Tag << 1) | ((Tag & 4) >> 2)) & 7);
  for (auto i : E)
    if ((i->Tag | Nxt) ^ (i->Tag)) i->Tag |= Nxt, i->DFS();
  char Frt(((Tag >> 1) | (Tag << 2)) & 7);
  for (auto i : IE)
    if ((i->Tag | Frt) ^ (i->Tag)) i->Tag |= Frt, i->DFS();
}
inline unsigned Find(unsigned x) {
  while (Fa[x] ^ x) *(++ST) = x, x = Fa[x];
  while (ST > Stack) Fa[*(ST--)] = x;
  return x;
}
inline unsigned long long Calc(unsigned long long x) { return x * x; }
//  inline void Clr() {}
signed main() {
  // freopen("AGC006F_18.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  // printf("FAQ\n");
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    N[A].E.push_back(N + B);
    N[B].IE.push_back(N + A);
  }
  for (unsigned i(1); i <= n; ++i) N[i].Tag = 0;
  for (unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (unsigned i(1); i <= n; ++i)
    for (auto j : N[i].E) Fa[Find(i)] = Find(j - N);
  // if (n >= 5) return 0;
  // if (n >= 5) return 0;
  for (unsigned i(1); i <= n; ++i)
    if (!(N[i].Tag)) N[i].DFS();
//   for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Bel - Bl);
//   putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Fa[i]);
  // putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) ++Sz[Find(i)];
  for (unsigned i(1); i <= n; ++i) SzBC[Fa[i]][3] += N[i].E.size();
  for (unsigned i(1); i <= n; ++i)
    if ((N[i].Tag ^ 1) && (N[i].Tag ^ 2) && (N[i].Tag ^ 4))
      Ans[Fa[i]] = Calc(Sz[Fa[i]]);
  Cnt = 0;
  for (unsigned i(1); i <= n; ++i)
    if (Fa[i] == i) List[++Cnt] = i;
  for (unsigned i(1); i <= n; ++i) {
    unsigned Cur(Fa[i]);
    // printf("%u ", Cur);
    // printf("%u ", N[i].Tag);
    if (N[i].Tag & 1) ++SzBC[Cur][0];
    if (N[i].Tag & 2) ++SzBC[Cur][1];
    if (N[i].Tag & 4) ++SzBC[Cur][2];
  }
  // // putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i)
  //   if ((Sz[Fa[i]] ^ (SzBC[Fa[i]][0] + SzBC[Fa[i]][1] + SzBC[Fa[i]][2])) &&
  //       (!Ans[Fa[i]]))
  //     printf("%u\n", i);
  for (unsigned i(1), j(List[1]); i <= Cnt; j = List[++i])
    if (!Ans[j]) {
      if (((unsigned long long)SzBC[j][0] * SzBC[j][1]) * SzBC[j][2])
        Ans[j] = (unsigned long long)SzBC[j][0] * (SzBC[j][2] + SzBC[j][1]) +
                 (unsigned long long)SzBC[j][2] * SzBC[j][1];
      else
        Ans[j] = SzBC[j][3];
    }
  // for (unsigned i(1), j(List[1]); i <= Cnt; j = List[++i])
  // putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i)
  //   if (N[Fa[i]].Tag) printf("%u\n", Sz[Fa[i]]), N[Fa[i]].Tag = 0;
  // for (unsigned i(1); i <= n; ++i)
  //   if (N[Fa[i]].Tag) printf("%llu\n", Ans[Fa[i]]), N[Fa[i]].Tag = 0;
  // for (unsigned i(1); i <= n; ++i)
  //   if (N[Fa[i]].Tag) {
  //     sort(SzBC[Fa[i]], SzBC[Fa[i]] + 3);
  //     printf("%u,%u,%u\n", SzBC[Fa[i]][0], SzBC[Fa[i]][1], SzBC[Fa[i]][2]),
  //         N[Fa[i]].Tag = 0;
  //   }
  // for (unsigned i(1), j(List[1]); i <= Cnt; j = List[++i]) printf("%u ",
  // Sz[j]);
  // putchar(0x0A);
  //  printf("End = %llu\n", End); for (unsigned i(1),
  // j(List[1]); i <= Cnt; j = List[++i])
  //   if (Ans[j] >= 10) printf("%llu ", Ans[j]);
  // putchar(0x0A);
  for (unsigned i(1), j(List[1]); i <= Cnt; j = List[++i]) End += Ans[j];
  printf("%llu\n", End);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ AGC006F_Blackout.cpp -o faq -std=c++14 -Wl,--stack=1024000000 -O2
+1
-2
+4
-5
+7
-8
+3k + 1
-3k - 2

1 2
1 5
4 2
4 5

2 3
2 6
5 3
5 6

3 1
3 4
6 1
6 4
*/
