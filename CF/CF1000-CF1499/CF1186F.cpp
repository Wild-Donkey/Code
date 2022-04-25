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
bitset<1500005> Ava, M, Ant;
unsigned Ans[1500005], Add[1500005][2];
struct Node;
struct Node {
  vector<unsigned> E;
  unsigned Dgr, Top;
}N[1000005], *Lst(NULL);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void DFS(Node* x) {
//  printf("DFS %u %u\n", x - N, x->Top);
  while (~(x->Top)) {
    unsigned Cur(x->E[(x->Top)--]);
//    printf("Cur %u\n", Cur);
    if(Ava[Cur]) continue;
    Ava[Cur] = 1;
    Node* To(N + Add[Cur][Add[Cur][0] == x - N]);
    if(~(To->Top)) DFS(To);
    Ans[++Cnt] = Cur;
  }
}
//  inline void Clr() {}
signed main() {
//  freopen("graph2.in", "r", stdin);
//  freopen("my.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Ava = 0;
  for (unsigned i(1); i <= m; ++i) {
    Add[i][0] = A = RD(), Add[i][1] = B = RD(), ++(N[A].Dgr), ++(N[B].Dgr);
    N[A].E.push_back(i), N[B].E.push_back(i);
  }
  for (unsigned i(1), Lst(0), Ct(m); i <= n; ++i) if(N[i].Dgr & 1){ 
    if(Lst) {
      N[Lst].E.push_back(++Ct), N[i].E.push_back(Ct);
      Add[Ct][0] = Lst, Add[Ct][1] = i, Lst = 0;
    } else Lst = i;
  }
  for (unsigned i(1); i <= n; ++i) N[i].Top = N[i].E.size() - 1;
  Cnt = 0;
  for (unsigned i(1), j(Cnt); i <= n; ++i) if(~(N[i].Top)) {
    j = Cnt + 1, DFS(N + i);
    for (unsigned i(j); i <= Cnt; i += 2) 
      if(Ans[i] <= m) M[Ans[i]] = 1, ++Tmp; else N[Add[Ans[i]][0]].Dgr = 0, N[Add[Ans[i]][1]].Dgr = 0;
  }
//  for (unsigned i(1); i <= Cnt; ++i) printf("%u ", Ans[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) if(!(N[i].Dgr)) for (auto j:N[i].E)
    if((j <= m) && (!M[j])) {M[j] = 1, ++Tmp, N[Add[j][0]].Dgr = N[Add[j][1]].Dgr = 1; break;}
  printf("%u\n", Tmp);
//  for (unsigned i(1); i <= m; ++i) if(M[i]) printf("%u ", i);
  for (unsigned i(1); i <= m; ++i) if(M[i]) printf("%u %u\n", Add[i][0], Add[i][1]);
//  }
  return Wild_Donkey;
}

