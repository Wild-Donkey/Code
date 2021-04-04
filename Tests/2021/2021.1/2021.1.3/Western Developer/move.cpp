#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  char ich(getchar());
  unsigned long long intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  //  printf("RD %d\n", intmp);
  return intmp;
}
unsigned long long n, k, m, hd(0), tl(1), A, B, C;
struct Edge;
struct Node {
  unsigned long long D[15];
  Edge *Fst;
  unsigned short flg;

} N[10005], *S, *T, *Q[1000005], *now;
struct Edge {
  unsigned long long val;
  Edge *Nxt;
  Node *To;
} E[50005], *Sid, *cnte(E);
void Lnk(Node *x, Node *y, const unsigned long long &z) {
  (++cnte)->Nxt = x->Fst;
  x->Fst = cnte;
  cnte->To = y;
  cnte->val = z;
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("move.in", "r", stdin);
   freopen("move.out", "w", stdout);
  n = RD();
  m = RD();
  k = RD();
  S = N + RD();
  T = N + RD();
  // printf("Rat = %lf\n", rat);
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
    Lnk(N + A, N + B, C);
    Lnk(N + B, N + A, C);
  }
  for (register int i(0); i < n; ++i) {
    N[i].flg = 0;
    for (register int j(0); j <= k; ++j) {
      N[i].D[j] = 0x3f3f3f3f3f3f3f3f;
    }
  }
  for (register int i(0); i <= k; ++i) {
    S->D[i] = 1;
  }
  Q[0] = S;
  while (hd < tl) {
    now = Q[hd++];
    now->flg++;
    Sid = now->Fst;
    while (Sid) {
      unsigned long long tmp(now->D[0] + Sid->val);
      if (tmp < Sid->To->D[0]) {
        Sid->To->D[0] = tmp;
      }
      for (register int i(1); i <= k; ++i) {
        tmp = min(now->D[i - 1], now->D[i] + Sid->val);
        if (tmp < Sid->To->D[i]) {
          Sid->To->D[i] = tmp;
        }
      }
      // if (Sid->To->flg < 100) {
      Q[tl++] = Sid->To;
      //}
      Sid = Sid->Nxt;
    }
  }
  printf("%lld\n", T->D[k]);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
5 6 1
0 3
3 4 5
0 1 5
0 2 100
1 2 5
2 4 5
2 4 3

*/
