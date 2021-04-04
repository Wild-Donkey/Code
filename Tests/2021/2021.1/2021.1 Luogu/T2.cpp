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
unsigned long long ans(0), Fc[1005];
void Factorio() {
  Fc[0] = Fc[1] = 1;
  for (register int i(2); i <= n; ++i) {
    Fc[i] = Fc[i - 1] * i;
    Fc[i] %= Mod;
  }
  return;
}
bool Jdg(const unsigned int Dep) {
  unsigned int Mi, Ma;
  Mi = Ma = Stk[Dep];
  for (register int i(Dep); i >= 1; --i) {
    Ma = max(Ma, Stk[i]);
    Mi = min(Mi, Stk[i]);
    if (Ma - Mi == Dep - i && Dep + 1 > k + i && Dep + 1 < n + i) {
      return 1;
    }
  }
  if (Dep == n) {
    for (register int i(1); i <= n; ++i) {
      printf("%u ", Stk[i]);
    }
    putchar('\n');
  }
  return 0;
}
void DFS(unsigned int Dep) {
  if (Dep > k) {
    if (Jdg(Dep)) {
      ans += Fc[n - Dep];
      ans %= Mod;
      return;
    }
    if (Dep >= n) {
      return;
    }
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
  Factorio();
  if (k + 1 >= n) {
    printf("0\n");
    return 0;
  }
  memset(b, 0, sizeof(b));
  DFS(0);
  printf("%llu\n", ans % Mod);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
2 4 1 5 3
2 5 3 1 4
3 1 5 2 4
3 5 1 4 2
4 1 3 5 2
4 2 5 1 3
*/