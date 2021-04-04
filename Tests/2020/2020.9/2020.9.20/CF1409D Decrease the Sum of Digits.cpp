#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
unsigned long long a, b, ten[20], dfr, ans, n, sum, num[20], cnt;
unsigned long long In() {
  long long intmp(0), insign;
  char Inch;
  while ((Inch < '0' || Inch > '9') && Inch != '-') {
    Inch = getchar();
  }
  if (Inch == '-') {
    insign = -1;
    Inch = getchar();
  } else {
    insign = 1;
  }
  while (Inch <= '9' && Inch >= '0') {
    intmp *= 10;
    intmp += Inch - '0';
    Inch = getchar();
  }
  return intmp * insign;
}
void getn() {
  cnt = 0;
  unsigned long long A = a;
  sum = 0;
  while (A) {
    num[++cnt] = A % 10;
    sum += num[cnt];
    A /= 10;
  }
  return;
}
int main() {
  ten[0] = 1;
  for (register int i(1); i <= 19; ++i) {
    ten[i] = ten[i - 1] * 10;
  }
  n = In();
  for (register int T(1); T <= n; ++T) {
    ans = 0;
    a = In();
    b = In();
    getn();
    if (sum <= b) {
      printf("0\n");
      continue;
    }
    for (register int i(1); i <= cnt; ++i) {
      dfr = (10 - num[i]) * ten[i - 1];
      ans += dfr;
      a += dfr;
      getn();
      if (sum <= b) {
        printf("%lld\n", ans);
        break;
      }
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  //system("pause");
  return 0;
}
