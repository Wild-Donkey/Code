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
int m, n;
int a[1000005], A, B, C, D, Lst;
struct Node {
  Node *L, *R;  //左右儿子指针
  int Val;      //值
} N[20000005], *Vrsn[1000005] /*每个版本根节点*/, *Cntn(N) /*栈顶*/;
void Bld(Node *x, unsigned int l,
         const unsigned int &r) {  //将当前节点和对应区间作为参数传入, 节省空间
  if (l == r) {  //边界
    x->Val = a[l];
    return;
  }
  unsigned int m((l + r) >> 1);
  Bld(x->L = ++Cntn, l, m);  //递归左右子树
  Bld(x->R = ++Cntn, m + 1, r);
  return;
}
void Chg(Node *x, Node *y /*上一个版本的同位节点*/, unsigned int l,
         const unsigned int &r) {
  if (l == r) {  //边界
    x->Val = D;
    return;
  }
  unsigned int m = (l + r) >> 1;
  if (C <= m) {                          //左边
    x->R = y->R;                         //继承右儿子
    Chg(x->L = ++Cntn, y->L, l, m);      //递归左儿子
  } else {                               //右边
    x->L = y->L;                         //继承左儿子
    Chg(x->R = ++Cntn, y->R, m + 1, r);  //递归右儿子
  }
  return;
}
void Qry(Node *x, unsigned int l, const unsigned int &r) {
  if (l == r) {  //边界
    Lst = x->Val;
    return;
  }
  unsigned int m = (l + r) >> 1;
  if (C <= m) {           //左边
    Qry(x->L, l, m);      //递归左儿子
  } else {                //右边
    Qry(x->R, m + 1, r);  //递归右儿子
  }
  return;
}
int main() {
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  Bld(N, 1, n);  //建树
  Vrsn[0] = N;   //原始版本
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
    if (B == 1) {  //修改
      D = RD();
      Vrsn[i] = ++Cntn;  //新建一个版本
      Chg(Vrsn[i], Vrsn[A], 1, n);
    } else {
      Vrsn[i] = Vrsn[A];  //无需修改, 当前版本即所查询的版本
      Qry(Vrsn[i], 1, n);
      printf("%d\n", Lst);  //查询结果已经记录在Lst中
    }
  }
  return 0;
}