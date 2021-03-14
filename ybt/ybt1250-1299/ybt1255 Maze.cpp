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
inline unsigned int RD() {
  unsigned int intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned int f[6][6], m, n, Cnt(0), A, B, C, D, hd(0), tl(1), stk(10000);
bool a[6][6];
struct Pnt {
  unsigned int x, y, dep;
  Pnt *Lst;
  Pnt(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0) {
    x = a;
    y = b;
    dep = c;
  }
}Q[10005];
//inline void Clr() {
//  n = RD();
//  memset(a, 0, sizeof(a));
//}
void Print(Pnt *x) {
  if(x->x == 1 && x->y == 1) {
    printf("(0, 0)\n");
    return;
  }
  Print(x->Lst);
  printf("(%u, %u)\n", x->x - 1, x->y - 1);
} 
void BFS() {
  Pnt *now, *to;
  Q[1] = Pnt(1, 1, 0);
  while (tl > hd) {
    now = &Q[++hd];
//    printf("now %u %u %u\n", now.x, now.y, now.dep);
    to = &Q[stk--];
    to->dep = now->dep + 1;
    to->x = now->x - 1;
    to->y = now->y;
    to->Lst = now;
    if(to->x && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        if(to->x == 5 && to->y == 5) {
          Print(to);
          return;
        }
        f[to->x][to->y] = to->dep;
        Q[++tl] = *to;
      }
    }
    to->x = now->x + 1;
    if(to->x <= 5 && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        if(to->x == 5 && to->y == 5) {
          Print(to);
          return;
        }
        f[to->x][to->y] = to->dep;
        Q[++tl] = *to;
      }
    }
    to->x = now->x;
    to->y = now->y - 1;
    if(to->y && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        if(to->x == 5 && to->y == 5) {
          Print(to);
          return;
        }
        f[to->x][to->y] = to->dep;
        Q[++tl] = *to;
      }
    }
    to->y = now->y + 1;
    if(to->y <= 5 && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        if(to->x == 5 && to->y == 5) {
          Print(to);
          return;
        }
        f[to->x][to->y] = to->dep;
        Q[++tl] = *to;
      }
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  for (register unsigned int i(1); i <= 5; ++i) {
    for (register unsigned int j(1); j <= 5; ++j) {
      a[i][j] = !(RD());
    }
  }
  memset(f, 0x3f, sizeof(f));
  BFS();
//  printf("%d\n", f[tx][ty]); 
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/

