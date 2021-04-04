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
int n, m, A, B, C, Ecnt, Fthr[305];
struct Edge {
  int Val, To_1, To_2;
  bool operator <(const Edge &x) const {
    return this->Val < x.Val;
  }
} E[100005],*cnte, *a[305][305];
void Clr() {
  memset(E, 0, sizeof(E));
  memset(a, 0, sizeof(a));
  cnte = E;
  Ecnt = 0;
  return;
}
int Fnd(const int &x) {
  int x_tmp(x);
  while (x_tmp!=Fthr[x_tmp]){
    x_tmp = Fthr[x_tmp];
  }
  Fthr[x] = x_tmp;
  return x_tmp;
}

void Add(Edge *x) {
  Fthr[Fnd(x->To_1)] = Fthr[x->To_2];
  return;
}
void Kruskal(Edge *x) {
  if(Fnd(x->To_1)==Fnd(x->To_2)) {
    return;
  }
  //printf("Add %d\n", x - E);
  Add(x);
  ++Ecnt;
  return;
}
int main() {
  //freopen("P2330_0.in", "r", stdin);
  //freopen("P2330.out", "w", stdout);
//  printf("Done1\n");
  Clr();
  n = RD();
  m = RD();
  //  printf("Done2\n");
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
    if(a[A][B]) {
      if(a[A][B]->Val > C) {
        a[A][B]->Val = C;
      }
      continue;
    }
    (++cnte)->To_1 = A;
    cnte->To_2 = B;
    cnte->Val = C;
    a[A][B] = cnte;
    a[B][A] = cnte;
  }
  sort(E + 1, cnte + 1);
  for (register int i(1); i <= n; ++i) {
    Fthr[i] = i;
  }
  for (register Edge *i(E + 1); i <= cnte; ++i) {
    Kruskal(i);
    if(Ecnt == n - 1) {
      printf("%d %d\n", n - 1, i->Val);
      return 0;
    }
  }
  return 0;
}
