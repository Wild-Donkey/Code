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
unsigned int f[305][305], m, n, Cnt(0), sx, sy, tx, ty, hd(0), tl(1), stk(200000), t;
bool flg = 1;
char s[305];
struct Pnt {
  unsigned int x, y, dep;
  Pnt(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0) {
    x = a;
    y = b;
    dep = c;
  }
}Q[200005];
inline void Clr() {
  n = RD();
  sx = RD() + 1;
  sy = RD() + 1;
  tx = RD() + 1;
  ty = RD() + 1;
  hd = 0;
  tl = 1;
  flg = 0;
//  memset(a, 1, sizeof(a));
  memset(f, 0x3f, sizeof(f));
  memset(Q, 0, sizeof(Q));
  return;
}
void Try(Pnt x) {
  if (x.x < 1 || x.x > n || x.y < 1 || x.y > n) {
    return;
  }
  if(f[x.x][x.y] > x.dep) {
    f[x.x][x.y] = x.dep; 
    if(x.x == tx && x.y == ty) {
      flg = 1;
      return;
    }
    Q[++tl] = x; 
  }
  return;
}
void BFS() {
  Pnt *now, *to;
  Q[1] = Pnt(sx, sy, 0);
  while (tl > hd) {
    now = &Q[++hd];
//    printf("now %u %u %u\n", now->x, now->y, now->dep);
    to = &Q[stk--];
    Try(Pnt(now->x - 2, now->y - 1, now->dep + 1)); 
    Try(Pnt(now->x - 2, now->y + 1, now->dep + 1)); 
    Try(Pnt(now->x - 1, now->y - 2, now->dep + 1)); 
    Try(Pnt(now->x - 1, now->y + 2, now->dep + 1)); 
    Try(Pnt(now->x + 1, now->y - 2, now->dep + 1)); 
    Try(Pnt(now->x + 1, now->y + 2, now->dep + 1)); 
    Try(Pnt(now->x + 2, now->y - 1, now->dep + 1)); 
    Try(Pnt(now->x + 2, now->y + 1, now->dep + 1)); 
    if(flg) {
      return;
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
    BFS();
    if(f[tx][ty] <= 1000000000) {
      printf("%u\n", f[tx][ty]); 
    }
    else {
      printf("-1\n");
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

