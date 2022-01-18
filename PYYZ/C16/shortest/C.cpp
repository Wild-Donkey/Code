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
unsigned Ans[20005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node;
struct Edge {
  Node* Fr, * To;
  unsigned Len, Num;
  char Ava;
  inline const char operator < (const Edge& x) const { return Len < x.Len; }
}E[20005];
struct Node {
  vector <Node*> Ed;
  unsigned Dep;
}N[20005], * Que[20005], ** Hd(Que), ** Tl(Que);
inline char Check() {
  for (unsigned i(1); i <= m; ++i) if (!(E[i].Ava))
    E[i].Fr->Ed.push_back(E[i].To), E[i].To->Ed.push_back(E[i].Fr);// printf("Link %u %u\n", E[i].Fr - N, E[i].To - N);
  for (unsigned i(2); i <= n; ++i) N[i].Dep = 0x3f3f3f3f;
  Tl = Hd = Que, N[1].Dep = 1, *(++Tl) = N + 1;
  while (Hd != Tl) {
    Node* Cur(*(++Hd));
    // printf("BFS %u %u\n", Cur - N, Cur->Dep);
    for (auto i : Cur->Ed) if (i->Dep >= 0x3f3f3f3f) i->Dep = Cur->Dep + 1, * (++Tl) = i;
  }
  for (unsigned i(1); i <= n; ++i) N[i].Ed.clear();
  return N[n].Dep < 0x3f3f3f3f;
}
//  inline void Clr() {}
signed main() {
  freopen("shortest10.in", "r", stdin);
  freopen("shortest10.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), A = RD();
  for (unsigned i(1); i <= m; ++i) E[i].Fr = N + RD(), E[i].To = N + RD(), E[i].Len = RD(), E[i].Num = i;
  // printf("Done\n");
  sort(E + 1, E + m + 1);
  for (unsigned i(1); i <= m; ++i) {
    // printf("Try %u\n", i, E[i].Num);
    E[i].Ava = 1;
    if (Check()) Ans[++Cnt] = E[i].Num;
    else E[i].Ava = 0;
    if (Cnt >= A) break;
  }
  printf("%u\n", Cnt);
  for (unsigned i(1); i <= Cnt; ++i) printf("%u ", Ans[i]); putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}