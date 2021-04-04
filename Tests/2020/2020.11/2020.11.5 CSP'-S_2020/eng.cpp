#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Mod = 19260817;
inline int RD() {
  int Intmp(0), Insig(1);
  char Ichr(getchar());
  while ((Ichr != '-')&&((Ichr > '9')||(Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Insig = -1;
    Ichr = getchar();
  }
  while ((Ichr <= '9')&&(Ichr >= '0')) {
    Intmp = Intmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Intmp * Insig;
}
struct Edge;
struct Edge_;
struct Node {
  Edge *Fst;
  int DFSr, BkT, BlT, Val;
  bool InStk, _ed, Rich;
} N[10005], *Stk[10005];
struct Node_ {
  Edge_ *Fst;
  bool _ed;
  int IDg, Tpr, Dist, Val, Rich;
} N_[10005];
struct Edge {
  Node *To;
  Edge *Nxt;
} E[100005], *cnte(E);
struct Edge_ {
  Node_ *To;
  Edge_ *Nxt;
} E_[100005], *cnte_(E_);
int n, m, t, c, A, B;
int Dcnt, Scnt, Hd;
long long ans;
void Clr () {
  memset(N, 0, sizeof(N));
  memset(E, 0, sizeof(E));
  memset(N_, 0, sizeof(N_));
  memset(E_, 0, sizeof(E_));
  memset(Stk, 0, sizeof(Stk));
  cnte = E;
  cnte_ = E_;
  Dcnt = 0;
  Scnt = 0;
  Hd = 0;
  ans = 0;
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
  N_[x->BlT].Rich += x->Rich;
  N_[x->BlT].Val += x->Val;
  while (Sid) {
    if(x->BlT != Sid->To->BlT) {
      Lnk_(x->BlT, Sid->To->BlT);
    }
    Sid = Sid->Nxt;
  }
  return;
}
void DFS_(Node_ *x) {
  ans += (long long)x->Val * x->Rich;
  x->_ed = 1;
  Edge_ *Sid(x->Fst);
  while (Sid) {
    if(!Sid->To->_ed) {
      DFS_(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  return;
}
int main () {
  freopen("eng.in", "r", stdin);
  freopen("eng.out", "w", stdout);
  /*while (1) {
    printf("%d\n", RD());
  }*/
  n = RD();
  m = RD();
  t = RD();
  c = RD();
  //printf("faq1\n");
  for (register int i(1); i <= n; ++i) {
    N[i].Val = RD();
  }
  //printf("faq2\n");
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    Lnk(B, A);
  }
  //printf("faq3\n");
  for (register int i(1); i <= t; ++i) {
    N[RD()].Rich = 1;
  }
  //printf("faq4\n");
  for (register int i(1); i <= n; ++i) {
    if (!N[i].BlT) {
      Tarjan(N + i);
    }
    //printf("%d %d\n", i, N[i].BlT);
  }
  //printf("faq5\n");
  for (register int i(1); i <= n; ++i) {
    ToPnt(N + i);
  }
  //printf("faq6\n");
  DFS_(N[c].BlT + N_);
  //printf("faq7\n");
  printf("%d\n", ans % Mod);
  return 0;
}
