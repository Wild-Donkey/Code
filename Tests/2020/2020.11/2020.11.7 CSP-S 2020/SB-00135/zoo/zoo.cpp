#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
inline unsigned long long RD() {
  unsigned long long Itmp(0);
  char Ichr(getchar());
  while ((Ichr > '9') || (Ichr < '0')) {
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 - '0' + Ichr;
    Ichr = getchar();
  }
  return Itmp;
}
const unsigned long long _1(1);
bool Nd[65];
unsigned long long K(0), n, ans, m, k, c;
void Clr() {
  memset(Nd, 0, sizeof(Nd));
  K = 0;
  n = RD();
  return;
}
int main() {
  //freopen("zoo3.in", "r", stdin);
  Clr();
  m = RD();
  c = RD();
  k = RD();
  for (register unsigned long long i(1); i <= n; ++i) {
    K = K | RD();
  }
  for (register unsigned long long i(1); i <= m; ++i) {
    Nd[RD()] = true;
    RD();
  }
  for (register unsigned long long i(0); i < k; ++i) {
    if(!Nd[i]) {
      ++ans;
      continue;
    }
    if((_1 << i) & K) {
      ++ans;
      continue;
    }
  }
  if(ans == 64) {
    if(n == 0) {
      printf("18446744073709551616\n");
    }
    else {
      printf("%llu\n", -n);
    }
    return 0;
  }
  printf("%llu", (_1 << ans) - n);
  return 0;
}
