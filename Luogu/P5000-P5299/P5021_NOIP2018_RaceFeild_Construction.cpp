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
unsigned L(1), R(0), Mid;
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<pair<Node*, unsigned>> E;
  Node* Fa;
  unsigned f, g;
}N[50005];
inline unsigned Pre(Node* x) {
  // printf("%u %u\n", x - N, R);
  unsigned Fst(0), Sec(0);
  for (auto i : x->E) if (i.first != x->Fa) {
    Node* Cur(i.first);
    Cur->Fa = x;
    unsigned Rt(Pre(Cur) + i.second);
    if (Fst <= Rt) Sec = Fst, Fst = Rt;
    else if (Sec <= Rt) Sec = Rt;
  }
  R = max(R, Fst + Sec);
  return Fst;
}
inline void DFS(Node* x, unsigned ToFa) {
  x->f = 0;
  multiset<unsigned> S;
  unsigned Wait(0);
  for (auto i : x->E) if (i.first != x->Fa) {
    Node* Cur(i.first);
    DFS(Cur, i.second);
    x->f += Cur->f;
    if (Cur->g) S.insert(Cur->g);
  }
  while (S.size() && (*(--S.end()) >= Mid)) S.erase(--S.end()), ++(x->f);
  while (S.size() > 1) {
    unsigned Ori(*(S.begin()));
    multiset<unsigned>::iterator It(S.lower_bound(Mid - Ori));
    if (It != S.end()) S.erase(It), ++(x->f);
    else Wait = *(S.begin());
    S.erase(S.begin());
  }
  if (S.size()) Wait = *(S.rbegin());
  if (Wait + ToFa >= Mid) ++(x->f), x->g = 0;
  else x->g = Wait + ToFa;
  // printf("%u f %u g %u\n", x - N, x->f, x->g);
}
//  inline void Clr() {}
signed main() {
  // freopen("P5021_8.in", "r", stdin);
  // freopen("P5021.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].E.push_back(make_pair(N + B, C));
    N[B].E.push_back(make_pair(N + A, C));
  }
  Pre(N + 1);
  while (L ^ R) {
    Mid = ((L + R + 1) >> 1), DFS(N + 1, 0);
    // fprintf(stderr, "[%u, %u] %u: %u\n", L, R, Mid, N[1].f);
    if (N[1].f >= m) L = Mid;
    else R = Mid - 1;
  }
  printf("%u\n", L);
  //  }
  system("pause");
  return Wild_Donkey;
}