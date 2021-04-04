#include <iostream>
using namespace std;
const int Mod = 1000007;
inline int RD() {
  int Intmp(0), Insig(1);
  char Ichr(getchar());
  while ((Ichr != '-')&&((Ichr > '9')||(Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Insig = -1;
    Ichr = getchar();
  }
  while ((Ichr <= '9')&&(Ichr >= '0')) {
    Intmp = Intmp * 10 + Ichr - '0'; 
    Ichr = getchar();
  }
  return Intmp * Insig;
}
long long Ten[105], ans(3);
int n;
int main () {
  freopen("count.in", "r", stdin);
  freopen("count.out", "w", stdout);
  /*while (1) {
    printf("%d\n", RD());
  }*/
  n = RD();
  Ten[0] = 1;
  for (; n > 10; n -= 10) {
    ans *= 10000000000;
    ans %= Mod;
  }
  for (; n > 1; --n) {
    ans *= 10;
    ans %= Mod;
  }
  printf("%d\n", ans);
  return 0;
}
