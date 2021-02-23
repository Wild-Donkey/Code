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
int m, n, k, ans(0), A, B, e;
bool flg(0);
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
  Edge *Fst;
  Node *MPr;
} L[505], R[505];
struct Edge {
  Edge *Nxt;
  Node *To;
} E[50005], *cnte(E);
void Clr() {
  n = RD();
  m = RD();
  if (m < n) {
    swap(m, n);
    flg = 1;
  }
  e = RD();
  memset(L, 0, sizeof(L));
  memset(R, 0, sizeof(R));
  memset(E, 0, sizeof(E));
  return;
}
void Lnk(Node *x, Node *y) {
  (++cnte)->To = y;
  cnte->Nxt = x->Fst;
  x->Fst = cnte;
  return;
}
bool Try(Node *x) {
  // printf("Try %d\n", x - L);
  /*if (x - L == 106) {
    x = L + 106;
  }*/
  x->Flg = 1;
  Edge *Sid(x->Fst);
  while (Sid) {
    if (!(Sid->To->Flg)) {
      if (Sid->To->MPr) {
        if (Sid->To != x->MPr) {
          if (!(Sid->To->MPr->Flg)) {
            if (Try(Sid->To->MPr)) {
              Sid->To->MPr = x;
              x->MPr = Sid->To;
              x->Flg = 0;
              return 1;
            } else {
              Sid->To->Flg = 1;
            }
          }
        }
      } else {
        Sid->To->MPr = x;
        x->MPr = Sid->To;
        ++ans;
        return 1;
      }
    }
    Sid = Sid->Nxt;
  }
  return 0;
}
int main() {
  // freopen("P1874.in", "r", stdin);
  // freopen("P1874.out", "w", stdout);
  Clr();
  for (register int i(1); i <= e; ++i) {
    A = RD();
    B = RD();
    if (flg) {
      swap(A, B);
    }
    Lnk(L + A, R + B);
  }
  for (register int i(1); i <= n; ++i) {
    Edge *Sid(L[i].Fst);
    while (Sid) {
      if (Sid->To->MPr) {
        if (Try(Sid->To->MPr)) {
          Sid->To->MPr = L + i;
          L[i].MPr = Sid->To;
          Sid->To->Flg = 0;
          break;
        }
      } else {
        Sid->To->MPr = L + i;
        L[i].MPr = Sid->To;
        Sid->To->Flg = 0;
        ++ans;
        break;
      }
      Sid = Sid->Nxt;
    }
  }
  printf("%d\n", ans);
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}