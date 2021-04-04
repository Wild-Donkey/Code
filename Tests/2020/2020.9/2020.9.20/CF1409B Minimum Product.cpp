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
int m, n, a, b, c, d, e, ans(0), sum;
bool flg(0);
string s;
struct Edge;
struct Node {
  int Val;
  bool Vsd;
  Node *Fa;
  Edge *Fst;
} N[10005];
struct Edge {
  Node *To;
  Edge *Nxt;
} E[10005];
int In() {
  int intmp(0), insign;
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
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  // printf("%d\n", 123074);
  n = In();
  for (register int i(1); i <= n; ++i) {
    a = In();
    b = In();
    c = In();
    d = In();
    e = In();
    if (max(a - e, c) > max(b - e, d)) {
      swap(a, b);
      swap(c, d);
    }
    if (a > c) {
      int tmp = min(a - c, e);
      a -= tmp;
      e -= tmp;
    }
    if (b > d) {
      b = max(b - e, d);
    }
    printf("%lld\n", (long long)b * a);
  }
  // fclose(stdin);
  // fclose(stdout);
  // system("pause");
  return 0;
}
