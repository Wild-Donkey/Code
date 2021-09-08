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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a, m, n, Set[15], A, B, C, D, t, Ans(0x3f3f3f3f), Tmp(0);
unsigned Dist[1000005], Tl(0), Hd(0), Last(0);
char b[2000050], S[15], Flg, Prt(0);
struct Edge;
struct Node {
  Edge* Fst;
  unsigned Dist;
}N[1000005], * Q[1000005];
struct Edge {
  Node* To;
  Edge* Nxt;
}E[10000005], * CntE(E);
inline void Link(Node* x, Node* y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
}
void Print(unsigned x) {
  for (unsigned i = Ans; i; --i) putchar(b[i] + '0');
  putchar('\n');
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  a = RD(), n = RD();
  for (unsigned i(0); i < n; ++i) S[RD()] = 1;
  n = 0;
  for (char i(0); i < 10; ++i) if (!S[i]) Set[++n] = i;
  for (unsigned i(1); i < a; ++i) {
    for (char j(1); j <= n; ++j) {
      Link(N + ((i * 10 + Set[j]) % a), N + i);
    }
  }
  // for (unsigned i(1); i <= (m >> 1); ++i) swap(a[i], a[m - i + 1]);
// for (unsigned i(1); i <= m; ++i) ++Cnt[a[i]];
  for (unsigned i(1); i < a; ++i) N[i].Dist = 0x3f3f3f3f;
  Q[++Tl] = N;
  while (Tl ^ Hd) {
    Node* Now(Q[++Hd]);
    Edge* Sid(Now->Fst);
    // printf("BFS %u %u\n", Now - N, Now->Dist);
    while (Sid) {
      if (Sid->To->Dist > Now->Dist + 1) {
        Sid->To->Dist = Now->Dist + 1;
        Q[++Tl] = Sid->To;
      }
      Sid = Sid->Nxt;
    }
  }
  // for (unsigned i(1); i <= a; ++i) printf("Dist%u = %u\n", i, N[i].Dist);
  for (char i(1); i <= n; ++i) if ((Set[i]) && (Ans > N[Tmp = (Set[i] % a)].Dist)) Ans = N[Tmp].Dist, Last = Tmp, Prt = Set[i];
  if (Ans > 2000000) { printf("-1\n");return 0; }
  for (unsigned i(1); i <= Ans; ++i) {
    putchar(Prt + '0');
    for (char j(1); j <= n; ++j)
      if (Ans - i == N[Tmp = ((Last * 10 + Set[j]) % a)].Dist) { Last = Tmp, Prt = Set[j]; break; }
  }
  putchar(Prt + '0'), putchar('\n');
  // system("pause");
  return Wild_Donkey;
}
/*
30 9
0 1 2 3 4 5 6 7 9
100000 9
0 1 2 3 4 5 6 7 9
*/