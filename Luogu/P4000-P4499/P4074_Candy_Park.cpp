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
inline unsigned RD() {
  unsigned intmp = 0;
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, q, CntEu(0), CntQ(0), A, B, C, D, t, Tmp(0), Time, Cnt[100005], BlockLen, Block[200005];
unsigned long long W[100005], V[100005], Ans[100005];
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[20];
  unsigned Dep, Frnt, Back, Col;
  char Have;
}N[100005], *Euler[200005], *Ace(N);
struct Edge {
  Edge *Nxt;
  Node *To;
}E[200005], *CntE(E);
inline void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  return;
}
void DFS(Node *x) {
  x->Frnt = ++CntEu;
  Euler[CntEu] = x;
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa[0]) {
      Sid->To->Fa[0] = x;
      Sid->To->Dep = x->Dep + 1;
      for(register unsigned i(0); Sid->To->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
      }
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  x->Back = ++CntEu;
  Euler[CntEu] = x;
}
Node *LCA(Node *x, Node *y) {
  if(x->Dep < y->Dep) {
    Node *TmpNd(x); x = y, y = TmpNd;
  }
  for (register unsigned i(19); x->Dep > y->Dep; --i) {
    if(x->Fa[i]) {
      x = (x->Fa[i]->Dep >= y->Dep) ? x->Fa[i] : x;
    }
  }
  if (x == y) {
    return x;
  }
  for (register unsigned i(19); x->Fa[0] != y->Fa[0]; --i) {
//    printf("Jump %u x%u y%u Deep %u %u\n", i, x - N, y - N, x->Dep, y->Dep);
    if(x->Fa[i] != y->Fa[i]) {
      x = x->Fa[i], y = y->Fa[i];
    }
  }
  return x->Fa[0];
}
struct Qry {
  unsigned L, R, Ti, Num;
  inline const char operator<(const Qry &x) const {
    return (Block[this->L] ^ Block[x.L]) ? (Block[this->L] < Block[x.L]) : ((Block[this->R] ^ Block[x.R]) ? (Block[this->R] < Block[x.R]) : this->Ti < x.Ti);
  }
}Q[100005];
struct Change{
  Node *Addre;
  unsigned Value;
}Chg[100005];
inline void Turb(Node *x) { // 对某个节点进行状态改变 (没统计就统计, 已经统计就删去) 
  if(x->Have ^= 1) {  // 之前没统计 
    Ans[0] += W[++Cnt[x->Col]] * V[x->Col];
  } else {            // 之前统计过一次 
    Ans[0] -= W[Cnt[x->Col]--] * V[x->Col];
  }
  return;
}
int main() {
  n = RD(), m = RD(), q = RD(); 
  for (register unsigned i(1); i <= m; ++i) {
    V[i] = RD();
  }
  for (register unsigned i(1); i <= n; ++i) {
    W[i] = RD();
  }
  for (register unsigned i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  N[1].Dep = 1;
  N[1].Fa[0] = NULL;
  DFS(N + 1);
  Time = 1; // 没有修改, 最初的时刻 
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Col = RD();
  }
  for (register unsigned i(1); i <= q; ++i) {
    if(RD()) {      // 询问, 将路径转化为区间 
      A = RD();
      B = RD();
      if (N[A].Frnt <= N[B].Frnt) {
        if (N[A].Back <= N[B].Frnt) {
          Q[++CntQ].L = N[A].Back;
          Q[CntQ].R = N[B].Frnt;
        } else {
          Q[++CntQ].L = N[A].Frnt;
          Q[CntQ].R = N[B].Frnt;
        }
      } else {
        if (N[A].Back <= N[B].Back) {
          Q[++CntQ].L = N[B].Frnt;
          Q[CntQ].R = N[A].Frnt;
        } else {
          Q[++CntQ].L = N[B].Back;
          Q[CntQ].R = N[A].Frnt;
        }
      }
      Q[CntQ].Ti = Time;
      Q[CntQ].Num = CntQ;
    }
    else {          // 修改 
      Chg[++Time].Addre = N + RD();
      Chg[Time].Value = RD();
    }
  }
  BlockLen = (pow(((unsigned long long)n * n * Time / CntQ), 1.0/3) * 3.5) + 1; // 经过计算和修正的块长 (不同代码常数不同, 需要自行修正) 
  for (register unsigned i(1); i <= CntEu; ++i) { // 预处理不同坐标属于的块的编号 
    Block[i] = i / BlockLen;
  }
  sort(Q + 1, Q + CntQ + 1);
  Q[0].Ti = 1;
  Q[0].L = 1;
  Q[0].R = 1;
  Ans[0] = V[Euler[1]->Col] * W[++Cnt[Euler[1]->Col]];
  Euler[1]->Have ^= 1;  // 初始化, 开始增量 
  for (register unsigned i(1), TmpSw; i <= CntQ; ++i) {
    while (Q[0].Ti < Q[i].Ti) { // 时间正流 
      ++Q[0].Ti;
      if (Chg[Q[0].Ti].Addre->Have) {
        Turb(Chg[Q[0].Ti].Addre);
        TmpSw = Chg[Q[0].Ti].Addre->Col, Chg[Q[0].Ti].Addre->Col = Chg[Q[0].Ti].Value, Chg[Q[0].Ti].Value = TmpSw;
        Turb(Chg[Q[0].Ti].Addre);
      }
      else {
        TmpSw = Chg[Q[0].Ti].Addre->Col, Chg[Q[0].Ti].Addre->Col = Chg[Q[0].Ti].Value, Chg[Q[0].Ti].Value = TmpSw;
      }
    }
    while (Q[0].Ti > Q[i].Ti) { // 时间倒流 
      if (Chg[Q[0].Ti].Addre->Have) {
        Turb(Chg[Q[0].Ti].Addre);
        TmpSw = Chg[Q[0].Ti].Addre->Col, Chg[Q[0].Ti].Addre->Col = Chg[Q[0].Ti].Value, Chg[Q[0].Ti].Value = TmpSw;
        Turb(Chg[Q[0].Ti].Addre);
      }
      else {
        TmpSw = Chg[Q[0].Ti].Addre->Col, Chg[Q[0].Ti].Addre->Col = Chg[Q[0].Ti].Value, Chg[Q[0].Ti].Value = TmpSw;
      }
      --Q[0].Ti;
    }
    while (Q[0].L > Q[i].L) {Turb(Euler[--Q[0].L]);}  // 左端点左移 
    while (Q[0].R < Q[i].R) {Turb(Euler[++Q[0].R]);}  // 右端点右移 
    while (Q[0].L < Q[i].L) {Turb(Euler[Q[0].L++]);}  // 左端点右移 
    while (Q[0].R > Q[i].R) {Turb(Euler[Q[0].R--]);}  // 右端点左移 
    Ace = LCA(Euler[Q[0].L], Euler[Q[0].R]);
    if(Ace == Euler[Q[0].L] || Ace == Euler[Q[0].R]) {  // 垂直的链, LCA 是两点之一 
      Ans[Q[i].Num] = Ans[0];
    } else {                                            // 需要单独考虑 LCA 的贡献 
      Turb(Ace);
      Ans[Q[i].Num] = Ans[0];
      Turb(Ace);
    }
  }
  for (register unsigned i(1); i <= CntQ; ++i) {
    printf("%llu\n", Ans[i]);
  }
  return Wild_Donkey;
}



