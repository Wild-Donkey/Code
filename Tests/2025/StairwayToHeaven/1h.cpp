#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
int RDsg() {
  int RTm = 0;
  char Rchr = getchar(), Flg = 0;
  while ((Rchr < '0' || Rchr > '9') && Rchr != '-') Rchr = getchar();
  if (Rchr == '-') Flg = 1, Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return Flg ? -RTm : RTm;
}
unsigned n, m, k;
unsigned a[1005][1005];
priority_queue<pair<int, pair<unsigned short, unsigned short> > > Lst;
unordered_set<unsigned short> Delx, Dely;
unsigned OKx[1005], OKy[1005];
signed main() {
  n = RD(), m = RD(), k = RD();
  for (unsigned short i = 1; i <= n; ++i) {
    for (unsigned short j = 1; j <= m; ++j) {
      int TmpA = RDsg();
      Lst.push({ TmpA, make_pair(i, j) });
    }
  }

  for (unsigned i = 1, j = 0; i <= k; ++i) {
    pair<int, pair<unsigned short, unsigned short> > Node;
    char Flg = 0;
    do {
      Node = Lst.top();
      if (Delx.count(Node.second.first) || Dely.count(Node.second.second))
        Lst.pop();
      else
        Flg = 1, Lst.pop();
    } while (!Flg);
    // printf("Del %d %u %u\n", Node.first, Node.second.first, Node.second.second);
    Delx.insert(Node.second.first);
    Dely.insert(Node.second.second);
  }
  for (unsigned j = 1, J = 0; j <= n; ++j) if (!Delx.count(j)) OKx[j] = ++J;
  for (unsigned j = 1, J = 0; j <= m; ++j) if (!Dely.count(j)) OKy[j] = ++J;
  // for (unsigned i = 1; i <= n; ++i) printf("%u ", OKx[i]);
  // putchar(0x0A);
  // for (unsigned i = 1; i <= m; ++i) printf("%u ", OKy[i]);
  // putchar(0x0A);
  while (Lst.size()) {
    auto Node = Lst.top();
    a[OKx[Node.second.first]][OKy[Node.second.second]] = Node.first;
    Lst.pop();
  }
  n -= k, m -= k;
  for (unsigned i = 1; i <= n; ++i) {
    for (unsigned j = 1; j < m; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("%d\n", a[i][m]);
  }
  return 0;
}