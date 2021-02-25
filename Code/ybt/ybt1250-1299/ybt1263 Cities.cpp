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
unsigned int a[5005], f[5005], m, n, Cnt(0), A, B, D, len(0), now;
bool b[5005];
char s[5005];
struct Ct {
  unsigned int L, R;
  const bool operator<(const Ct &x) const {
    if (x.L == this->L) {
      return this->R < x.R;
    }
    return this->L < x.L;
  }
} C[5005];
// inline void Clr() {
//  n = RD();
//  memset(a, 0, sizeof(a));
//}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  RD();
  RD();
  n = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    C[i].L = RD();
    C[i].R = RD();
  }
  sort(C + 1, C + n + 1);
  for (register unsigned int i(1); i <= n; ++i) {
    //    printf("%u %u %u\n", i, C[i].L, C[i].R);
    a[i] = C[i].R;
  }
  memset(f, 0, sizeof(f));
  for (register unsigned int i(1); i <= n; ++i) {
    if (a[i] >= f[len]) {
      f[++len] = a[i];
      continue;
    }
    *(lower_bound(f + 1, f + len + 1, a[i])) = a[i];
  }
  printf("%u", len);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
*/
