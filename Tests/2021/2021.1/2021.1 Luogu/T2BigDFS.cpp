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
const unsigned long long Mod(1000000007);
unsigned int k, n, Cnta(1), Stk[1005];
bool b[1005];
unsigned long long ans(0);
bool Jdg() {
  unsigned int Mi, Ma;
  for (register int i(1); i <= n; ++i) {
    Ma = Mi = Stk[i];
    for (register int j(i); j <= n; ++j) {
      Ma = max(Ma, Stk[j]);
      Mi = min(Mi, Stk[j]);
      if (Ma - Mi == j - i && j + 1 > k + i && j + 1 < n + i) {
        return 1;
      }
    }
  }
  return 0;
}
void DFS(unsigned int Dep) {
  if (Dep == n) {
    if (Jdg()) {
      ++ans;
    }
    return;
  }
  for (register int i(1); i <= n; ++i) {
    if (!b[i]) {
      b[i] = 1;
      Stk[Dep + 1] = i;
      DFS(Dep + 1);
      b[i] = 0;
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3834_3.in", "r", stdin);
  // freopen("P3834.out", "w", stdout);
  n = RD();
  k = RD();
  memset(b, 0, sizeof(b));
  DFS(0);
  printf("%llu", ans % Mod);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}