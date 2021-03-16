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
inline unsigned long long RD() {
  char ich(getchar());
  unsigned int intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  //  printf("RD %d\n", intmp);
  return intmp;
}
long long m, n, Rot, A, B, cntd(0), DW;
long long Mod, a[200005], C;
struct SgNode {
  unsigned long long Val, Tag;
  SgNode *L, *R;
} SgN[400005], *cntn(SgN);
void Udt(SgNode *x) {
  x->Val = 0;
  if (x->L) {
    x->Val += x->L->Val;
  }
  if (x->R) {
    x->Val += x->R->Val;
  }
  return;
}
void SgBld(SgNode *x, const int &l, const int &r) {
  x->Tag = 0;
  if (l == r) {
    x->Val = a[l];
    x->L = x->R = NULL;
    return;
  }
  x->L = ++cntn;
  x->R = ++cntn;
  int mid((l + r) >> 1);
  SgBld(x->L, l, mid);
  SgBld(x->R, mid + 1, r);
  Udt(x);
  return;
}
inline bool Irg(const int &nl, const int &nr, const int &l, const int &r) {
  return nl >= l && nr <= r;
}
inline bool Org(const int &nl, const int &nr, const int &l, const int &r) {
  return nr < l || nl > r;
}
void PsDw(SgNode *x, const int &l, const int &r) {
  if (x->Tag) {
    if (l != r) {
      int mid((l + r) >> 1);
      x->L->Val += x->Tag * (mid - l + 1);
      x->R->Val += x->Tag * (r - mid);
      x->L->Tag += x->Tag;
      x->R->Tag += x->Tag;
    }
    x->Tag = 0;
  }
  return;
}
void SgChg(SgNode *x, const int &l, const int &r, const int &yl, const int &yr,
           const unsigned long long &yv) {
  // printf("SgChg %d %d %d %d\n", x - SgN, l, r, x->Val);
  if (Org(l, r, yl, yr)) {
    return;
  }
  if (l == r) {
    x->Val += yv;
    return;
  }
  if (Irg(l, r, yl, yr)) {
    x->Tag += yv;
    x->Val += (r - l + 1) * yv;
    x->Tag %= Mod;
    x->Val %= Mod;
    return;
  }
  int mid((l + r) >> 1);
  if (!x) {
    x = NULL;
  }
  PsDw(x, l, r);
  if (!x->L) {
    x->L = NULL;
  }
  SgChg(x->L, l, mid, yl, yr, yv);
  if (!x->R) {
    x->R = NULL;
  }
  SgChg(x->R, mid + 1, r, yl, yr, yv);
  Udt(x);
  return;
}
long long SgQry(SgNode *x, const int &l, const int &r, const int &yl,
                const int &yr) {
  if (Org(l, r, yl, yr)) {
    return 0;
  }
  if (Irg(l, r, yl, yr)) {
    return x->Val;
  }

  PsDw(x, l, r);
  int mid((l + r) >> 1);
  return (SgQry(x->L, l, mid, yl, yr) + SgQry(x->R, mid + 1, r, yl, yr)) % Mod;
}
int main() {
  // freopen("P3372_2.in", "r", stdin);
  // freopen("P3384my.out", "w", stdout);
  n = RD();
  m = RD();
  Mod = 0x7fffffffffffffff;
  //  printf("n = %d m = %d Rot = %d Mod = %d\n", n, m, Rot, Mod);
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  SgBld(SgN, 1, n);
  for (register int i(1); i <= m; ++i) {
    DW = RD();
    A = RD();
    B = RD();
    switch (DW) {
      case 1: {
        C = RD() % Mod;
        SgChg(SgN, 1, n, A, B, C);
        break;
      }
      case 2: {
        printf("%lld\n", SgQry(SgN, 1, n, A, B));
        break;
      }
      default: {
        printf("FYSNB\n");
        break;
      }
    }
  }
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}