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
unsigned int f[105][105], m, n, Cnt(0), A, B, C, D, sx, sy, tx, ty, hd(0), tl(1);
bool b[10005];
char s[105][105];
struct Pnt {
  unsigned int x, y, dep;
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
void BFS() {
  Pnt now, to;
  Q[1] = Pnt(sx, sy, 0);
  while (tl > hd) {
    now = Q[++hd];
//    printf("now %u %u %u\n", now.x, now.y, now.dep);
    to = now;
    to.dep = now.dep + 1;
    to.x = now.x - 1;
    if(to.x && s[to.x][to.y - 1] != '#') {
      if(to.dep < f[to.x][to.y]) {
        if(to.x == tx && to.y == ty) {
          printf("%u\n", to.dep);
          return;
        }
        f[to.x][to.y] = to.dep;
        Q[++tl] = to;
      }
    }
    to.x = now.x + 1;
    if(to.x <= n && s[to.x][to.y - 1] != '#') {
      if(to.dep < f[to.x][to.y]) {
        if(to.x == tx && to.y == ty) {
          printf("%u\n", to.dep);
          return;
        }
        f[to.x][to.y] = to.dep;
        Q[++tl] = to;
      }
    }
    to.x = now.x;
    to.y = now.y - 1;
    if(to.y && s[to.x][to.y - 1] != '#') {
      if(to.dep < f[to.x][to.y]) {
        if(to.x == tx && to.y == ty) {
          printf("%u\n", to.dep);
          return;
        }
        f[to.x][to.y] = to.dep;
        Q[++tl] = to;
      }
    }
    to.y = now.y + 1;
    if(to.y <= m && s[to.x][to.y - 1] != '#') {
      if(to.dep < f[to.x][to.y]) {
        if(to.x == tx && to.y == ty) {
          printf("%u\n", to.dep);
          return;
        }
        f[to.x][to.y] = to.dep;
        Q[++tl] = to;
      }
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    gets(s[i]);
  }
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= m; ++j) {
//      putchar(s[i][j]);
      if(s[i][j - 1] == 'S') {
        s[i][j - 1] = '.';
        sx = i;
        sy = j;
      }
      if(s[i][j - 1] == 'T') {
        s[i][j - 1] = '.';
        tx = i;
        ty = j;
      }
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
3 3
S#T
.#.
...
*/

