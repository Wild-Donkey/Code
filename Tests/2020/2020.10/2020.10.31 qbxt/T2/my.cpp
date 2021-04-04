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
  bool InStk, _ed;
} N[100005], *Stk[100005];
struct Node_ {
  Edge_ *Fst;
  Node *FstN;
  int IDg, Tpr, Siz, Dist;
  bool UnSmpl;
} N_[100005], *Stk_[100005];
struct Edge {
  Node *To;
  Edge *Nxt;
} E[100005], *cnte(E);
struct Edge_ {
  Node_ *To;
  Edge_ *Nxt;
} E_[100005], *cnte_(E_);
int n, m, A, B, Dcnt(0), Dcnt_(0), Scnt(0), Hd(0), Hd_(0), ans(0);
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
  ans = 0;
  for (register int i(1); i <= 100000; ++i) {
    N_[i].Dist = -0x3f3f; 
  }
  return;
}
void Lnk(const int &x, const int &y) {
  //printf("Faq\n");
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
    ++(N_[++Scnt].Siz);
    N_[Scnt].FstN = x;
    while (Stk[Hd] != x) {
      ++(N_[Scnt].Siz);
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
    if(x->BlT != Sid->To->BlT) {
      Lnk_(x->BlT, Sid->To->BlT);
    }
    Sid = Sid->Nxt;
  }
  return;
}
void DFS_(Node_ *x, int Dep) {
  ans = max(Dep, ans);
  //printf("To %d %d\n", x - N_, x->Tpr);
  Edge_ *Sid(x->Fst);
  while (Sid) {
    if(Sid->To->Siz == 1) {
      if(Sid->To->Dist < Dep) {
        Sid->To->Dist = Dep;
        DFS_(Sid->To, Dep);
      }
    } else {
      if(Sid->To->Dist <= Dep) {
        Sid->To->Dist = Dep + 1;
        DFS_(Sid->To, Dep + 1);
      }
    }
    Sid = Sid->Nxt;
  }
  return;
}
void TPR() {
  for(register int i(1); i <= Scnt; ++i) {
    if (N_[i].IDg == 0) {
      if(N_[i].Siz == 1) {
        DFS_(N_ + i, -1);
      } else {
        DFS_(N_ + i, 0);
      }
      Stk_[++Hd_] = &N_[i];
    }
  }
//  while (Hd_) {
//    Stk_[Hd_]->Tpr = ++Dcnt_;
//    Edge_ *Sid(Stk_[Hd_--]->Fst);
//    while (Sid) {
//      if(!Sid->To->Tpr) {
//        --(Sid->To->IDg);
//        if(Sid->To->IDg == 0) {
//          Stk_[++Hd_] = Sid->To;
//        }
//      }
//      Sid = Sid->Nxt;
//    }
//  }
  return;
}
void DFSIsd(Node *x) {
  if(N_[x->BlT].UnSmpl) {
    return;
  }
  x->_ed = 1;
  Edge *Sid(x->Fst);
  int Icnt(0), Ihd(Hd + 1);
  while (Sid) {
    if(Sid->To->BlT == x->BlT) {
      if(Sid->To != N_[x->BlT].FstN) {
        if (Sid->To->_ed) {
          N_[x->BlT].UnSmpl = 1;
          return;
        }
        Stk[++Hd] = Sid->To;
      }
    }
    Sid = Sid->Nxt;
  }
  sort(Stk + Ihd, Stk + Hd + 1);
  int Itmp(Hd);
  for (register int i(Ihd); i <= Itmp; ++i) {
    if(Stk[i] != Stk[i + 1]||i==Hd) {
      DFSIsd(Stk[i]);
      if(++Icnt >= 2) {
        N_[x->BlT].UnSmpl = 1;
        return;
      }
    }
  }
  return;
}
int main() {
  freopen("t2.in", "r", stdin);
  freopen("my.out", "w", stdout);
  Clr();
  n = RD();
  m = RD();
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    Lnk(A, B);
    //Lnk(B, A);
  }
  for (register int i(1); i <= n; ++i) {
    if(!N[i].DFSr) {
      Tarjan(N + i);
    }
  }
  for (register int i(1); i <= n; ++i) {
    //printf("%d Rank %d BkT %d BlT %d\n", i, N[i].DFSr, N[i].BkT, N[i].BlT);
    ToPnt(N + i);
  }
  for (register int i(1); i <= Scnt; ++i) {
    if(N_[i].Siz == 1) {
      continue;
    } else {
      DFSIsd(N_[i].FstN);
      if(N_[i].UnSmpl) {
        printf("-1\n");
        return 0;
      }
    }
  }
  TPR();
  printf("%d\n", max(0, ans));
  return 0;
}
