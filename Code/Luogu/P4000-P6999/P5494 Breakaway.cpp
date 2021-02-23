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
unsigned int a[200005];
unsigned int M, n, Cnta(1), A, B, C, D;
unsigned long long Lst;
struct Node {
  Node *L, *R;
  unsigned long long Val;
} N[4000005], *Cntn(N), *Vrsn[200005];  //和可持久化类似, Vrsn[]存每个线段树的根
void Bld(Node *x, unsigned int l, const unsigned int &r) {
  if (l == r) {  //边界
    x->Val = a[l];
    return;
  }
  unsigned int m((l + r) >> 1);
  Bld(x->L = ++Cntn, l, m);
  Bld(x->R = ++Cntn, m + 1, r);  //递归
  x->Val = 0;                    //统计区间元素总个数
  if (x->L) {
    x->Val += x->L->Val;
  }
  if (x->R) {
    x->Val += x->R->Val;
  }
  return;
}
void Brkaw(Node *x /*To*/, Node *y /*From*/, unsigned int l,
           const unsigned int &r) {
  if (l == r) {
    return;
  }
  unsigned int m((l + r) >> 1);
  x->Val = 0;
  y->Val = 0;
  if (y->L) {
    if (m <= D && l >= C) {  //左边继承
      x->L = y->L;
      y->L = NULL;
    } else {
      if (!(m < C || l > D)) {  //左边递归
        Brkaw(x->L = ++Cntn, y->L, l, m);
      }
    }
  }
  if (y->R) {
    if (r <= D && m + 1 >= C) {  //右边继承
      x->R = y->R;
      y->R = NULL;
    } else {
      if (!(r < C || m + 1 > D)) {  //右边递归
        Brkaw(x->R = ++Cntn, y->R, m + 1, r);
      }
    }
  }
  if (y->L) {  //最后统计两个同位点的权值
    y->Val += y->L->Val;
  }
  if (x->L) {
    x->Val += x->L->Val;
  }
  if (y->R) {
    y->Val += y->R->Val;
  }
  if (x->R) {
    x->Val += x->R->Val;
  }
  return;
}
void Addto(Node *x /*To*/, Node *y /*From*/, unsigned int l,
           const unsigned int &r) {  // O(nlogn)
  x->Val += y->Val;
  if (l == r) {
    return;
  }
  unsigned int m = (l + r) >> 1;
  if (y->L) {
    if (x->L) {  //递归合并
      Addto(x->L, y->L, l, m);
    } else {  //直接继承
      x->L = y->L;
    }
  }
  if (y->R) {
    if (x->R) {  //递归合并
      Addto(x->R, y->R, m + 1, r);
    } else {  //直接继承
      x->R = y->R;
    }
  }
  return;
}
void Chnge(Node *x, unsigned int l, const unsigned int &r) {
  x->Val += C;  //自己的子集增加 C 个元素, 先给自己加上 C
  if (l == r) {
    return;
  }
  unsigned int m((l + r) >> 1);
  if (D <= m && D >= l) {  //在左
    if (!(x->L)) {
      x->L = ++Cntn;  //开点
    }
    return Chnge(x->L, l, m);
  }
  if (D <= r && D >= m + 1) {  //在右
    if (!(x->R)) {
      x->R = ++Cntn;  //开点
    }
    return Chnge(x->R, m + 1, r);
  }
  return;
}
void Qrynm(Node *x, unsigned int l, const unsigned int &r) {
  if (l >= C && r <= D) {  //全包
    Lst += x->Val;
    return;
  }
  unsigned int m((l + r) >> 1);
  if (x->L) {
    if (!(m < C || l > D)) {  //波及左边
      Qrynm(x->L, l, m);
    }
  }
  if (x->R) {
    if (!(r < C || m + 1 > D)) {  //波及右边
      Qrynm(x->R, m + 1, r);
    }
  }
  return;
}
void Qryrk(Node *x, unsigned int l, const unsigned int &r) {
  if (l == r) {
    Lst = l;
    return;
  }
  unsigned int m((l + r) >> 1);
  if (x->L) {
    if (x->L->Val >= C) {
      return Qryrk(x->L, l, m);
    }
    C -= x->L->Val;
  }
  if (x->R) {
    if (x->R->Val >= C) {
      return Qryrk(x->R, m + 1, r);
    }
    Lst = -1;
    return;
  }
  Lst = -1;
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
  Bld(Vrsn[1] = ++Cntn, 1, n);
  for (register int i(1); i <= M; ++i) {
    A = RD();
    B = RD();
    C = RD();
    switch (A) {
      case 0: {
        D = RD();
        Brkaw(Vrsn[++Cnta] = ++Cntn, Vrsn[B], 1, n);
        break;
      }
      case 1: {
        Addto(Vrsn[B], Vrsn[C], 1, n);
        break;
      }
      case 2: {
        D = RD();
        Chnge(Vrsn[B], 1, n);
        break;
      }
      case 3: {
        D = RD();
        Lst = 0;
        Qrynm(Vrsn[B], 1, n);
        printf("%llu\n", Lst);
        break;
      }
      case 4: {
        if (Vrsn[B]->Val < C) {
          printf("-1\n");
          break;
        }
        Lst = 0;
        Qryrk(Vrsn[B], 1, n);
        printf("%llu\n", Lst);
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
/*
5 8
1 2 3 4 5
0 1 3 5
0 1 1 2
3 2 2 4
3 3 2 4
3 1 1 5
4 2 3
4 3 3
4 1 1

7
2
0
3
2
-1
*/