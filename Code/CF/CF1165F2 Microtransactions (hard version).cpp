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
int m, n, ne[200005], tmp[200005], mid, sum, l(0), r(400005), z[200005];
bool b[200005];
char ch;
string s;
struct DZ {
  int day, stf;
  const bool operator<(const DZ &x) const { return this->day < x.day; }
} D[200005];
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
bool Check(const int &x) {
  for (register int i(1); i <= n; ++i) {
    tmp[i] = ne[i];
  }
  for (register int i(1); D[i].day <= x && i <= m; ++i) {
    z[D[i].stf] = D[i].day;
  }
  int Spt(0);
  for (register int i(1); D[i].day <= x && i <= m; ++i) {
    if (D[i].day <= x) {
      if (z[D[i].stf] == D[i].day) {
        if (tmp[D[i].stf]) {
          tmp[0] = min(tmp[D[i].stf], D[i].day - Spt /*当前金钱*/);
          tmp[D[i].stf] -= tmp[0];
          Spt += tmp[0];
        }
      }
    }
  }
  for (register int i(1); i <= n; ++i) {
    Spt += (tmp[i]) << 1;
  }
  if (Spt > x) {
    return 0;
  }
  return 1;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = RD();
  m = RD();
  memset(b, 1, sizeof(b));
  for (register int i(1); i <= n; ++i) {
    ne[i] = RD();
    if (ne[i] == 0) {
      b[i] = 0;
    }
    sum += ne[i];
  }
  for (register int i(1); i <= m; ++i) {
    D[i].day = RD();
    D[i].stf = RD();
    if (!b[D[i].stf]) {
      --i;
      --m;
    }
  }
  sort(D + 1, D + m + 1);
  /*for (register int i(1); i <= m; ++i) {
    printf("%d %d %d\n", i, D[i].day, D[i].stf);
  }*/
  while (l < r) {
    mid = (l + r) >> 1;
    if (Check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
5 6
1 2 0 2 0
2 4
3 3
1 5
1 2
1 5
2 3

8


5 3
4 2 1 3 2
3 5
4 2
2 5

20

2 2
2 2
2 1
2 2

6

2 2
2 3
3 1
3 2

7

2 2
3 2
3 1
3 2

7

2 2
2 2
20 1
20 2

8

1 1
3
2 1

4

1 1
3
2 1

4

*/