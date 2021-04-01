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
#define Wild_Donkey 0
using namespace std;
inline unsigned int RD() {
  unsigned int intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
int a[200005];
unsigned int M, n, Cnta(1);
long long Lst, A, B, C, D;
struct Node {
  Node *L, *R;
  int Tagpls, Mx, HisMx, SecMx, Cntmax;
  long long Sum;
} N[1000005], *Cntn(N);
void Udt(Node *x, const unsigned int &l, const unsigned int &r,
         const unsigned int &m) {
  if (l == r) {
    return;
  }
  x->Sum = x->L->Sum + x->R->Sum;  //更新总和
  if (x->L->Mx == x->R->Mx) {      //更新最值和最值数量
    x->Cntmax = x->L->Cntmax + x->R->Cntmax;
    x->Mx = x->L->Mx;
    x->SecMx = max(x->L->SecMx, x->R->SecMx);  //更新次大值
  } else {
    if (x->L->Mx > x->R->Mx) {
      x->Mx = x->L->Mx;
      x->Cntmax = x->L->Cntmax;
      x->SecMx = x->R->Mx;
    } else {
      x->Mx = x->R->Mx;
      x->Cntmax = x->R->Cntmax;
      x->SecMx = x->L->Mx;
    }
  }
  x->HisMx = max(x->Mx, x->HisMx);  //历史最值
  return;
}
void Bld(Node *x, unsigned int l, const unsigned int &r) {
  x->Tagpls = 0;
  if (l == r) {
    x->Cntmax = 1;
    x->SecMx = -0x3f3f3f3f3f3f3f3f;
    x->Sum = a[l];
    x->Mx = a[l];
    x->HisMx = a[l];
    return;
  }
  unsigned int m((l + r) >> 1);
  Bld(x->L = ++Cntn, l, m);
  Bld(x->R = ++Cntn, m + 1, r);
  Udt(x, l, r, m);
  return;
}
void PsDw(Node *x, const unsigned int &l, const unsigned int &r,
          const unsigned int &m) {
  if (l == r) {
    return;
  }
  if (x->Tagpls) {
    x->L->Tagpls += x->Tagpls;
    x->L->Mx += x->Tagpls;
    x->L->HisMx = max(x->L->Mx, x->L->HisMx);
    x->R->Tagpls += x->Tagpls;
    x->R->Mx += x->Tagpls;
    x->R->HisMx = max(x->R->Mx, x->R->HisMx);
    x->L->Sum += (long long)x->Tagpls * (m - l + 1);
    x->R->Sum += (long long)x->Tagpls * (r - m);
    x->Tagpls = 0;
  }
  return;
}
void Addnm(Node *x, unsigned int l, const unsigned int &r) {
  if (l >= B && r <= C) {  //全包
    x->Sum += (long long)(r - l + 1) * D;
    x->Tagpls += D;
    x->Mx += D;
    x->HisMx = max(x->HisMx, x->Mx);  //历史最值
    return;
  }
  unsigned int m((l + r) >> 1);
  if (D <= m && D >= l) {  //在左
    if (!(x->L)) {
      x->L = ++Cntn;
    }
    return Addnm(x->L, l, m);
  }
  if (D <= r && D >= m + 1) {  //在右
    if (!(x->R)) {
      x->R = ++Cntn;
    }
    return Addnm(x->R, m + 1, r);
  }
  Udt(x, l, r, m);
  return;
}
void Tomin(Node *x, unsigned int l, const unsigned int &r) {
  if (l == r) {
    x->Sum = min(x->Sum, D);
    x->Mx = min(x->Sum, D);
    return;
  }
  if (l >= B && r <= C) {
    if (x->Mx <= D) {
      return;
    }
    if (x->SecMx < D) {
      x->Sum -= (long long)x->Cntmax * (x->Mx - D);
      return;
    }
  }
  unsigned int m((l + r) >> 1);
  PsDw(x, l, r, m);
  Tomin(x->L, l, m);
  Tomin(x->R, m + 1, r);
  Udt(x, l, r, m);
  return;
}
void QrSum(Node *x, unsigned int l, const unsigned int &r) {
  if (l >= B && r <= C) {  //全包
    Lst += x->Sum;
    return;
  }
  unsigned int m((l + r) >> 1);
  PsDw(x, l, r, m);
  if (!(l > C || m < B)) {  //左边
    QrSum(x->L, l, m);
  }
  if (!(m + 1 > C || r < B)) {  //右边
    QrSum(x->R, m + 1, r);
  }
  return;
}
void QMaxA(Node *x, unsigned int l, const unsigned int &r) {
  if (l >= B && r <= C) {
    Lst = max((long long)x->Mx, Lst);
    return;
  }
  unsigned int m((l + r) >> 1);
  PsDw(x, l, r, m);
  if (!(l > C || m < B)) {
    QMaxA(x->L, l, m);
  }
  if (!(m + 1 > C || r < B)) {
    QMaxA(x->R, m + 1, r);
  }
  return;
}
void QMaxB(Node *x, unsigned int l, const unsigned int &r) {
  x->HisMx = max(x->Mx, x->HisMx);
  if (l >= B && r <= C) {
    Lst = max(Lst, (long long)x->HisMx);
    return;
  }
  unsigned int m((l + r) >> 1);
  PsDw(x, l, r, m);
  if (!(l > C || m < B)) {
    QMaxB(x->L, l, m);
  }
  if (!(m + 1 > C || r < B)) {
    QMaxB(x->R, m + 1, r);
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3834_3.in", "r", stdin);
  // freopen("P3834.out", "w", stdout);
  n = RD();
  M = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  memset(N, 0, sizeof(N));
  Bld(N, 1, n);
  for (register int i(1); i <= M; ++i) {
    A = RD();
    B = RD();
    C = RD();
    switch (A) {
      case 1: {
        D = RD();
        Addnm(N, 1, n);
        break;
      }
      case 2: {
        D = RD();
        Tomin(N, 1, n);
        break;
      }
      case 3: {
        Lst = 0;
        QrSum(N, 1, n);
        printf("%lld\n", Lst);
        break;
      }
      case 4: {
        Lst = -0x3f3f3f3f3f3f3f3f;
        QMaxA(N, 1, n);
        printf("%lld\n", Lst);
        break;
      }
      case 5: {
        Lst = -0x3f3f3f3f3f3f3f3f;
        QMaxB(N, 1, n);
        printf("%lld\n", Lst);
        break;
      }
      default: {
        printf("FYSNB\n");
        break;
      }
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}