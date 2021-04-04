#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))){
    Ichr = getchar(); 
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')){
    Itmp = Itmp * 10 + Ichr - '0'; 
    Ichr = getchar(); 
  }
  return Itmp * Isig;
}
inline void PR(int Prtmp, bool SoE) {
  long long Prstk(0), Prlen(0);
  if (Prtmp < 0) {
    putchar('-');
    Prtmp = -Prtmp;
  }
  do {
    Prstk = Prstk * 10 + Prtmp % 10;
    Prtmp /= 10;
    ++Prlen;
  } while (Prtmp);
  //printf("%d", Prtmp);
  do {
    putchar(Prstk % 10 + '0');
    Prstk /= 10;
    --Prlen;
  } while (Prlen);
  if (SoE) {
    putchar('\n');
  }
  else {
    putchar(' ');
  }
  return;
}
int n, a[1005], ans(0);
bool f[1005][1005];
int gcd (int x, int y) {
  if(!y) {
    return x;
  }
  return gcd(y, x % y);
}
int main() {
  freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  n = RD();
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  sort(a + 1, a + n + 1);
  for (register int i(1); i < n; ++i) {
    for (register int j(i + 1), tmp1, tmp2, tmp3; j <= n; ++j) {
      if(a[j] == a[i]) {
        continue;
      }
      tmp3 = gcd(a[i], a[j]);
      tmp1 = a[i] / tmp3;
      tmp2 = a[j] / tmp3;
      f[tmp1][tmp2] = 1;
    }
  }
  for (register int i(1); i < 1000; ++i) {
    for (register int j(i + 1); j <= 1000; ++j) {
      if(f[i][j]) {
        ++ans;
       // printf("%d %d\n", i, j);
      } 
    }
  }
  PR(ans,1);
  return 0;
} 
