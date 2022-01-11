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
unsigned a[105][3][2][2], m, n, Des[2], Lim;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char Flg(0);
bitset<105> f[2][105][105][105], Meta;
inline unsigned Mo(unsigned x) { x -= (x >= Lim) ? Lim : 0;return x; }
//  inline void Clr() {}
signed main() {
  freopen("P7606_41.in", "r", stdin);
  freopen("P7606.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Lim = RD();
  for (unsigned i(0); i < Lim; ++i) Meta[i] = 1;
  cout << (Meta & ((Meta >> 8) | (Meta << 10))) << '\n';
  for (unsigned i(1); i <= n; ++i) {
    a[i][2][1][0] = RD(), a[i][2][1][1] = RD();
    a[i][1][1][0] = RD(), a[i][1][1][1] = RD();
    a[i][0][1][0] = RD(), a[i][0][1][1] = RD();
    a[i][2][0][0] = RD(), a[i][2][0][1] = RD();
    a[i][1][0][0] = RD(), a[i][1][0][1] = RD();
    a[i][0][0][0] = RD(), a[i][0][0][1] = RD();
  }
  Des[0] = RD(), Des[1] = RD(), f[0][50][50][0][0] = 1;
  for (A = 1; A <= n; ++A) {
    // fprintf(stderr, "Done %u\n", A);
    unsigned Now((A & 1) ^ 1), Nxt(A & 1);
    for (unsigned i(0); i <= 100; ++i) for (unsigned j(0); j <= 100; ++j)
      for (unsigned k(0); k < Lim; ++k) f[Nxt][i][j][k] = 0;
    for (unsigned k(0); k < Lim; ++k) {
      f[Nxt][1][1][Mo(k + a[A][0][0][0])] |= (((f[Now][0][0][k] << a[A][0][0][1]) & Meta) | ((f[Now][0][0][k] >> (Lim - a[A][0][0][1])) & Meta));
      f[Nxt][1][0][Mo(k + a[A][1][0][0])] |= (((f[Now][0][0][k] << a[A][1][0][1]) & Meta) | ((f[Now][0][0][k] >> (Lim - a[A][1][0][1])) & Meta));
      f[Nxt][0][1][Mo(k + a[A][2][1][0])] |= (((f[Now][0][0][k] << a[A][2][1][1]) & Meta) | ((f[Now][0][0][k] >> (Lim - a[A][2][1][1])) & Meta));
    }
    for (unsigned j(1); j <= 100; ++j) {
      for (unsigned k(0); k < Lim; ++k) {
        f[Nxt][1][j + 1][Mo(k + a[A][0][0][0])] |= (((f[Now][0][j][k] << a[A][0][0][1]) & Meta) | ((f[Now][0][j][k] >> (Lim - a[A][0][0][1])) & Meta));
        f[Nxt][1][j][Mo(k + a[A][1][0][0])] |= (((f[Now][0][j][k] << a[A][1][0][1]) & Meta) | ((f[Now][0][j][k] >> (Lim - a[A][1][0][1])) & Meta));
        f[Nxt][0][j - 1][Mo(k + a[A][2][0][0])] |= (((f[Now][0][j][k] << a[A][2][0][1]) & Meta) | ((f[Now][0][j][k] >> (Lim - a[A][2][0][1])) & Meta));
        f[Nxt][0][j + 1][Mo(k + a[A][2][1][0])] |= (((f[Now][0][j][k] << a[A][2][1][1]) & Meta) | ((f[Now][0][j][k] >> (Lim - a[A][2][1][1])) & Meta));
      }
    }
    for (unsigned i(1); i <= 100; ++i) {
      for (unsigned k(0); k < Lim; ++k) {
        f[Nxt][i + 1][1][Mo(k + a[A][0][0][0])] |= (((f[Now][i][0][k] << a[A][0][0][1]) & Meta) | ((f[Now][i][0][k] >> (Lim - a[A][0][0][1])) & Meta));
        f[Nxt][i + 1][0][Mo(k + a[A][1][0][0])] |= (((f[Now][i][0][k] << a[A][1][0][1]) & Meta) | ((f[Now][i][0][k] >> (Lim - a[A][1][0][1])) & Meta));
        f[Nxt][i - 1][0][Mo(k + a[A][1][1][0])] |= (((f[Now][i][0][k] << a[A][1][1][1]) & Meta) | ((f[Now][i][0][k] >> (Lim - a[A][1][1][1])) & Meta));
        f[Nxt][i][1][Mo(k + a[A][2][1][0])] |= (((f[Now][i][0][k] << a[A][2][1][1]) & Meta) | ((f[Now][i][0][k] >> (Lim - a[A][2][1][1])) & Meta));
      }
      for (unsigned j(1); j <= 100; ++j) {
        for (unsigned k(0); k < Lim; ++k) {
          f[Nxt][i + 1][j + 1][Mo(k + a[A][0][0][0])] |= (((f[Now][i][j][k] << a[A][0][0][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][0][0][1])) & Meta));
          f[Nxt][i - 1][j - 1][Mo(k + a[A][0][1][0])] |= (((f[Now][i][j][k] << a[A][0][1][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][0][1][1])) & Meta));
          f[Nxt][i + 1][j][Mo(k + a[A][1][0][0])] |= (((f[Now][i][j][k] << a[A][1][0][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][1][0][1])) & Meta));
          f[Nxt][i - 1][j][Mo(k + a[A][1][1][0])] |= (((f[Now][i][j][k] << a[A][1][1][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][1][1][1])) & Meta));
          f[Nxt][i][j - 1][Mo(k + a[A][2][0][0])] |= (((f[Now][i][j][k] << a[A][2][0][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][2][0][1])) & Meta));
          f[Nxt][i][j + 1][Mo(k + a[A][2][1][0])] |= (((f[Now][i][j][k] << a[A][2][1][1]) & Meta) | ((f[Now][i][j][k] >> (Lim - a[A][2][1][1])) & Meta));
        }
      }
    }
    // if (A <= 50) for (unsigned k(0); k < Lim; ++k) printf("%u: ", k), cout << f[Nxt][50][50 + A][k] << '\n';
    // for (unsigned i(0); i <= 100; ++i) for (unsigned j(0); j <= 100; ++j) for (unsigned k(0); k < Lim; ++k)
    //   if (f[n & 1][i][j][k].count()) printf("A: (%u, %u) %u ", A, i, j, k), cout << f[Nxt][i][j][k] << '\n';
  }
  // for (unsigned k(0); k < Lim; ++k) printf("%u: ", k), cout << f[n & 1][50][50][k] << '\n';
  // for (unsigned i(0); i <= 100; ++i) for (unsigned j(0); j <= 100; ++j) for (unsigned k(0); k < Lim; ++k)
  //   if (f[n & 1][i][j][k].count()) printf("(%u, %u) %u ", i, j, k), cout << f[n & 1][i][j][k] << '\n';
  printf(f[n & 1][50][50][Des[0]][Des[1]] ? "Chaotic Evil\n" : "Not a true problem setter\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*(, 75)*/