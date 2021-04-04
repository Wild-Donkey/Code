#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
inline int RD() {
  int intmp(0), insign(1);
  char rdch(getchar());
  while ((rdch != '-') && (rdch < '0' || rdch > '9')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    insign = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp *= 10;
    intmp += rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int n, h, ans(0), f[5005] /*打完还剩i滴血打的屋数量*/;
priority_queue<pair<int, int>> q;
struct Rm {
  int Pai, Mdc /*, Ls*/;
  bool operator<(const Rm &x) const {
    if (this->Mdc == x.Mdc) {
      return this->Pai > x.Pai;
    }
    return this->Mdc > x.Mdc;
  }
} R[5005];
int main() {
  freopen("ex2.in", "r", stdin);
  n = RD();
  h = RD();
  for (register int i(1); i <= n; ++i) {
    R[i].Pai = RD();
  }
  for (register int i(1); i <= n; ++i) {
    R[i].Mdc = RD();
    // R[i].Ls = R[i].Mdc - R[i].Pai;
    q.push(make_pair(R[i].Mdc, i));
  }
  sort(R + 1, R + n + 1);
  /*for (register int i(1); i<= n; ++i) {
          printf("%d %d\n", R[i].Pai, R[i].Mdc);
  }*/
  /*while (h && q.size()) {
    if (R[q.top().second].Pai > h) {
      q.pop();
      continue;
    }
    h += R[q.top().second].Ls;
    q.pop();
    ++ans;
    // printf("%d %d\n", h, ans);
  }*/
  memset(f, 0, sizeof(f));
  for (register int i(1); i <= n; ++i) {
    for (register int j(R[i].Mdc); j <= h - R[i].Pai + R[i].Mdc; ++j) {
      // if (!f[i][j]) {
      // if()
      f[j] = max(f[j] /*不打i*/, f[j - R[i].Mdc + R[i].Pai] + 1 /*打i之前*/);
      //}
    }
  }
  for (register int i(0); i <= h; ++i) {
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
  /*while (1) {
    printf("%d\n", RD());
  }*/
  system("pause");
  return 0;
}
/*
4 12
4 8 2 1
2 0 0 0

3


3 10
10 1 3
8 0 1

3


3 10
10 6 5
2  5 0

2

3 10
10 1 2
2 0 1
*/
