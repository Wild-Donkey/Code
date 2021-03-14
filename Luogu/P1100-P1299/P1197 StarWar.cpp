#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int m, n, k, a[400005], b[200005], c[200005], ans[200005], Net;
inline int RD() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
struct Edge;
struct Node {
  bool Flg;
  Node *Fa;
  Edge *Fst;
  Node *Fnd() {
    if (this->Fa == this) {
      return this;
    }
    this->Fa = this->Fa->Fnd();
    return this->Fa;
  }
} N[400005];
struct Edge {
  Edge *Nxt;
  Node *To;
} E[400005], *cnte(E);
void Clr() {
  n = RD();
  m = RD();
  // memset(L, 0, sizeof(L));
  memset(N, 0, sizeof(N));
  for (register int i(0); i < n; ++i) {
    N[i].Fa = N + i;
  }
  return;
}
void Add(Node *x, Node *y) {
  if (x->Fnd() == y->Fnd()) {
    return;
  }
  Net--;
  x->Fa->Fa = y->Fa;
  return;
}
void Lnk(Node *x, Node *y) {
  (++cnte)->Nxt = x->Fst;
  x->Fst = cnte;
  cnte->To = y;
  return;
}
void Del(Node *x) {
  x->Flg = 0;
  Edge *Sid(x->Fst);
  while (Sid) {
    if (!(Sid->To->Flg)) {
      Add(x, Sid->To);
    }
    Sid = Sid->Nxt;
  }
  return;
}
int main() {
  // freopen("P1874.in", "r", stdin);
  // freopen("P1874.out", "w", stdout);
  Clr();
  for (register int i(1); i <= m; ++i) {
    b[i] = RD();
    c[i] = RD();
  }
  k = RD();
  Net = n - k;
  for (register int i(1); i <= k; ++i) {
    a[i] = RD();
    N[a[i]].Flg = 1;
  }
  for (register int i(1); i <= m; ++i) {
    if ((!N[b[i]].Flg) && (!N[c[i]].Flg)) {
      Add(N + b[i], N + c[i]);
    } else {
      Lnk(N + b[i], N + c[i]);
      Lnk(N + c[i], N + b[i]);
    }
  }
  // ans[k] = Net;
  for (register int i(k); i >= 1; --i) {
    ans[i] = Net;
    ++Net;
    Del(N + a[i]);
  }
  printf("%d\n", Net);
  for (register int i(1); i <= k; ++i) {
    printf("%d\n", ans[i]);
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}