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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Pnt[10005][2], m, n, CntPnt, CntFly, Cnt(0), A, B, C, D, Minx(0x7f3f3f3f), Miny(0x7f3f3f3f), Maxx(0), Maxy(0);
char Fly[505][505], Wea[505][505], Sid[505][505], Ava[505][505][4];
inline void Clr() {}
inline void DFS(unsigned x, unsigned y) {
  Wea[x][y] = 1;
  if(x && (!Ava[x][y][1]) && (!Sid[x - 1][y]) && (!Wea[x - 1][y])) {
    DFS(x - 1, y);
  }
  if(y && (!Ava[x][y][3]) && (!Sid[x][y - 1]) && (!Wea[x][y - 1])) {
    DFS(x, y - 1);
  }
  if((x < Maxx) && (!Ava[x][y][0]) && (!Sid[x + 1][y]) && (!Wea[x + 1][y])) {
    DFS(x + 1, y);
  }
  if((y < Maxy) && (!Ava[x][y][2]) && (!Sid[x][y + 1]) && (!Wea[x][y + 1])) {
    DFS(x, y + 1);
  }
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), CntFly = RD();
  for (register unsigned i(1); i <= CntFly; ++i) {
    A = RD(), B = RD();
    Fly[A][B] = 1;
  }
  CntPnt = RD();
  for (register unsigned i(1); i <= CntPnt; ++i) {
    Pnt[i][0] = RDsg() + 1000000000, Pnt[i][1] = RDsg() + 1000000000; 
    Minx = min(Pnt[i][0], Minx);
    Miny = min(Pnt[i][1], Miny);
  }
  for (register unsigned i(1); i <= CntPnt; ++i) {
    Pnt[i][0] -= Minx, Pnt[i][1] -= Miny;
    Maxx = max(Maxx, Pnt[i][0]);
    Maxy = max(Maxy, Pnt[i][1]);
  }
  if((Maxx > n) || (Maxy > m)) {
    printf("0\n");
    return 0;
  }
  Pnt[0][0] = Pnt[CntPnt][0];
  Pnt[0][1] = Pnt[CntPnt][1];
  for (register unsigned k(1), Delx, Dely; k <= CntPnt; ++k) {
    if(Pnt[k - 1][0] < Pnt[k][0]) {
      A = Pnt[k - 1][0], B = Pnt[k - 1][1];
      C = Pnt[k][0], D = Pnt[k][1];
    } else {
      C = Pnt[k - 1][0], D = Pnt[k - 1][1];
      A = Pnt[k][0], B = Pnt[k][1];
    }
    printf("Link %u %u %u %u\n", A, B, C, D);
    Delx = C - A;
    if(Delx) {
      if(B ^ D) {
        if(B < D) {
          Dely = D - B;
          if(Delx > Dely) {
            for (register unsigned i(A), j(B); i <= C; ++i) {
              if((j - B) * Delx == Dely * (i - A)) {
                Sid[i][j] = 1, ++j;
              } else {
                if((j - B) * Delx == Dely * (i - A + 1)) {
                  
                }
                Ava[i][j][3] ^= 1;
                Ava[i][j - 1][2] ^= 1;
              }
            }
          } else {
            for (register unsigned i(A), j(B); j <= D; ++j) {
              if((j - B) * Delx == Dely * (i - A)) {
                Sid[i][j] = 1, ++i;
              } else {
                Ava[i][j][1] ^= 1;
                Ava[i - 1][j][0] ^= 1;
              }
            }
          }
        } else {
          Dely = B - D;
          if(Delx > Dely) {
            for (register unsigned i(A), j(B); i <= C; ++i) {
              if((B - j) * Delx == Dely * (i - A)) {
                Sid[i][j] = 1, --j;
              } else {
                Ava[i][j][2] ^= 1;
                Ava[i][j + 1][3] ^= 1;
              }
            }
          } else {
            for (register unsigned i(A), j(B); j >= D && j < 0x3f3f3f3f; --j) {
              if((B - j) * Delx == Dely * (i - A)) {
                Sid[i][j] = 1, ++i;
              } else {
                Ava[i][j][1] ^= 1;
                Ava[i - 1][j][0] ^= 1;
              }
            }
          }
        }
      } else {
        for (register unsigned i(A); i <= C; ++i) {
          Sid[i][B] = 1;
        }
      }
    } else {
      if(B > D) swap(B, D);
      for (register unsigned i(B); i <= D; ++i) {
        Sid[A][i] = 1;
      }
    }
  }
  for (register unsigned i(0); i <= Maxx; ++i) {
    if((!Sid[i][0]) && (!Wea[i][0])) {
      DFS(i, 0);
    }
    if((!Sid[i][Maxy]) && (!Wea[i][Maxy])) {
      DFS(i, Maxy);
    }
  }
  for (register unsigned i(0); i <= Maxy; ++i) {
    if((!Sid[0][i]) && (!Wea[0][i])) {
      DFS(0, i);
    }
    if((!Sid[Maxx][i]) && (!Wea[Maxx][i])) {
      DFS(Maxx, i);
    }
  }
  for (register unsigned i(Maxy); i < 0x3f3f3f3f; --i) {
    for (register unsigned j(0); j <= Maxx; ++j) {
      putchar(Wea[j][i] + '0');
    }
    putchar('\n');
  }
  for (register unsigned i(Maxy); i < 0x3f3f3f3f; --i) {
    for (register unsigned j(0); j <= Maxx; ++j) {
      putchar(Ava[j][i][0] + '0');
      putchar(Ava[j][i][1] + '0');
      putchar(Ava[j][i][2] + '0');
      putchar(Ava[j][i][3] + '0');
      putchar(' ');
    }
    putchar('\n');
  }
//  printf("");
//  }
  return Wild_Donkey;
}
/*
6 7 2
2 5
4 5
8
1 4
3 3
4 1
5 3
7 4
5 5
4 7
3 5

10 10 0
6
1 0
4 2
1 3
3 2
1 1
0 3
4
0 0
1 0
0 3
1 3
4
0 0
0 1
3 0
3 1
*/
