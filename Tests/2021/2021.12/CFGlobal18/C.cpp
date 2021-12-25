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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[100005], b[100005];
inline void Clr() {
  n = RD(), Ans = A = B = C = D = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    scanf("%s%s", a + 1, b + 1);
    for (unsigned i(1); i <= n; ++i) A += a[i] - '0';
    for (unsigned i(1); i <= n; ++i) B += b[i] - '0';
    if ((A ^ B) && (!((A) && (A - 1 == n - B)))) {
      printf("-1\n");
      continue;
    }
    if (A == B) for (unsigned i(1); i <= n; ++i) C += (a[i] ^ b[i]);
    else C = 0x3f3f3f3f;
    if ((A) && (A - 1 == n - B))for (unsigned i(1); i <= n; ++i) D += (a[i] ^ (b[i] ^ 1));
    else D = 0x3f3f3f3f;
    // printf("%u %u\n", C, (D | 1));
    printf("%u\n", min(C, (D | 1)));
  }
  // system("pause");
  return Wild_Donkey;
}