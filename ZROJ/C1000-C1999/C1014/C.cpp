#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned a[10005], m, n;
unsigned A(1), B(1), C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Road[40005];
char Vis[10005], Flg(0);
char Move[20] = "  DLDRLDLUULURRDRU";
int Mov[10][2] = {{0, 0}, {-1, -2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}};
int Blc3[2][5][2] = {{{1, 2}, {1, -2}, {-2, 1}, {1, 2}, {1, -2}},
                    {{-1, -2}, {-1, 2}, {2, 1}, {}}}
inline void Clr() {
  n = RD(), A = B = 1, Flg = 0;
  memset(Vis, 0, sizeof(Vis));
}
inline void Print() {
  printf("1 1\n");
  for (unsigned i(1); i < (n << 2); ++i)
    printf("%u %u\n", B += Mov[Road[i]][1], A += Mov[Road[i]][0]);
}
inline void DFS(unsigned Dep, unsigned x, char y) {
  if(Dep == (n << 2)) {Flg = 1,Print(); return;}
  if((y > 2) && (x > 1) && (!(Vis[x - 1] & (1 << (y - 2)))))
    Vis[x - 1] |= (1 << (y - 2)), Road[Dep] = 1, DFS(Dep + 1, x - 1, y - 2), Vis[x - 1] ^= (1 << (y - 2));
  if(Flg) return;
  if((y > 2) && (x < n) && (!(Vis[x + 1] & (1 << (y - 2)))))
    Vis[x + 1] |= (1 << (y - 2)), Road[Dep] = 2, DFS(Dep + 1, x + 1, y - 2), Vis[x + 1] ^= (1 << (y - 2));
  if(Flg) return;
  if((y > 1) && (x > 2) && (!(Vis[x - 2] & (1 << (y - 1)))))
    Vis[x - 2] |= (1 << (y - 1)), Road[Dep] = 3, DFS(Dep + 1, x - 2, y - 1), Vis[x - 2] ^= (1 << (y - 1));
  if(Flg) return;
  if((y < 4) && (x > 2) && (!(Vis[x - 2] & (1 << (y + 1)))))
    Vis[x - 2] |= (1 << (y + 1)), Road[Dep] = 4, DFS(Dep + 1, x - 2, y + 1), Vis[x - 2] ^= (1 << (y + 1));
  if(Flg) return;
  if((y < 3) && (x > 1) && (!(Vis[x - 1] & (1 << (y + 2)))))
    Vis[x - 1] |= (1 << (y + 2)), Road[Dep] = 5, DFS(Dep + 1, x - 1, y + 2), Vis[x - 1] ^= (1 << (y + 2));
  if(Flg) return;
  if((y < 3) && (x < n) && (!(Vis[x + 1] & (1 << (y + 2)))))
    Vis[x + 1] |= (1 << (y + 2)), Road[Dep] = 6, DFS(Dep + 1, x + 1, y + 2), Vis[x + 1] ^= (1 << (y + 2));
  if(Flg) return;
  if((y > 1) && (x < n - 1) && (!(Vis[x + 2] & (1 << (y - 1)))))
    Vis[x + 2] |= (1 << (y - 1)), Road[Dep] = 7, DFS(Dep + 1, x + 2, y - 1), Vis[x + 2] ^= (1 << (y - 1));
  if(Flg) return;
  if((y < 4) && (x < n - 1) && (!(Vis[x + 2] & (1 << (y + 1)))))
    Vis[x + 2] |= (1 << (y + 1)), Road[Dep] = 8, DFS(Dep + 1, x + 2, y + 1), Vis[x + 2] ^= (1 << (y + 1));
  if(Flg) return;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    if(n == 1 || n == 2 || n == 4) {printf("No\n");continue;}
    printf("Yes\n");
    if(n >= 9) {
      Road[1] = 6;
      Road[2] = 2;
      Road[3] = 4;
      Road[4] = 6;
      Road[5] = 2;
      Road[6] = 6;
      Road[7] = 2;
      Vis[1] = 6;
      Vis[2] = 24;
      Vis[3] = 6;
      Vis[4] = 16;
      Vis[5] = 4;
      if(n == 10) {
        Road[8] = 6;
        Road[9] = 2;
        Road[10] = 6;
        Vis[6] = 16;
        Vis[7] = 4;
        Vis[8] = 16;
        DFS(11, 8, 4);
      } else DFS(8, 5, 2);
    } else {
  //  Vis[1] = 22, Vis[n] = 18, DFS(5, A = 1, B = 2);
      Vis[1] = 2, DFS(1, 1, 1);
    }
//  for (unsigned i(1); i <= n; ++i) {
//    a[i] = RD();
//  }
  }
  return Wild_Donkey;
}
/*
5
10
10
10
10
10

UR
DR
LD
LU

UL
RD
DL
UL
RU
RD
DR



LD
UL
RU
DL

UL
RD
RU
DR
LD
UR
DR

*/
