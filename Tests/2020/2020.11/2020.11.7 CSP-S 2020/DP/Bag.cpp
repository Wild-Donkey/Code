#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
struct Stf {
  int Val, Wei, num;
  int Lw1V, Lw1W, Lw2V, Lw2W;
} S[65];
int n, m, A, B, C, f[40005], cntn(0), ans(0), tmp;
void Clr() {
  memset(f, 0, sizeof(f));
  memset(S, 0, sizeof(S));
  cntn = 0;
}
int Gt(const int &x) {
  for (register int i(1); i <= cntn; ++i) {
    if(S[i].num == x){
      return i;
    }
  }
} 
int main() {
  //freopen("P2330_0.in", "r", stdin);
  //freopen("P2330.out", "w", stdout);
  //printf("Done1\n");
  Clr();
  n = RD();
  m = RD();
  //  printf("Done2\n");
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    B *= A;
    C = RD();
    if(C == 0) {
      S[++cntn].Val = B;
      S[cntn].Wei = A;
      S[cntn].num = i;
    } else {
      tmp = Gt(C);
      if(S[tmp].Lw1W) {
        S[tmp].Lw2V = B;
        S[tmp].Lw2W = A;
      } else {
        S[tmp].Lw1V = B;
        S[tmp].Lw1W = A;
      }
    }
  }
  /*for (register int i(1); i <= cntn; ++i) {
    //printf("%d: w = %d v = %d v1 = %d w1 = %d v2 = %d w2 = %d\n", i, S[i].Wei, S[i].Val, S[i].Lw1V, S[i].Lw1W, S[i].Lw2V, S[i].Lw2W);
  }*/
  for (register int i(1); i <= cntn; ++i) {
    for (register int j(0); j <= n - S[i].Wei; ++j) {
      f[j] = max(f[j], f[j + S[i].Wei] + S[i].Val);
      if(j + S[i].Wei + S[i].Lw1W <= n && S[i].Lw1V) {
        f[j] = max(f[j], f[j + S[i].Wei + S[i].Lw1W] + S[i].Val + S[i].Lw1V);
      }
      if(j + S[i].Wei + S[i].Lw2W <= n && S[i].Lw2V) {
        f[j] = max(f[j], f[j + S[i].Wei + S[i].Lw2W] + S[i].Val + S[i].Lw2V);
      }
      if(j + S[i].Wei + S[i].Lw1W + S[i].Lw2W <= n && S[i].Lw1V && S[i].Lw2V) {
        f[j] = max(f[j], f[j + S[i].Wei + S[i].Lw1W + S[i].Lw2W] + S[i].Val + S[i].Lw1V + S[i].Lw2V);
      }
      //if (f[j] != f[j - 1]) {
        //printf("%d %d %d\n", i, j, f[j]);
      //}
    }
  }
  //for (register int i(0); i <= n; ++i) {
  //ans = max(ans, f[i]);
  //}
  printf("%d\n", f[0]);
  return 0;
}
/*
1
40 40 40 40 40 40 40 40 40 25 25 25 20  5  5  5
2
50 50 50 50 50 50 50 40 40 35 30 25 20 15 10 10 10 10 10
3
62 62 62 52 52 50 50 40 40 35 30 25 22 22 22 12 12
*/
