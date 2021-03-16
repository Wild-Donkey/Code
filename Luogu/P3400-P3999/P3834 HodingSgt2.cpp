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
int a[200005], b[200005], Rkx[200005], A, B, C;
unsigned int M, n, Cnta(0), Lst, Now;
struct Node {
  Node *L, *R;
  unsigned int Val;
} N[4000005], *Vrsn[200005], *Cntn(N);
void Chg(Node *x, Node *y, unsigned int l, const unsigned int &r) {
  if (y) {  //更新权值
    x->Val = y->Val + 1;
  } else {
    x->Val = 1;
  }
  if (l == r) {  //边界
    return;
  }
  unsigned int m = (l + r) >> 1;  //继续递归
  if (B <= m) {                   //左边
    if (y) {
      x->R = y->R;                     //继承右儿子
      Chg(x->L = ++Cntn, y->L, l, m);  //递归左儿子
    } else {
      x->R = NULL;                     //无可继承
      Chg(x->L = ++Cntn, NULL, l, m);  //递归左儿子
    }
  } else {  //右边
    if (y) {
      x->L = y->L;                         //继承左儿子
      Chg(x->R = ++Cntn, y->R, m + 1, r);  //递归右儿子
    } else {
      x->L = NULL;
      Chg(x->R = ++Cntn, NULL, m + 1, r);  //递归右儿子
    }                                      //继承左儿子
  }
  return;
}
void Qry(Node *x, Node *y, unsigned int l, const unsigned int &r) {
  if (l == r) {  //边界
    Lst = l;
    return;
  }
  unsigned int m = (l + r) >> 1, Tmpx(0), Tmpy(0);
  Node *Sonxl(NULL), *Sonxr(NULL), *Sonyl(NULL), *Sonyr(NULL);
  if (x) {
    if (x->L) {
      Tmpx = x->L->Val;
      Sonxl = x->L;
    }
    if (x->R) {
      Sonxr = x->R;
    }
  }
  if (y) {
    if (y->L) {
      Tmpy = y->L->Val;
      Sonyl = y->L;
    }
    if (y->R) {
      Sonyr = y->R;
    }
  }                                  //防RE
  if (C <= Tmpy - Tmpx) {            //在左边
    return Qry(Sonxl, Sonyl, l, m);  //递归左儿子
  }
  C += Tmpx;  //右边
  C -= Tmpy;
  return Qry(Sonxr, Sonyr, m + 1, r);  //递归右儿子
}
int main() {
  n = RD();
  M = RD();
  memset(N, 0, sizeof(N));
  for (register int i(1); i <= n; ++i) {
    b[i] = a[i] = RD();  //创建副本
  }
  sort(b + 1, b + n + 1);
  b[0] = 0x3f3f3f3f;
  for (register int i(1); i <= n; ++i) {
    if (b[i] != b[i - 1]) {
      Rkx[++Cnta] = b[i];  // Rkx[i]为第i大的数为多少
    }
  }
  Vrsn[0] = N;
  for (register int i(1); i <= n; ++i) {
    A = i;
    B = lower_bound(Rkx + 1, Rkx + Cnta + 1, a[i]) -
        Rkx;  //给当前数字的次序(离散化后的值) 这个点加一
    Chg(Vrsn[i] = ++Cntn, Vrsn[i - 1], 1, Cnta);  //在上一个位置前缀和基础上修改
  }
  for (register int i(1); i <= M; ++i) {
    A = RD();
    B = RD();
    C = RD();
    Qry(Vrsn[A - 1], Vrsn[B], 1, Cnta);  //查询
    printf("%d\n", Rkx[Lst]);  //同样, 将查询结果存入Lst后, 输出Lst对应的原始值
  }
  return 0;
}