#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
const unsigned long long Base(39);
unsigned long long b[1000005], c[1000005], A, B;
unsigned m, n;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[1000005], Avb[2][1000005], Avc[2][1000005], Flg(0);
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", a + 1);
    for (unsigned j(1); j <= m; ++j)
      b[i] = b[i] * Base + a[j] - 'A', c[j] = c[j] * Base + a[j] - 'A';
  }
  Avb[0][0] = Avb[1][n] = Avc[0][0] = Avc[1][m] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(i + 1), k(i); (j <= n && k); ++j, --k) {
      if(b[j] ^ b[k]) break;
      else if(Avb[0][k - 1]) {Avb[0][i] = 1; break;}
    }
  }
  for (unsigned i(n - 1); ~i; --i) {
    for (unsigned j(i + 1), k(i); (j <= n && k); ++j, --k) {
      if(b[j] ^ b[k]) break;
      else if(Avb[1][j]) {Avb[1][i] = 1; break;}
    }
  }
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(i + 1), k(i); (j <= m && k); ++j, --k) {
      if(c[j] ^ c[k]) break;
      else if(Avc[0][k - 1]) {Avc[0][i] = 1; break;}
    }
  }
  for (unsigned i(m - 1); ~i; --i) {
    for (unsigned j(i + 1), k(i); (j <= m && k); ++j, --k) {
      if(c[j] ^ c[k]) break;
      else if(Avc[1][j]) {Avc[1][i] = 1; break;}
    }
  }
//  for (unsigned i(0); i <= n; ++i) putchar(Avb[0][i] ? '1' : '0');putchar(0x0A);
//  for (unsigned i(0); i <= n; ++i) putchar(Avb[1][i] ? '1' : '0');putchar(0x0A);
//  for (unsigned i(0); i <= m; ++i) putchar(Avc[0][i] ? '1' : '0');putchar(0x0A);
//  for (unsigned i(0); i <= m; ++i) putchar(Avc[1][i] ? '1' : '0');putchar(0x0A);
  for (unsigned i(0); i <= n; ++i) {
    if(Avb[1][i]) A += Cnt;
    if(Avb[0][i]) ++Cnt;
  }
  Cnt = 0;
  for (unsigned i(0); i <= m; ++i) {
    if(Avc[1][i]) B += Cnt;
    if(Avc[0][i]) ++Cnt;
  }
  printf("%llu\n", A * B);
  return Wild_Donkey;
}
/*
1 95
VOVYYYYVOVQVOVYYYYVOVYYVOVYYYYVOVYYVVYYVOVYYVVYYYIYYIYYIYYIYYYVVYYYYYVVYYYYYYYYVVYYYYYVVYYYIYYI
*/
