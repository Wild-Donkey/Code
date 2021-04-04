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
inline unsigned int RD() {  // without "-"
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
const unsigned long long Mod(998244353);
unsigned int m, n, Cnta(0), len;
int L, R, a[100005];
bool b[1005];
char s[100005];
long long ans;
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3834_3.in", "r", stdin);
  // freopen("P3834.out", "w", stdout);
  n = RD();
  scanf("%s", s);
  // printf("%s\n", s);
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  L = RD();
  R = RD();
  ans = 0;
  for (register int i(1); i < n; ++i) {
    for (register int j(i + 1); j <= n; ++j) {
      if ((a[i] ^ a[j]) >= R) {
        continue;
      }
      // printf("i = %d\n", i);
      for (register int k(/*max(L - (a[i] ^ a[j]), */ 1 /*)*/);
           /*k + (a[i] ^ a[j]) <= R &&*/ k <= i; ++k) {
        // printf("%d %d %dfaq\n", i, j, k);
        if (s[i - k] != s[j - k]) {
          break;
        }
        if ((a[i] ^ a[j]) + k >= L && (a[i] ^ a[j]) + k <= R) {
          ++ans;
        }
      }
    }
    // ans %= Mod;
  }
  printf("%lld\n", ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}