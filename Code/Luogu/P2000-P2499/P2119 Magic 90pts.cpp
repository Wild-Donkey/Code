#include <cstdio>
#include <cstring>
#include <ctime>
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
int Ans[15005][4];
int a[40005], b[15005], n, m, mx(0);
/*struct Stf {
  int Num, Val;
  const bool operator<(const Stf &x) const { return this->Val < x.Val; }
} a[40005];*/
int main() {
  n = RD();
  m = RD();
  // scanf("%d%d", &n, &m);
  memset(b, 0, sizeof(b));
  for (register int i(1); i <= m; ++i) {
    a[i] = RD();
    // scanf("%d", a[i]);
    b[a[i]]++;
    mx = max(mx, a[i]);
  }
  // sort(a + 1, a + m + 1);
  /*for (register int i(1); i <= m; ++i) {
    printf("%d %d\n", a[i].Num, a[i].Val);
  }*/
  long long ti(clock());
  for (register int i(1), Dlt; i + 9 < n; ++i) {
    if (!b[i]) {
      continue;
    }
    Dlt = (mx - i - 1) / 9;
    for (register int j(1), b_(i + 2), Tmp_1; j <= Dlt; ++j, b_ += 2) {
      if (!b[b_]) {  // B 不存在
        continue;
      }
      Tmp_1 = b[b_] * b[i];
      for (register int k(i + (j << 3) + 1), d_(k + j), Tmp_2; d_ <= mx;
           ++k, ++d_) {
        if (!((b[k]) && (b[d_]))) {
          continue;
        }
        Tmp_2 = b[k] * b[d_];
        Ans[k][2] += /*(long long)*/ Tmp_1 * b[d_];
        Ans[d_][3] += /*(long long)*/ Tmp_1 * b[k];
        // Tmp_1 *= b[k] * b[k + j];
        Ans[i][0] += /*(long long)*/ Tmp_2 * b[b_];
        Ans[b_][1] += /*(long long)*/ Tmp_2 * b[i];
        // Tmp_1 = b[i + (j << 1)];
      }
    }
  }
  ti = clock() - ti;
  for (register int i(1); i <= m; ++i) {
    printf("%d %d %d %d\n", Ans[a[i]][0], Ans[a[i]][1], Ans[a[i]][2],
           Ans[a[i]][3]);
  }
  // printf("Time : %lld\n", ti);
  // system("pause");
  return 0;
}