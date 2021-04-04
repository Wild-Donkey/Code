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
struct Edge_;
struct Node {
  Edge *Fst;
  int DFSr, BkT, BlT;
  bool InStk;
} N[10005], *Stk[10005];
struct Node_ {
  Edge_ *Fst;
  int IDg, Tpr;
  bool _ed;
  /*const bool operator <(const Node_ x) const {
    return this->IDg < x.IDg;
  }*/
} N_[10005], *Stk_[10005];
struct Edge {
  Node *To;
  Edge *Nxt;
} E[10005], *cnte(E);
struct Edge_ {
  Node_ *To;
  Edge_ *Nxt;
} E_[10005], *cnte_(E_);
int n, A, Dcnt(0), Dcnt_(0), Scnt(0), Hd(0), Hd_(0);
void Clr () {
  memset(N, 0, sizeof(N));
  memset(E, 0, sizeof(E));
  memset(N_, 0, sizeof(N_));
  memset(E_, 0, sizeof(E_));
  memset(Stk, 0, sizeof(Stk));
  memset(Stk_, 0, sizeof(Stk_));
  cnte = E;
  cnte_ = E_;
  Dcnt = 0;
  Dcnt_ = 0;
  Scnt = 0;
  Hd = 0;
  Hd_ = 0;
  return;
}
void Lnk(const int &x, const int &y) {
  (++cnte)->To = N + y;
  cnte->Nxt = N[x].Fst;
  N[x].Fst = cnte;
  return;
}
void Lnk_(const int &x, const int &y) {
  ++N_[y].IDg;
  (++cnte_)->To = N_ + y;
  cnte_->Nxt = N_[x].Fst;
  N_[x].Fst = cnte_;
  return;
}
void Tarjan(Node *x) {
  //printf("To %d %d\n", x - N, Dcnt);
  if (!x->DFSr) {
    x->DFSr = ++Dcnt;
    x->BkT = x->DFSr;
    x->InStk = 1;
    Stk[++Hd] = x;
  }
  Edge *Sid(x->Fst);
  while (Sid) {
    if (Sid->To->BlT) {
      Sid = Sid->Nxt;
      continue;
    }
    if (Sid->To->InStk) {
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
  //printf("To %d %d\n", x - N, Dcnt);
  Edge *Sid(x->Fst);
  while (Sid) {
    if(x->BlT != Sid->To->BlT) {
      Lnk_(x->BlT, Sid->To->BlT);
    }
    Sid = Sid->Nxt;
  }
  return;
}
void TPR() {
  //sort(N_ + 1, N_ + Scnt + 1);
  for(register int i(1); i <= Scnt; ++i) {
    if (N_[i].IDg == 0) {
      Stk_[++Hd_] = &N_[i];
      //Stk_[Hd_]->Tpr = ++Dcnt_;
    }
  }
  while (N_[++Hd_].IDg == 0) {
    Stk_[Hd_] = &N_[Hd_];
    //Stk_[Hd_]->Tpr = ++Dcnt_;
  }
  --Hd_;
  while (Hd_) {
    Stk_[Hd_]->Tpr = ++Dcnt_;
    Edge_ *Sid(Stk_[Hd_--]->Fst);
    while (Sid) {
      if(!Sid->To->Tpr) {
        --(Sid->To->IDg);
        if(Sid->To->IDg == 0) {
          Stk_[++Hd_] = Sid->To;
        }
      }
      Sid = Sid->Nxt;
    }
  }
  return;
}
void DFS_(Node_ *x) {
  x->_ed = 1;
  printf("To %d %d\n", x - N_, x->Tpr);
  Edge_ *Sid(x->Fst);
  while (Sid) {
    if(!Sid->To->_ed) {
      DFS_(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  return;
}
int main() {
  freopen("P2746_0.in", "r", stdin);
  //freopen("P2746.out", "w", stdout);
  Clr();
  n = RD();
  for (register int i(1); i <= n; ++i) {
    while (A = RD()) {
      Lnk(i, A);
      //Lnk(A, i);
    }
  }
  for (register int i(1); i <= n; ++i) {
    if(!N[i].DFSr) {
      Tarjan(N + i);
    }
  }
  for (register int i(1); i <= n; ++i) {
    printf("%d Rank %d BkT %d BlT %d\n", i, N[i].DFSr, N[i].BkT, N[i].BlT);
    ToPnt(N + i);
  }
  TPR();
  for (register int i(1); i <= Scnt; ++i) {
    if(!N_[i]._ed) {
      DFS_(N_ + i);
    }
  }
  return 0;
}
