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
#define foreplay for
#define wild while
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
unsigned m, n;
unsigned A, B, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char R[6], C[6], Possi[60][5], a[5][5], Done(0);
inline void Prt(char x) { putchar(x ? (x + 64) : '.'); }
inline void Prt(char* x) {
  for (unsigned i(0); i < n; ++i) Prt(x[i]);
  putchar(0x0A);
}
inline void Prt() {
  printf("Yes\n");
  for (unsigned i(0); i < n; ++i) {
    for (unsigned j(0); j < n; ++j) Prt(a[i][j]);
    putchar(0x0A);
  }
}
inline void DFS(unsigned x) {
  // printf("DFS %u\n", x), Prt();
  if (x == n) {
    for (unsigned i(0); i < n; ++i) {
      char Cou[4];
      Cou[0] = Cou[1] = Cou[2] = Cou[3] = 0;
      for (unsigned j(0); j < n; ++j) Cou[a[j][i]]++;
      if (!(Cou[1] == 1 && Cou[2] == 1 && Cou[3] == 1)) return;
    }
    Prt(), Done = 1;
    return;
  }
  for (unsigned i(0); i < Cnt; ++i) {
    char *Cur(Possi[i]), Flg(0);
    // printf("Try %u ", i), Prt(Cur);
    for (unsigned j(0); j < n; ++j)
      if (Cur[j]) {
        if (Cur[j] != R[x]) Flg = 1;
        break;
      }
    if (Flg) continue;
    for (unsigned j(0); j < n; ++j)
      if (Cur[j]) {
        char Top(0);
        for (unsigned k(x - 1); (~k) && (!Flg); --k)
          if (a[k][j]) {
            Top = 1;
            if (a[k][j] == Cur[j]) Flg = 1;
          }
        if ((!Top) && (Cur[j] ^ C[j])) Flg = 1;
        if (Flg) break;
      }
    if (Flg) continue;
    for (unsigned j(0); j < n; ++j) a[x][j] = Cur[j];
    DFS(x + 1);
    if (Done) return;
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  scanf("%s%s", R, C);
  for (unsigned i(0); i < n; ++i) R[i] -= 64;
  for (unsigned i(0); i < n; ++i) C[i] -= 64;
  for (unsigned i(0); i < n; ++i) {
    for (unsigned j(0); j < n; ++j)
      if (j ^ i) {
        for (unsigned k(0); k < n; ++k)
          if ((k ^ i) && (k ^ j)) {
            Possi[Cnt][i] = 1;
            Possi[Cnt][j] = 2;
            Possi[Cnt++][k] = 3;
            // printf("Possi %u ", Cnt - 1), Prt(Possi[Cnt - 1]);
          }
      }
  }
  DFS(0);
  if (!Done) printf("No\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}