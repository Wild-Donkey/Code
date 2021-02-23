#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
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
int n, m, DW, A, cntans(0);
// long long ti(clock());
struct Node {
  Node *Ls, *Rs, *Fa;
  int val, x_Cnt, Siz;
} N[100005], *cntn(N), *Rot(N);
void Clr() {
  m = RD();
  memset(N, 0, sizeof(Node) * (m + 3));
  N[0].val = 0x3f3f3f3f;
  cntn = N;
  Rot = N;
  return;
}
Node *Fnd(Node *x, const int &y) {
  if (!x) {
    return NULL;
  }
  if (x->val == y) {
    return x;
  }
  if (x->val < y) {
    return Fnd(x->Rs, y);
  }
  return Fnd(x->Ls, y);
}
void Trn(Node *x) {
  if (x->Fa) {
    Node *TmpFa(x->Fa);
    if (TmpFa->Fa) {
      if (TmpFa == TmpFa->Fa->Ls) {
        TmpFa->Fa->Ls = x;
      } else {
        TmpFa->Fa->Rs = x;
      }
    }
    x->Fa = TmpFa->Fa;
    TmpFa->Fa = x;
    if (x == TmpFa->Ls) {
      TmpFa->Ls = x->Rs;
      if (x->Rs) {
        x->Rs->Fa = TmpFa;
      }
      x->Rs = TmpFa;
    } else {
      TmpFa->Rs = x->Ls;
      if (x->Ls) {
        x->Ls->Fa = TmpFa;
      }
      x->Ls = TmpFa;
    }
    TmpFa->Siz = TmpFa->x_Cnt;
    x->Siz = x->x_Cnt;
    if (TmpFa->Ls) {
      TmpFa->Siz += TmpFa->Ls->Siz;
    }
    if (TmpFa->Rs) {
      TmpFa->Siz += TmpFa->Rs->Siz;
    }
    if (x->Ls) {
      x->Siz += x->Ls->Siz;
    }
    if (x->Rs) {
      x->Siz += x->Rs->Siz;
    }
  }
  return;
}
void Spl(Node *x, Node *rot) {
  Node *Farot(rot->Fa);
  if (x == rot) {
    return;
  }
  // printf("Spl Node %d Val %d\n", x - N, x->val);
  while (x->Fa && x->Fa != Farot) {
    // printf("%d->Fa = %d\n", x - N, x->Fa->val);
    if (x->Fa->Fa == Farot) {
      // printf("NoGrandfather\n");
      Trn(x);
      break;
    } else {
      // printf("grandfather val = %d\n", x->Fa->Fa->val);
      if (x == x->Fa->Ls) {
        if (x->Fa == x->Fa->Fa->Ls) {
          Trn(x->Fa);
          Trn(x);
        } else {
          Trn(x);
          Trn(x);
        }
      } else {
        if (x->Fa == x->Fa->Fa->Rs) {
          Trn(x->Fa);
          Trn(x);
        } else {
          Trn(x);
          Trn(x);
        }
      }
    }
  }
  if (!Farot) {
    Rot = x;
  }
  return;
}
Node *GoRi(Node *x) {
  if (!x->Rs) {
    if (x->Siz > 0) {
      // Spl(x, Rot);
      return x;
    } else {
      Node *TmpFa(x->Fa);
      // Spl(TmpFa, Rot);
      return TmpFa;
    }
  }
  return GoRi(x->Rs);
}
Node *GoLe(Node *x) {
  if (!x->Ls) {
    // Spl(x, Rot);
    return x;
  }
  return GoLe(x->Ls);
}
void GoUp(Node *x) {
  while (x->Fa) {
    x->Fa->Siz = x->Fa->x_Cnt;
    if (x->Fa->Ls) {
      x->Fa->Siz += x->Fa->Ls->Siz;
    }
    if (x->Fa->Rs) {
      x->Fa->Siz += x->Fa->Rs->Siz;
    }
    x = x->Fa;
  }
  return;
}
void Add(Node *x, const int &y) {
  // printf("Add %d val %d y %d\n", x - N, x->val, y);
  ++(x->Siz);
  if (x->val == y) {
    ++(x->x_Cnt);
    return Spl(x, Rot);
  }
  if (x->val < y) {
    if (x->Rs) {
      return Add(x->Rs, y);
    }
    x->Rs = ++cntn;
    cntn->Fa = x;
    cntn->val = y;
    cntn->x_Cnt = 1;
    cntn->Siz = 1;
    return Spl(cntn, Rot);
  } else {
    if (x->Ls) {
      // printf("Ls = %d(val = %d)\n", x->Ls - N, x->Ls->val);
      return Add(x->Ls, y);
    }
    x->Ls = ++cntn;
    cntn->Fa = x;
    cntn->val = y;
    cntn->x_Cnt = 1;
    cntn->Siz = 1;
    return Spl(cntn, Rot);
  }
  return;
}
void Del(const int &y) {
  // printf("Del %d %d\n", x - N, y);
  Node *x(Fnd(Rot, y));
  if (!x) {
    return;
  }
  if (x->x_Cnt > 1) {
    --(x->Siz);
    --(x->x_Cnt);
    return GoUp(x);
  }
  Spl(x, Rot);
  if (x->Ls) {
    x->Ls->Fa = NULL;
  }
  if (x->Rs) {
    x->Rs->Fa = NULL;
  }
  if (!x->Ls) {
    Rot = x->Rs;
    return;
  }
  if (!x->Rs) {
    Rot = x->Ls;
    return;
  }
  Node *TmpSon = GoRi(x->Ls);
  Spl(TmpSon, x->Ls);
  TmpSon->Rs = x->Rs;
  x->Rs->Fa = TmpSon;
  TmpSon->Siz += TmpSon->Rs->Siz;
  Rot = TmpSon;
  return;
}
void Val_Rate(Node *x, const int &y) {
  if (y < x->val) {
    return Val_Rate(x->Ls, y);
  }
  if (y > x->val) {
    return Val_Rate(x->Rs, y);
  }
  return Spl(x, Rot);
}
void Rate_Val(Node *x, int y) {
  if (x->Ls) {
    if (x->Ls->Siz >= y) {
      return Rate_Val(x->Ls, y);
    }
    y -= x->Ls->Siz;
  }
  if (x->x_Cnt >= y) {
    return Spl(x, Rot);
  }
  y -= x->x_Cnt;
  return Rate_Val(x->Rs, y);
}
void Bfr(Node *x, const int &y) {
  /*if (!x) {
    printf("%d, FAQ\n", x - N);
    return;
  }*/
  // printf("Bfr %d val %d y %d ls %d rs %d\n", x - N, x->val, y, x->Ls - N,
  //    x->Rs - N);
  if (x->val >= y) {
    return Bfr(x->Ls, y);
  } else {
    if (x->Rs) {
      Node *TmpSon(GoLe(x->Rs));
      if (TmpSon->val < y) {
        return Bfr(x->Rs, y);
      }
    }
    return Spl(x, Rot);
  }
}
void Aft(Node *x, const int &y) {
  // printf("Aft %d val %d y %d\n", x - N, x->val, y);
  if (x->val <= y) {
    return Aft(x->Rs, y);
  } else {
    if (x->Ls) {
      Node *TmpSon(GoRi(x->Ls));
      if (TmpSon->val > y) {
        return Aft(x->Ls, y);
      }
    }
    return Spl(x, Rot);
  }
}
int main() {
  // freopen("P3369_7.in", "r", stdin);
  // freopen("p3369.out", "w", stdout);
  Clr();
  for (register int i(1); i <= m; ++i) {
    DW = RD();
    A = RD();
    if (DW == 1) {
      Add(Rot, A);
    } else {
      if (DW == 2) {
        if (i == 14) {
          DW = 0;
        }
        Del(A);
      } else {
        ++cntans;
        if (cntans == 1188) {
          cntans = 1188;
        }
        // printf("Now %d  ", i);
        if (DW == 3) {
          Val_Rate(Rot, A);
          if (Rot->Ls) {
            printf("%d\n", Rot->Ls->Siz + 1);
          } else {
            printf("1\n");
          }
        } else {
          if (DW == 4) {
            Rate_Val(Rot, A);
            printf("%d\n", Rot->val);
          } else {
            if (DW == 5) {
              if (i == 12) {
                DW = 0;
              }
              Bfr(Rot, A);
              printf("%d\n", Rot->val);
            } else {
              Aft(Rot, A);
              printf("%d\n", Rot->val);
            }
          }
        }
      }
    }
  }
  // system("pause");
  /*while (1) {
    system("");
  }*/
  // ti = clock() - ti;
  // printf("Time : %lld ms\n", ti);
  return 0;
}
// faq
//加油
// bye!!