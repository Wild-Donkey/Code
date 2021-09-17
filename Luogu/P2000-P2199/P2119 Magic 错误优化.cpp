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
int Ans[15005][4], a[40005], b[15005], n, m, mx(0), Nxt[15005], NxtO[15005], kk;
int main() {
  freopen("P2119_10.in", "r", stdin);
  //freopen("my.out", "w", stdout);
  long long ti(clock());
  n = RD();
  m = RD();
  memset(b, 0, sizeof(b));
  for (register int i(1); i <= m; ++i) {
    a[i] = RD();
    b[a[i]]++;
    mx = max(mx, a[i]);
  }
  for (register int i(mx), tmp(mx), tmpj(-1), tmpo(-1); i >= 1; --i) {
    if (b[i]) {
      Nxt[i] = tmp;
      if (i % 2) {
        NxtO[i] = tmpj;
        tmpj = i;
      } else {
        NxtO[i] = tmpo;
        tmpo = i;
      }
      tmp = i;
    }
  }
  for (register int i(1), j, b_, Dlt, Tmp_1; i + 9 < mx; i = Nxt[i]) {
    Dlt = (mx - i - 1) / 9;
    b_ = NxtO[i];
    while (1) {
      if (b_ < 0) {
        break;
      }
      if (b_ > (Dlt << 1) + i) {
        break;
      }
      Tmp_1 = b[b_] * b[i];
      kk = i + (j << 3) + 1;
      while (kk < mx) {
        if (Nxt[kk]) {
          break;
        }
        ++kk;
      }
      for (register int k(kk), d_(k + j), Tmp_2; d_ < mx; k = Nxt[k]) {
        d_ = k + j;
        if (!b[d_]) {
          continue;
        }
        Tmp_2 = b[k] * b[d_];
        Ans[k][2] += Tmp_1 * b[d_];
        Ans[d_][3] += Tmp_1 * b[k];
        Ans[i][0] += Tmp_2 * b[b_];
        Ans[b_][1] += Tmp_2 * b[i];
      }
      b_ = NxtO[b_];
      j = (b_ - i) >> 1;
    }
  }
  for (register int i(1); i <= m; ++i) {
    printf("%d %d %d %d\n", Ans[a[i]][0], Ans[a[i]][1], Ans[a[i]][2],
           Ans[a[i]][3]);
  }
  ti = clock() - ti;
  printf("Time : %lld\n", ti);
  return 0;
}
