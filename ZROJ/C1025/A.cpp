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
const double Tin(0.00000001), Inf(1000000000);
double Ans(0), Low(0), Top(1000000001);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
struct Node;
struct Edge {
  Node* To;
  unsigned Val;
};
struct Node {
  vector<Edge> To;
  unsigned Dis, Dis2;
  char Vis;
}N[10005], * St, * Ki, * Des;
priority_queue <pair<unsigned, unsigned> > Q;
inline void Dij () {
  for (unsigned i(1); i <= n; ++i) N[i].Dis = 0x3f3f3f3f;
  Q.push(make_pair(0x3f3f3f3f, Ki - N));
  Ki->Dis = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Vis) continue;
    Cur->Vis = 1;
    for (auto i:Cur->To) {
      if(i.To->Dis > Cur->Dis + i.Val) {
        i.To->Dis = Cur->Dis + i.Val;
        Q.push(make_pair(0x3f3f3f3f - i.To->Dis, i.To - N));
      }
    }
  }
}
inline void Check() {
  for (unsigned i(1); i <= n; ++i) N[i].Vis = 0, N[i].Dis2 = 0x3f3f3f3f;
  Q.push(make_pair(0x3f3f3f3f, St - N));
  St->Dis2 = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
//    printf("BFS %u\n", Cur - N);
    Q.pop();
    if (Cur->Vis) continue;
    Cur->Vis = 1;
    if ((Cur->Dis2 / Ans) >= Cur->Dis) continue;
    if (Cur == Des) {Flg = 1; return;}
    for (auto i:Cur->To) {
      if(i.To->Dis2 > Cur->Dis2 + i.Val) {
        i.To->Dis2 = Cur->Dis2 + i.Val;
        Q.push(make_pair(0x3f3f3f3f - i.To->Dis2, i.To - N));
      }
    }
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].To.push_back((Edge){N + B, C});
    N[B].To.push_back((Edge){N + A, C});
  }
  St = N + RD(), Ki = N + RD(), Des = N + RD();
  Dij();
  while (Low + Tin < Top) {
    Ans = (Low + Top) / 2;
    Flg = 0, Check();
    if(Flg) Top = Ans;
    else Low = Ans;
  }
  if(Ans > Inf) printf("-1\n");
  else printf("%lf\n", Ans);
//  }
  return Wild_Donkey;
}

