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
int m, n, k, lst, nxt, X[200005], t, cnt, ans, plt[200005][2], Ma[200005];
bool flg;
string s;
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
  // freopen(".in","r", stdin);
  // freopen(".out","w", stdout);
  t = In();
  for (register int T(1); T <= t; ++T) {
    memset(Ma, 0, sizeof(Ma));
    n = In();
    k = In();
    ans = 0;
    flg = 0;
    lst = 1;
    cnt = 0;
    for (register int i(1); i <= n; ++i) {
      X[i] = In();
    }
    for (register int i(1); i <= n; ++i) {
      X[0] = In();
    }
    sort(X + 1, X + n + 1);
    for (register int i(1); i <= n; ++i) {
      lst = lower_bound(X + 1, X + n + 1, X[i] - k) - X;
      nxt = upper_bound(X + 1, X + n + 1, X[i] + k) - X - 1;
      plt[i][0] = i - lst + 1;
      plt[i][1] = nxt - i + 1;
    }
    Ma[n] = 0;
    for (register int i(n - 1); i >= 1; --i) {
      Ma[i] = max(Ma[i + 1], plt[i + 1][1]);
    }
    for (register int i(1); i <= n; ++i) {
      ans = max(ans, plt[i][0] + Ma[i]);
    }
    printf("%d\n", ans);
  }
  // fclose(stdin);
  // fclose(stdout);
  // system("pause");
  return 0;
}
