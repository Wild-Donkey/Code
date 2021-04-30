#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int n, r, A, ans(0);
double B, lst;
struct Node {
  double L, R;
  const bool operator<(const Node &x) const {
    if (this->R == x.R) {
      return this->L < x.L;
    }
    return this->R < x.R;
  }
} N[1005];
int main() {
  n = RD();
  r = RD();
  for (register int i(1); i <= n; ++i) {
    A = RD();
    B = RD();
    B = r * r - B * B;
    B = sqrt(B);
    N[i].L = A - B;
    N[i].R = A + B;
  }
  sort(N + 1, N + n + 1);
  lst = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    if (N[i].L > lst) {
      ans++;
      lst = N[i].R;
    }
  }
  printf("%d\n", ans);
  system("pause");
  return 0;
}