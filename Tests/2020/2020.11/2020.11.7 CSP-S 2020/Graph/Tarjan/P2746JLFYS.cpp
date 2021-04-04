#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
struct Edge;
struct Node {
  Edge *Fst;
  int DFSr, BkT, BlT;
  bool InStk;
} N[10005], *Stk[10005];
struct Node_ {
  bool IDg, ODg;
} N_[10005];
struct Edge {
  Node *To;
  Edge *Nxt;
} E[10005], *cnte(E);
int n, A, Dcnt(0), Dcnt_(0), Scnt(0), Hd(0), Hd_(0), ansI(0), ansO(0);
void Clr () {
  memset(N, 0, sizeof(N));
  memset(E, 0, sizeof(E));
  memset(N_, 0, sizeof(N_));
  memset(Stk, 0, sizeof(Stk));
  ansI = 0;
  ansO = 0;
  cnte = E;
  Dcnt = 0;
  Scnt = 0;
  Hd = 0;
  return;
}
void Lnk(const int &x, const int &y) {
  (++cnte)->To = N + y;
  cnte->Nxt = N[x].Fst;
  N[x].Fst = cnte;
  return;
}
void Lnk_(const int &x, const int &y) {
  N_[y].IDg = 1;
  N_[x].ODg = 1;
  return;
}
void Tarjan(Node *x) {
  //printf("To %d %d\n", x - N, Dcnt);
  x->DFSr = ++Dcnt;
  x->BkT = x->DFSr;
  x->InStk = 1;
  Stk[++Hd] = x;
  Edge *Sid(x->Fst);
  while (Sid) {
    if (Sid->To->BlT) {
      Sid = Sid->Nxt;
      continue;
    }
    if (Sid->To->InStk) {//up or equal
      x->BkT = min(x->BkT, Sid->To->DFSr);
    } else {
      Tarjan(Sid->To);
      x-> BkT = min(x->BkT, Sid->To->BkT);
    }
    Sid = Sid->Nxt;
  }
  if(x->BkT == x->DFSr) {
    ++Scnt;
    while (Stk[Hd] != x) {
      Stk[Hd]->BlT = Scnt;
      Stk[Hd]->InStk = 0;
      --Hd;
    }
    Stk[Hd]->BlT = Scnt;
    Stk[Hd--]->InStk = 0;
  }
  return;
}
void ToPnt(Node *x) {
  Edge *Sid(x->Fst);
  while (Sid) {
    if((x->BlT != Sid->To->BlT)&&(!((N_[x->BlT].ODg)&&(N_[Sid->To->BlT].IDg)))) {
      Lnk_(x->BlT, Sid->To->BlT);
    }
    Sid = Sid->Nxt;
  }
  return;
}
int main() {
  freopen("P2746_3.in", "r", stdin);
  Clr();
  n = RD();
  for (register int i(1); i <= n; ++i) {
    while (A = RD()) {
      Lnk(i, A);
    }
  }
  for (register int i(1); i <= n; ++i) {
    if(!N[i].DFSr) {
      Tarjan(N + i);
    }
  }
  for (register int i(1); i <= n; ++i) {
    ToPnt(N + i);
  }
  for (register int i(1); i <= Scnt; ++i) {
    if(!N_[i].IDg) {
      ++ansI;
    }
    if(!N_[i].ODg) {
      ++ansO;
    }
  }
  if(Scnt == 1) {
    printf("1\n0\n");
    return 0;
  }
  printf("%d\n%d\n", ansI,max(ansI, ansO));
  return 0;
}
