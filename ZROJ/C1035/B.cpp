#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned m, n, A;
char a[500005];
struct Node {
  Node *LS, *RS, *Fa;
  unsigned Size;
  char Tag, Val;
} N[500005], *Rot;
inline Node* Bld(unsigned L, unsigned R, Node *fa) {
  unsigned Mid((L + R) >> 1);
  N[Mid].Fa = fa, N[Mid].Size = R - L + 1, N[Mid].Val = a[Mid]; 
  N[Mid].LS = (Mid > L) ? Bld(L, Mid - 1, N + Mid) : NULL;
  N[Mid].RS = (Mid < R) ? Bld(Mid + 1, R, N + Mid) : NULL;
  return N + Mid;
}
inline void PsDw(Node *x) {
  if (x->Tag) {
    swap(x->LS, x->RS);
    if (x->LS) x->LS->Tag ^= 1;
    if (x->RS) x->RS->Tag ^= 1;
    x->Tag ^= 1;
  }
  return;
}
Node *Fnd(Node *x, unsigned y) {
  PsDw(x);
  if (x->LS) {
    if (x->LS->Size >= y) return Fnd(x->LS, y);
    y -= x->LS->Size;
  }
  if (y == 1) return x;
  --y;
  return Fnd(x->RS, y);
}
void Trn(Node *x) {
  if (!x->Fa) return;
  Node *Tmpfa(x->Fa);
  PsDw(Tmpfa), x->Fa = Tmpfa->Fa;
  if (Tmpfa->Fa) {
    if (Tmpfa == Tmpfa->Fa->LS) Tmpfa->Fa->LS = x;
    else Tmpfa->Fa->RS = x;
  }
  Tmpfa->Fa = x;
  if (x == Tmpfa->LS) {
    Tmpfa->LS = x->RS;
    if (x->RS) x->RS->Fa = Tmpfa;
    x->RS = Tmpfa;
  } else {
    Tmpfa->RS = x->LS;
    if (x->LS) x->LS->Fa = Tmpfa;
    x->LS = Tmpfa;
  }
  Tmpfa->Size = x->Size = 1;
  if (Tmpfa->LS) Tmpfa->Size += Tmpfa->LS->Size;
  if (Tmpfa->RS) Tmpfa->Size += Tmpfa->RS->Size;
  if (x->LS) x->Size += x->LS->Size;
  if (x->RS) x->Size += x->RS->Size;
  return;
}
void Spl(Node *x, Node *y) {
  Node *fa(y->Fa);
  if (x == y) return;
  while (x->Fa != fa) {
    if (x->Fa->Fa == fa) {Trn(x);break;}
    if (x == x->Fa->LS) {
      if (x->Fa == x->Fa->Fa->LS) Trn(x->Fa), Trn(x);
      else Trn(x), Trn(x);
    } else {
      if (x->Fa == x->Fa->Fa->RS) Trn(x->Fa), Trn(x);
      else Trn(x), Trn(x);
    }
  }
  if (!fa) Rot = x;
  return;
}
void Flp(Node *x) {
  Spl(Fnd(Rot, 1), Rot);
  PsDw(Rot);
  Spl(Fnd(Rot, A + 2), Rot->RS);
  Rot->RS->LS->Tag ^= 1;
}
void Prt(Node *x) {
  PsDw(x);
  if (x->LS) Prt(x->LS);
  if(x->Val) putchar(x->Val);
  if (x->RS) Prt(x->RS);
  return;
}
int main() {
  //freopen("P3391_1.in", "r", stdin);
  //freopen("P3391.out", "w", stdout);
  n = RD(), m = RD();
  scanf("%s", a + 1);
//  for (unsigned i(1); i <= n; ++i) a[i] = i;
  Rot = Bld(0, n + 1, NULL);
  for (register int i(1); i <= m; ++i) A = RD(), Flp(Rot);
  Prt(Rot);
  // system("pause");
  return Wild_Donkey;
}
