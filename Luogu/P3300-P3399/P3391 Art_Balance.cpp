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
int m, n, A, B;
struct Node {
  int Val, Siz;
  Node *Ls, *Rs, *Fa;
  bool Tag;
} N[100005], *Rot;
const int Bld(const int x, const int y, Node *fa) {
  int m((x + y) >> 1);
  N[m].Fa = fa;
  N[m].Siz = y - x + 1;
  if (m > x) {
    N[m].Ls = N + Bld(x, m - 1, N + m);
  } else {
    N[m].Ls = NULL;
  }
  if (m < y) {
    N[m].Rs = N + Bld(m + 1, y, N + m);
  } else {
    N[m].Rs = NULL;
  }
  return m;
}
void Clr() {
  n = RD();
  m = RD();
  memset(N, 0, sizeof(N));
  Rot = N + ((1 + n) >> 1);
  Bld(0, n + 1, NULL);
  return;
}
inline void MkTg(Node *x) {
  x->Tag ^= 1;
  return;
}
inline void PsDw(Node *x) {
  if (x->Tag) {
    if (x->Ls) {
      MkTg(x->Ls);
    }
    if (x->Rs) {
      MkTg(x->Rs);
    }
    swap(x->Ls, x->Rs);
    MkTg(x);
  }
  return;
}
Node *Fnd(Node *x, int y) {
  PsDw(x);
  /*if (y <= 0) {
    y = 0x3f3f3f3f;
  }*/
  if (x->Ls) {
    if (x->Ls->Siz >= y) {
      return Fnd(x->Ls, y);
    }
    y -= x->Ls->Siz;
  }
  if (y == 1) {
    return x;
  }
  --y;
  /*if (!(x->Rs)) {
    y = 0x3f3f3f3f;
  }
  if (x->Rs->Siz < y) {
    y = 0x3f3f3f3f;
  }*/
  return Fnd(x->Rs, y);
}
void Trn(Node *x) {
  if (!x->Fa) {
    return;
  }
  Node *Tmpfa(x->Fa);
  PsDw(Tmpfa);
  x->Fa = Tmpfa->Fa;
  if (Tmpfa->Fa) {
    if (Tmpfa == Tmpfa->Fa->Ls) {
      Tmpfa->Fa->Ls = x;
    } else {
      Tmpfa->Fa->Rs = x;
    }
  }
  Tmpfa->Fa = x;
  if (x == Tmpfa->Ls) {
    Tmpfa->Ls = x->Rs;
    if (x->Rs) {
      x->Rs->Fa = Tmpfa;
    }
    x->Rs = Tmpfa;
  } else {
    Tmpfa->Rs = x->Ls;
    if (x->Ls) {
      x->Ls->Fa = Tmpfa;
    }
    x->Ls = Tmpfa;
  }
  Tmpfa->Siz = 1;
  x->Siz = 1;
  if (Tmpfa->Ls) {
    Tmpfa->Siz += Tmpfa->Ls->Siz;
  }
  if (Tmpfa->Rs) {
    Tmpfa->Siz += Tmpfa->Rs->Siz;
  }
  if (x->Ls) {
    x->Siz += x->Ls->Siz;
  }
  if (x->Rs) {
    x->Siz += x->Rs->Siz;
  }
  return;
}
void Spl(Node *x, Node *y) {
  Node *fa(y->Fa);
  if (x == y) {
    return;
  }
  while (x->Fa != fa) {
    if (x->Fa->Fa == fa) {
      Trn(x);
      break;
    }
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
  if (!fa) {
    Rot = x;
  }
  return;
}
void Flp(Node *x) {
  Node *rot(Fnd(Rot, A));
  Spl(rot, Rot);
  PsDw(Rot);
  Spl(Fnd(Rot, B + 2), Rot->Rs);
  MkTg(Rot->Rs->Ls);
}
void Prt(Node *x) {
  PsDw(x);
  if (x->Ls) {
    Prt(x->Ls);
  }
  if ((x - N > 0) && (x - N <= n)) {
    printf("%d ", x - N);
  }
  if (x->Rs) {
    Prt(x->Rs);
  }
  return;
}
int main() {
  freopen("P3391_1.in", "r", stdin);
  freopen("P3391.out", "w", stdout);
  Clr();
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    if (A == B) {
      continue;
    }
    Flp(Rot);
  }
  Prt(Rot);
  // system("pause");
  return 0;
}