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
unsigned int m, n, Rot, cntd(0), DW;
unsigned int Mod, a[200005], C, A, B, yl, yr, yv;
struct Edge;
struct Node {
  unsigned int Siz /*子树大小*/, Dep /*深度(根为1)*/, DFSr /*DFS序*/;
  unsigned int Val /*权值(卫星数据)*/;
  Node *Fa /*父亲*/, *Top /*所在的重链顶端(即深度最小的点)*/, *Hvy /*重儿子*/;
  Edge *Fst /*邻接表的一部分, 首条边*/;
} N[200005];
struct Edge {
  Edge *Nxt /*邻接表, 下一条边*/;
  Node *To /*邻接表, 终点*/;
} E[400005], *cnte(E) /*栈顶*/;
void Lnk(Node *x, Node *y) {
  (++cnte)->Nxt = x->Fst;
  x->Fst = cnte;
  cnte->To = y;
  return;
}
struct SgNode {
  unsigned int Val, Tag;
  SgNode *L, *R;
} SgN[400005], *cntn(SgN);
void SgBld(SgNode *x, const unsigned int &l, const unsigned int &r) {
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
  x->Val = x->L->Val + x->R->Val;
  return;
}
inline void PsDw(SgNode *x, const unsigned int &l, const unsigned int &r) {
  unsigned int mid((l + r) >> 1);
  if (mid < r) {
    x->L->Val += x->Tag * (mid - l + 1);
    x->R->Val += x->Tag * (r - mid);
    x->L->Tag += x->Tag;
    x->R->Tag += x->Tag;
  }
  x->Tag = 0;
  return;
}
inline void Udt(SgNode *x) {
  if (x->L) {
    x->Val = (x->L->Val + x->R->Val) % Mod;
  }
  return;
}
void SgChg(SgNode *x, const unsigned int &l, const unsigned int &r) {
  if (l == r) {
    x->Val += yv;
    return;
  }
  if ((l >= yl && r <= yr)) {
    x->Tag += yv;
    x->Val += (r - l + 1) * yv % Mod;
    return;
  }
  unsigned int mid((l + r) >> 1);
  if (x->Tag) {
    PsDw(x, l, r);
  }
  if (mid >= yl) {
    SgChg(x->L, l, mid);
  }
  if (mid < yr) {
    SgChg(x->R, mid + 1, r);
  }
  Udt(x);
  return;
}
unsigned int SgQry(SgNode *x, const int &l, const int &r) {
  if (l >= yl && r <= yr) {
    return x->Val %= Mod;
  }
  if (l == r) {
    return Wild_Donkey;
  }
  if (x->Tag) {
    PsDw(x, l, r);
  }
  unsigned int mid((l + r) >> 1), Tmp(0);
  if (mid >= yl) {
    Tmp += SgQry(x->L, l, mid);
  }
  if (mid < yr) {
    Tmp += SgQry(x->R, mid + 1, r);
  }
  return Tmp % Mod;
}
void SonChg(Node *x) {
  yl = x->DFSr;               //子树根
  yr = x->DFSr + x->Siz - 1;  //树根加大小减一就是右边界
  return SgChg(SgN, 1, n);    //线段树操作
}
unsigned int SonQry(Node *x) {  //同上
  yl = x->DFSr;
  yr = x->DFSr + x->Siz - 1;
  return SgQry(SgN, 1, n);  //线段树操作自带取模
}
void LnkChg(Node *x, Node *y) {
  while (x->Top != y->Top) {  //不在同一重链上
    if (x->Top->Dep < y->Top->Dep) {
      swap(x, y);  //保证x所在的链顶深度较大
    }
    yl = x->Top->DFSr;  //线段树上操作左边界(x所在链顶)
    yr = x->DFSr;       //线段树上操作右边界(x)
    SgChg(SgN, 1, n);   //线段树上操作
    x = x->Top->Fa;     //路径上删去从x到x所在链顶这一段
  }
  if (x->Dep < y->Dep) {      //这时x, y在同一链上
    yl = x->DFSr;             // x为左边界
    yr = y->DFSr;             // y为右边界
    return SgChg(SgN, 1, n);  //进行最后一次线段树操作
  } else {
    yl = y->DFSr;             // y为左边界
    yr = x->DFSr;             // x为右边界
    return SgChg(SgN, 1, n);  //同上
  }
  return;
}
unsigned int LnkQry(Node *x, Node *y) {
  unsigned int Tmp(0);        //累计结果
  while (x->Top != y->Top) {  //其它的同上
    if (x->Top->Dep < y->Top->Dep) {
      swap(x, y);
    }
    yl = x->Top->DFSr;
    yr = x->DFSr;
    Tmp += SgQry(SgN, 1, n);
    x = x->Top->Fa;
  }
  if (x->Dep < y->Dep) {
    yl = x->DFSr;
    yr = y->DFSr;
    Tmp += SgQry(SgN, 1, n);
  } else {
    yl = y->DFSr;
    yr = x->DFSr;
    Tmp += SgQry(SgN, 1, n);
  }
  return Tmp % Mod;  //减少取模次数
}
void Bld(Node *x) {
  if (x->Fa) {                //不是根
    x->Dep = x->Fa->Dep + 1;  //深度比父亲大一
  } else {
    x->Dep = 1;  //根的深度为1
  }
  x->Siz = 1;         //初始化Siz
  Edge *Sid(x->Fst);  //遍历儿子
  while (Sid) {
    if (Sid->To != x->Fa) {  //是儿子
      Sid->To->Fa = x;       //儿子的父亲是自己
      Bld(Sid->To);          //递归子树
      if (!(x->Hvy)) {       //无重儿子
        x->Hvy = Sid->To;    //当前这个做目前重儿子
      } else {
        if (x->Hvy->Siz < Sid->To->Siz) {  //更重
          x->Hvy = Sid->To;                //更新重儿子
        }
      }
      x->Siz += Sid->To->Siz;  //累计Siz
    }
    Sid = Sid->Nxt;  //继续遍历
  }
  return;
}
void DFS(Node *x) {
  x->DFSr = (++cntd);  //标记DFS序
  Edge *Sid(x->Fst);
  if (x->Hvy) {            //优先走重儿子
    x->Hvy->Top = x->Top;  //与父同链, 链顶与父相同
    DFS(x->Hvy);           //递归子树
  } else {
    return;  //叶子
  }
  while (Sid) {
    if (Sid->To != x->Fa && Sid->To != x->Hvy) {  //普通儿子
      Sid->To->Top = Sid->To;                     //重链链顶为自己
      DFS(Sid->To);                               //递归子树
    }
    Sid = Sid->Nxt;  //继续遍历
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3384_2.in", "r", stdin);
  // freopen("P3384.out", "w", stdout);
  n = RD();
  m = RD();
  Rot = RD();
  Mod = RD();
  //  printf("n = %d m = %d Rot = %d Mod = %d\n", n, m, Rot, Mod);
  for (register int i(1); i <= n; ++i) {
    N[i].Val = RD() % Mod;
  }
  for (register int i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Lnk(N + A, N + B);
    Lnk(N + B, N + A);
  }
  Bld(N + Rot);
  N[Rot].Top = N + Rot;
  DFS(N + Rot);
  for (register unsigned int i(1); i <= n; ++i) {
    a[N[i].DFSr] = N[i].Val;
  }
  SgBld(SgN, 1, n);
  // Ti = clock() - Ti;
  for (register unsigned int i(1); i <= m; ++i) {
    DW = RD();
    A = RD();
    // Ti = clock();
    switch (DW) {
      case 1: {
        B = RD();
        yv = RD() % Mod;
        LnkChg(N + A, N + B);
        break;
      }
      case 2: {
        B = RD();
        printf("%u\n", LnkQry(N + A, N + B));
        break;
      }
      case 3: {
        yv = RD() % Mod;
        SonChg(N + A);
        break;
      }
      case 4: {
        printf("%u\n", SonQry(N + A));
        break;
      }
      default: {
        printf("FYSNB\n");
        break;
      }
    }
    // Ti = clock() - Ti;
    // Mti = max(Mti, Ti);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}