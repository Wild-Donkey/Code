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
struct Node {
  Node *Ls, *Rs;
  long long Val, Tag, L, R;
} N[200005], *cntn(N);
long long a[100005];
int A, B, C, n, m, k, DWt;
void Clr () {
  memset(N, 0, sizeof(N));
  cntn = N;
  return;
}
Node *BldT(const int &l, const int &r) {
  //printf("Bld %d, in[%d,%d]\n",cntn+1-N, l,r);
  Node *now(cntn++);
  now->L = l;
  now->R = r;
  if(l == r) {
    now->Val = a[l];
    now->Ls = now->Rs = NULL;
    return now;
  }
  int m = (l + r) >> 1;
  now->Ls = BldT(l, m);
  now->Rs = BldT(m + 1, r);
  now->Val = now->Ls->Val + now->Rs->Val;
  return now;
}
inline bool InRg (Node *x) {
  if(x->L >= A && x->R <= B) {
    return 1;
  }
  return 0;
}
inline bool OtRg (Node *x) {
  if(x->R < A || x->L > B) {
    return 1;
  }
  return 0;
}
void Udt(Node *x) {
  if(x->L == x->R) {
    return;
  }
  x->Val = x->Ls->Val + x->Rs->Val;
  return;
}
void Dld(Node *x) {
  if(!(x->Tag)) {
    return;
  }
  if(!(x->L == x->R)) {
    x->Ls->Tag += x->Tag;
    x->Rs->Tag += x->Tag;
    x->Ls->Val += x->Tag * (x->Ls->R - x->Ls->L + 1);
    x->Rs->Val += x->Tag * (x->Rs->R - x->Rs->L + 1);
  }
  x->Tag = 0;
  return;
}
void Chg(Node *x) {
  if(OtRg(x)) {
    return;
  }
  if(InRg(x)) {
    x->Tag += C;
    x->Val += C * (x->R - x->L + 1);
    return;
  }
  Dld(x);
  Chg(x->Ls);
  Chg(x->Rs);
  Udt(x);
  return;
}
long long Fnd(Node *x) {
  //printf("Fnd %d, V=%d, in[%d,%d]\n", x-N, x->Val, x->L, x->R);
  if(OtRg(x)) {
    return 0;
  }
  if(InRg(x)) {
    return x->Val;
  }
  Dld(x);
  long long tmp (Fnd(x->Ls));
  return tmp + (Fnd(x->Rs));
}
int main() {
  //freopen("P3372_2.in", "r", stdin);
  //freopen("P3372.out", "w", stdout);
  Clr();
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  BldT(1, n);
  for (register int i(1); i <= m; ++i) {
    DWt = RD();
    A = RD();
    B = RD();
    if(A > B) {
      swap(A, B); 
    } 
    if(DWt == 1) {
      C = RD();
      Chg(N);
    } else {
      printf("%lld\n", Fnd(N));
    }
  }
  return 0;
}
