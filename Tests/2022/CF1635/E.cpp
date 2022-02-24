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
unsigned a[10005], m, n;
unsigned A, B, C(0), D(0), t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
struct Node {
  vector<pair<Node*, char> > To;
  vector<Node*> E;
  unsigned Idg, Pos;
  char Col;
}N[200005], * Q[200005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    C = RD(), A = RD(), B = RD();
    N[A].To.push_back(make_pair(N + B, C & 1));
    N[B].To.push_back(make_pair(N + A, C & 1));
  }
  for (unsigned i(1); i <= n; ++i) if (!(N[i].Col)) {
    unsigned Hd(0), Tl(0);
    (Q[++Tl] = N + i)->Col = 1;
    while (Hd ^ Tl) {
      Node* Cur(Q[++Hd]);
      // printf("BFS %u %u\n", Cur - N, Cur->Col);
      for (auto j : Cur->To) if (((j.first)->Col) ^ (Cur->Col) ^ 3) {
        (j.first)->Col |= (Cur->Col ^ 3);
        if ((j.first)->Col == 3) { Flg = 1; break; }
        Q[++Tl] = j.first;
      }
      if (Flg) break;
    }
    if (Flg) break;
  }
  if (Flg) { printf("NO\n"); return 0; }
  for (unsigned i(1); i <= n; ++i) {
    Node* Cur(N + i);
    for (auto j : Cur->To) if (j.second ^ ((Cur->Col) & 1)) Cur->E.push_back(j.first), ++((j.first)->Idg);
  }
  // printf("Done\n");
  C = D = 0;
  for (unsigned i(1); i <= n; ++i) if (!(N[i].Idg)) Q[++D] = N + i;
  while (D ^ C) {
    Node* Cur(Q[++C]);
    // printf("BFS %u %u %u\n", C, D, Cur - N);
    Cur->Pos = ++Cnt;
    for (auto i : Cur->E) if (!(--(i->Idg))) Q[++D] = i;
  }
  if (Cnt < n) { printf("NO\n"); return 0; }
  printf("YES\n");
  for (unsigned i(1); i <= n; ++i) {
    printf("%c %u\n", (((N[i].Col) & 1) ? 'R' : 'L'), N[i].Pos);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}