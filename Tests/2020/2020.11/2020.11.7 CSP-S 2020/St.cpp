#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
int St[18][100005], Log2[100005];
int A, B, n, m, k;
void Clr () {
  memset(St, 0, sizeof(St));
  return;
}
void Bld() {
  for (register int i(1); i <= Log2[n]; ++i) {
    for (register int j(1); j + (1 << i) <= n + 1; ++j) {
      St[i][j] = max(St[i - 1][j], St[i - 1][j + (1 << (i - 1))]);
      //printf("%d %d %d\n", i, j, St[i][j]);
    }
  }
  return;
}
int Fnd () {
  int len = Log2[B - A + 1];
  return max(St[len][A], St[len][B - (1 << len) + 1]);
}
int main() {
  //freopen("P3372_2.in", "r", stdin);
  //freopen("P3372.out", "w", stdout);
  Clr();
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    St[0][i] = RD();
  }
  Log2[1] = 0;
  for (register int i(2); i <= n; ++i) {
    Log2[i] = Log2[i - 1];
    if(i >= 1 << (Log2[i - 1] + 1)) {
      ++Log2[i];
    }
    //printf("%d %d\n", i, Log2[i]);
  }
  Bld();
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    if(A > B) {
      swap(A, B); 
    }
    printf("%d\n", Fnd());
  }
  return 0;
}
