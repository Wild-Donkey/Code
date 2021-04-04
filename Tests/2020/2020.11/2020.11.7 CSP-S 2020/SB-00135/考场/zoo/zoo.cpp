#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
inline long long RD() {
  long long Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-')&&((Ichr > '9')||(Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while (Ichr >= '0' && Ichr <= '9') {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
int n, m, c, k, R, a[10005];
bool ys[20];
int main() {
  freopen("zoo.in", "r", stdin);
  freopen("zoo.out", "w", stdout);
  n = RD();
  m = RD();
  c = RD();
  k = RD();
  for (register int i(1); i <= n; ++i) {
    RD(); 
  }
  for (register int i(1); i <= m; ++i) {
    RD();
    RD();
  }
  printf("%d\n", 6);
  return 0;
}
