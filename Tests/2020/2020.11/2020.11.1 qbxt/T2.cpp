#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp(0), insi(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && rdch != '-') {
    rdch = getchar();
  }
  if (rdch == '-') {
    insi = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insi;
}
int n, m, k, p, l, t;
int A, B, C;
int a[505];
int fy[505][505];
bool /*f[505][505][25],*/ flg(0);  // i 到 j 有 %p=k 的路径
struct Edge;
struct Node {
  Edge *fst;
  bool imp;
} N[505];
struct Edge {
  Node *to;
  Edge *nxt;
  int Val;
} E[505], *cnte(E + 0);
inline void Clr() {
  memset(N, 0, sizeof(N));
  // memset(f, 0, sizeof(f));
  memset(fy, 0, sizeof(fy));
  memset(a, 0, sizeof(a));
  flg = 0;
  return;
}
inline void Lk(const int &x, const int &y, const int &v) {
  /* (++cnte)->to = N + y;
   cnte->nxt = N[x].fst;
   N[x].fst = cnte;
   cnte->Val = v;*/
  // f[x][y][v] = 1;
  fy[x][y] |= (1 << v);
  return;
}
int main() {
  /*while (1) {
    printf("%d\n", RD());
  }*/
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    n = RD();
    m = RD();
    k = RD();
    p = RD();
    l = RD();
    cnte = E + 0;
    for (register int i(1); i <= k; ++i) {
      a[i] = RD();
      // printf("%d %d\n", i, a[i]);
      // N[a[i]].imp = 1;
    }
    /*for (register int i(1); i <= k; ++i) {
      printf("%d\n", a[i]);
    }*/
    for (register int i(1); i <= m; ++i) {
      A = RD();
      B = RD();
      C = RD();
      Lk(A, B, C);
      Lk(B, A, C);
    }
    for (register int i(1); i <= n; ++i) {
      fy[i][i] |= 1;
    }
    // floyd
    for (register int j(1); j <= n; ++j) {
      for (register int i(1); i <= n; ++i) {
        // if (k != i) {
        for (register int ik(0); ik < p; ++ik) {
          if (fy[i][j] & (1 << ik)) {
            for (register int e(1); e <= n; ++e) {
              // if (e != k && e != i) {
              // for (register int j(0); j < p; ++j) {
              // f[i][e][j] |= f[k][e][(j + p - ik) % p];
              fy[i][e] |= fy[j][e] >> ik;
              fy[i][e] |= (fy[j][e] & ((1 << ik) - 1)) << (p - ik);
              // }
              // }
            }
          }
        }
        // }
      }
    }
    /*   for (register int i(1); i <= n; ++i) {
         for (register int j(1); j <= n; ++j) {
           for (register int kk(0); kk < p; ++kk) {
             if (fy[i][j] & (1 << kk)) {
               printf("%d to %d len %d\n", i, j, kk);
             }
           }
         }
       }*/
    for (register int i(1); i <= k; ++i) {
      if (flg) {
        break;
      }
      for (register int j(i); j <= k; ++j) {
        // printf("%d %d %d %d\n", i, j, a[i], a[j]);
        if (fy[a[i]][a[j]] & (1 << l)) {
          printf("YES\n");
          flg = 1;
          break;
        }
      }
    }
    if (flg) {
      continue;
    }
    printf("NO\n");
  }
  system("pause");
  return 0;
}
/*
4
2 2 2 5 3
1 2
1 2 1
2 1 1
2 2 2 5 0
1 2
1 2 1
2 1 1
2 2 2 5 1
1 2
1 2 1
2 1 1
3 2 2 4 3
1 3
1 2 1
2 3 1

YES
YES
YES
NO

1
3 2 2 4 3
1 3
1 2 1
2 3 1
*/