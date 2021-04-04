#include <iostream>
using namespace std;
inline int RD() {
  int intmp(0), insig;
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
unsigned long long ans(0), n, m, t, tmp;
int main() {
  n = RD();
  m = RD();
  if (n == 2) {
    printf("1\n");
    continue;
  }
  if (n % 2) {
    printf("%llu\n", (n * (n - 1)) >> 1);
  } else {
    printf("%llu\n", ((n * (n - 1)) >> 1) - ((n - 2) >> 1));
  }
  // system("pause");
  return 0;
}