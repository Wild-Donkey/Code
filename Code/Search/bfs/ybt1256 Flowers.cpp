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
unsigned int f[205][205], m, n, Cnt(0), sx, sy, tx, ty, hd(0), tl(1), stk(100000), t;
bool a[205][205];
char s[205];
struct Pnt {
  unsigned int x, y, dep;
  Pnt(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0) {
    x = a;
    y = b;
    dep = c;
  }
}Q[100005];
inline void Clr() {
  n = RD();
  m = RD();
  hd = 0;
  tl = 1;
  memset(a, 1, sizeof(a));
  memset(f, 0x3f, sizeof(f));
  memset(Q, 0, sizeof(Q));
  return;
}
void BFS() {
  Pnt *now, *to;
  Q[1] = Pnt(sx, sy, 0);
  while (tl > hd) {
    now = &Q[++hd];
//    printf("now %u %u %u\n", now->x, now->y, now->dep);
    to = &Q[stk--];
    to->dep = now->dep + 1;
    to->x = now->x - 1;
    to->y = now->y;
    if(to->x && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        f[to->x][to->y] = to->dep;
        if(to->x == tx && to->y == ty) {
          return;
        }
        Q[++tl] = *to;
      }
    }
    to->x = now->x + 1;
    if(to->x <= n && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        f[to->x][to->y] = to->dep;
        if(to->x == tx && to->y == ty) {
          return;
        }
        Q[++tl] = *to;
      }
    }
    to->x = now->x;
    to->y = now->y - 1;
    if(to->y && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        f[to->x][to->y] = to->dep;
        if(to->x == tx && to->y == ty) {
          return;
        }
        Q[++tl] = *to;
      }
    }
    to->y = now->y + 1;
    if(to->y <= m && a[to->x][to->y]) {
      if(to->dep < f[to->x][to->y]) {
        f[to->x][to->y] = to->dep;
        if(to->x == tx && to->y == ty) {
          return;
        }
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
  t = RD();
  for(register unsigned int T(1); T <= t; ++T) {
    Clr();
    for (register unsigned int i(1); i <= n; ++i) {
      gets(s);
      for (register unsigned int j(1); j <= m; ++j) {
//        putchar(s[i][j]);
        if(s[j - 1] == 'S') {
          sx = i;
          sy = j;
        }
        if(s[j - 1] == 'E') {
          tx = i;
          ty = j;
        }
        if(s[j - 1] == '#') {
          a[i][j] = 0;
        }
      }
    }
    BFS();
    if(f[tx][ty] <= 1000000000) {
      printf("%u\n", f[tx][ty]); 
    }
    else {
      printf("oop!\n");
    }
  }
//  printf("%d\n", f[tx][ty]); 
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
3 4
.S..
###.
..E.

3 4
.S..
.E..
....

3 4
.S..
####
..E.
*/

