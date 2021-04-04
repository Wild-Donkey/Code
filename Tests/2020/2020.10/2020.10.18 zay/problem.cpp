#include <iostream>
using namespace std;
inline long long RD() {
  long long intmp(0), insig;
  char inchar(getchar());
  while ((inchar > '9' || inchar < '0') && (inchar != '-')) {
    inchar = getchar();
  }
  if (inchar == '-') {
    insig = -1;
    inchar = getchar();
  } else {
    insig = 1;
  }
  while (inchar <= '9' && inchar >= '0') {
    intmp *= 10;
    intmp += inchar - '0';
    inchar = getchar();
  }
  return intmp * insig;
}
unsigned long long n, t, tmp;
int main() {
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
  t = RD();
  for (register int i(1); i <= t; ++i) {
    n = RD();
    tmp = n - 1;
    if (n % 2) {  //奇数
      tmp = tmp >> 1;
    } else {
      n = n >> 1;
    }
    printf("%llu\n", tmp * n);
  }
  // system("pause");
  return 0;
}