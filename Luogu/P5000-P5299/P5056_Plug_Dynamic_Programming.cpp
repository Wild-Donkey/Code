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
#include <set>
#include <string>
#include <unordered_map>
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
unordered_map<unsigned, unsigned> List;
unsigned long long f[13][12][42005];
unsigned g[42005][13], Find[42005], Stack[13], STop(0), Con(0), Now(0);
unsigned A, B, C, D, t, m, n, N;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[13][13], Flg(0);
inline void Nxt(unsigned& x, unsigned& y) {
  if (y + 1 >= m) ++x, y = 0; else ++y;
}
inline void Lst(unsigned& x, unsigned& y) {
  if (y) --y; else --x, y = m - 1;
}
inline void DFS(unsigned Dep) {
//  printf("%u %u Cnt %u\n", Dep, Now, Cnt);
  if(Dep > m) {
    if(!Cnt) {
      List[Now] = ++Con, Find[Con] = Now;
      for (unsigned i(0), j(0); i <= m; ++i, j += 2) {
        char Cur((Now >> j) & 3);
        if(Cur) {
          if(Cur == 1) Stack[++STop] = i;
          else g[Con][Stack[STop]] = i, g[Con][i] = Stack[STop--];
        }
      }
//      printf("OK %u %u\n", Con, Now);
//      for (unsigned i(0); i <= m; ++i) printf("%u ", g[Con][i]); putchar(0x0A);
    }
    return;
  }
  DFS(Dep + 1);
  Now ^= (1 << (Dep << 1)), ++Cnt;
  DFS(Dep + 1);
  --Cnt, Now ^= (1 << (Dep << 1));
  if(Cnt) {
    Now ^= (2 << (Dep << 1)), --Cnt;
    DFS(Dep + 1);
    ++Cnt, Now ^= (2 << (Dep << 1));
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), N = ((1 << (m = RD()) + 1) << 1), DFS(0);
  for (unsigned i(1); i <= n; ++i) scanf("%s", a[i]);
  for (unsigned i(1); (i <= n) && (!Flg); ++i) for (unsigned j(0); j < m; ++j)
    if (a[i][j] ^ '*') { Flg = 1, A = i, B = j;break; }
  if (!Flg) { printf("1\n"); return 0; } Flg = 0;
  for (unsigned i(n); i && (!Flg); --i) for (unsigned j(m - 1); ~j; --j)
    if (a[i][j] ^ '*') { Flg = 1, C = i, D = j;break; }
  if ((B == (m - 1)) || (!D)) { printf("0\n"); return 0;}
//  printf("Con %u\n", Con);
  Lst(A, B), f[A][B][1] = 1;
  unsigned Pli(A), Plj(B); Nxt(Pli, Plj);
  for (unsigned i(A), j(B); (i ^ C) || (j ^ D); i = Pli, j = Plj, Nxt(Pli, Plj)) {
//    printf("Do (%u, %u) %c\n", i, j, a[Pli][Plj]);
//    for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) printf("(%u,%u)", k, f[i][j][k]); putchar(0x0A);
    if(a[Pli][Plj] ^ '.') {
      if(Plj) {for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) {
        unsigned Cur(Find[k]), Up(Cur & (3 << ((Plj + 1) << 1))), Lef(Cur & (3 << ((Plj << 1))));
        if(!(Up | Lef)) f[Pli][Plj][List[(Cur ^ Up) ^ Lef]] += f[i][j][k];
      }}
      else for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) {
        unsigned Cur(Find[k]);
        if(!(Cur & 3)) f[Pli][Plj][List[Cur << 2]] += f[i][j][k];
      }
      continue;
    }
    if(!Plj) {
      for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) {
//        printf("(%u, %u)", k, f[i][j][k]);
        unsigned Cur(Find[k]), To(Cur << 2);
        char Up(Cur & 3);
        if (Up) f[Pli][Plj][List[To]] += f[i][j][k], To ^= 5;
        else To ^= 9;
        f[Pli][Plj][List[To]] += f[i][j][k];
      }
    } else for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) {
//      printf("(%u, %u)", k, f[i][j][k]);
      unsigned Cur(Find[k]), To(Cur);
      char Up((Cur >> ((Plj + 1) << 1)) & 3), Lef(Cur >> ((Plj << 1)) & 3);
      if(!(Up | Lef)) To ^= (9 << (Plj << 1));
      else if(a[Pli][Plj]) {
//        printf("Up %u Lef %u %u %u\n", Up, Lef, Pli, Plj);
        if((!Lef) || (!Up)) f[Pli][Plj][k] += f[i][j][k], To ^= (((Up + Lef) | ((Lef + Up) << 2)) << (Plj << 1));
        else {
          To ^= (Up << ((Plj + 1) << 1));
          To ^= (Lef << (Plj << 1));
          if(Lef & Up) To ^= (3 << (g[k][Plj + (Lef == 1)] << 1));
          else if(Lef == 1) continue;
        }
      }
      f[Pli][Plj][List[To]] += f[i][j][k];
//      printf("To %u f [%u] += %u", To, List[To], f[i][j][k]);
    }
//    putchar(0x0A);
  }
  Ans = ((1 << (D << 1)) | (2 << ((D + 1) << 1)));
//  printf("Ans %u  LA %u\n", Ans, List[Ans]); 
  printf("%llu\n", f[C][D - 1][List[Ans]]);
  //  }
    //  system("pause");
  return Wild_Donkey;
}
/*
12 12
............
............
............
............
............
............
............
............
............
............
............
............
12 12
..**********
...*********
....********
*....*******
**....******
***....*****
****....****
*****....***
******....**
*******....*
********....
*********...
10 10
..********
...*******
....******
*....*****
**....****
***....***
****....**
*****....*
******....
*******...
8 8
..******
...*****
....****
*....***
**....**
***....*
****....
*****...
8 7
..*****
...****
....***
*....**
**....*
***....
****...
*****..
4 4
....
..*.
..*.
....
10 10
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
467260456608
*/
