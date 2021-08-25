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
inline unsigned RD() {
  unsigned intmp = 0;
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
inline unsigned long long RDll() {
  unsigned long long intmp = 0;
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
unsigned List[2005], InList[20005], Ask[2005], n, Cnt(0);
unsigned long long f[15], Ans(0);
void DFS(unsigned Dep, unsigned Csd, unsigned Now) {
  if (Dep == 13) {
    if (Csd == 7) List[++Cnt] = Now;
    return;
  }
  if (13 - Dep < 7 - Csd) return;
  DFS(Dep + 1, Csd + 1, (Now << 1) + 1);
  DFS(Dep + 1, Csd, Now << 1);
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  DFS(0, 0, 0);
  for (register unsigned i(1); i <= n; ++i) {
    InList[List[i]] = i;
  }
  for (register unsigned i(0); i < 13; ++i) {
    Cnt = 0;
    for (register unsigned j(1); j <= n; ++j) {
      if (List[j] & (1 << i)) {
        Ask[++Cnt] = j;
      }
    }
    if (Cnt) {
      printf("? %u", Cnt);
      for (register unsigned j(1); j <= Cnt; ++j) {
        printf(" %u", Ask[j]);
      }
      putchar('\n');
      fflush(stdout);
      f[i] = RDll();
    }
    else {
      f[i] = 0;
    }
  }
  putchar('!');
  for (register unsigned i(1); i <= n; ++i) {
    Ans = 0;
    for (register unsigned j(0); j < 13; ++j) {
      if (!(List[i] & (1 << j))) Ans |= f[j];
    }
    printf(" %llu", Ans);
  }
  putchar('\n');
  fflush(stdout);
  // Ti = clock() - Ti;
    // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



