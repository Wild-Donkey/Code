#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
struct Edge;
struct Edge_;
struct Node {
  Edge *Fst;
  int Dst;
  bool InStk;
  /*const bool operator <(const Node &x) const{
    return this->Dst > x.Dst;
  }*/
} N[100005];
struct Edge {
  Node *To;
  Edge *Nxt;
  int Val;
} E[400005], *cnte(E);
priority_queue <pair<int, int> > q;
int n, m, A, B, C, s;
void Lnk(const int &x, const int &y) {
  (++cnte)->To = N + y;
  cnte->Nxt = N[x].Fst;
  N[x].Fst = cnte;
  cnte->Val = -C;
  return;
}
void Dijkstra() {
  q.push(make_pair(-N[s].Dst, s));
  Node *now;
  while (!q.empty()) {
    now = N + q.top().second;
    //printf("%d\n", now.Dst);
    q.pop();
    if(now->InStk) {
      continue;
    }
    now->InStk = 1;
    for (Edge *Sid(now->Fst); Sid; Sid = Sid->Nxt) {
      if (Sid->To->Dst < now->Dst + Sid->Val)
        if (!Sid->To->InStk) {
          Sid->To->Dst = now->Dst + Sid->Val;
          q.push(make_pair(Sid->To->Dst, Sid->To - N));
        }
    }
  }
  return;
}
int main() {
  //freopen("P4779_0.in", "r", stdin);
  //freopen("P2746.out", "w", stdout);
//  printf("Done1\n");
  n = RD();
  m = RD();
  s = RD();
//  printf("Done2\n");
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
    Lnk (A, B);
    //Lnk (B, A);
  }
//  printf("Done3\n");
  for (register int i(1); i <= n; ++i) {
    N[i].Dst = -0x3f3f3f3f;
  }
  N[s].Dst = 0;
  Dijkstra();
  for (register int i(1); i <= n; ++i) {
    printf("%d ", -N[i].Dst);
  }
  return 0;
}
