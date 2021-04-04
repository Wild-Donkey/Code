#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int n, a[100005], cnts(0);
bool b[100005];
char ch, s[100005];
struct Qr {
  int Ti, Val;
} q[100005], *cntq(q);
inline int RD() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = RD();
  ch = getchar();
  for (register int i(1); i <= n; ++i) {
    while (ch != 'T' && ch != 'Q' && ch != 'U') {
      ch = getchar();
    }
    if (ch == 'T') {
      getchar();
      ch = getchar();
      a[i] = -(ch);
    } else {
      if (ch == 'U') {
        a[i] = RD();
      } else {
        if (ch == 'Q') {
          //--n;
          (++cntq)->Val = RD();
          cntq->Ti = /*--*/ i;
        }
      }
    }
    ch = getchar();
  }
  for (register int i(1); i <= n; ++i) {
    printf("%d %d\n", i, a[i]);
  }
  for (register int i(1); i + q <= cntq; ++i) {
    printf("%d %d %d\n", i, q[i].Ti, q[i].Val);
  }
  for (register int i(n); i >= 1; --i) {
    if (a[i] > 0 && a[i] < 1e7) {
      i -= a[i];
    } else {
      b[i] = 1;
    }
  }
  for (register int i(1), j(1); i <= n && j + q <= cntq; ++i) {
    if (b[i]) {
      s[++cnts] = -a[i];
    }
    if (a[i] >= 0) {
    }
    if (q[j].Ti == i) {
      putchar(s[q[j++].Val]);
      putchar('\n');
    }
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
