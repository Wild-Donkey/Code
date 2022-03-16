#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned a[100005], b[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Set {
  Set *Son[2], *Fa;
  unsigned Val, Size;
  inline void Prt() {
    if(Son[0]) Son[0]->Prt();
    printf("%u ", Val);
    if(Son[1]) Son[1]->Prt();
  }
  inline void PsUp() {
    Size = 1;
    if(Son[0]) Size += Son[0]->Size;
    if(Son[1]) Size += Son[1]->Size;
  }
  inline void Rotate() {
//    if(!Fa) return;
    Set* Cur(Fa);
    Fa = Cur->Fa;
//    printf("Rotate %u\n", Val);
//    Cur->Prt(), putchar(0x0A);
    char Ty(Cur->Son[1] == this);
    if(Cur->Fa) Cur->Fa->Son[Cur->Fa->Son[1] == Cur] = this;
    if(Cur->Son[Ty] = Son[Ty ^ 1]) Son[Ty ^ 1]->Fa = Cur;
    (Son[Ty ^ 1] = Cur)->Fa = this;
    Size = Cur->Size, Cur->PsUp();
//    Prt(), putchar(0x0A);
  }
  inline void Splay() {
//    printf("Splay %u %u %u\n", Val, Fa, this);
    Set* Cur(Fa), *Grd;
    while (Cur) {
      if(!(Grd = Cur->Fa)) return Rotate();
      char Tym(Cur->Son[1] == this), Tyf(Grd->Son[1] == Cur);
      if(Tym ^ Tyf) Rotate(), Rotate(); 
      else Cur->Rotate(), Rotate();
      Cur = Fa;
    }
//    printf("Done Splay %u\n", Size);
  }
  inline Set* Rank () {
//    printf("Find %u at %u Size %u\n", A, Val, Size);
    if(A == Val) {++B; if(Son[0]) B += Son[0]->Size; Splay(); return this;}
    if(A > Val) {
      ++B;
      if(Son[0]) B += Son[0]->Size;
      if(Son[1]) return Son[1]->Rank();
      else {Splay(); return this;}
    }
    if(Son[0]) return Son[0]->Rank();
    else { Splay(); return this;}
  }
  inline Set* Find() {
//    printf("%u in %u\n", B, Size);
    if(Son[0]) {
      if(B <= Son[0]->Size) return Son[0]->Find();
      else B -= Son[0]->Size;
    }
    if(B == 1) return this;
    --B;
    return Son[1]->Find();
  }
  inline Set* Delete() {
    Set* Rot;
//    printf("Cur %u:", Val), Prt(), putchar(0x0A);
    B = 0, Rot = Rank(), C = B;
//    printf("Rot %u:", Rot->Val), Rot->Prt(), putchar(0x0A);
//    printf("A %u B %u Size %u C %u\n", A, B, Rot->Size, C);
    Set* Me(Rot->Find()), *Nxt;
//    printf("Me %u Size %u \n", Me->Val, Me->Size);
    if(Rot->Size ^ C) {
      B = C + 1, (Nxt = Rot->Find())->Splay(), Me->Splay();
    //    printf("Me %u:", Me->Val), Me->Prt(), putchar(0x0A);
      Nxt->Son[0] = Me->Son[0], Nxt->PsUp(), Nxt->Fa = NULL;
      if(Nxt->Son[0]) Nxt->Son[0]->Fa = Nxt;
//    printf("Nxt %u\n", Nxt->Size);
      return Nxt;
    }
    Me->Splay();
    if(Me->Son[0]) Me->Son[0]->Fa = NULL;
//      if(Me->Son[0]) printf("Son %u %u\n", Me->Son[0]->Val, Me->Son[0]->Size);
    return Me->Son[0];
  }
}Pool[2000005], *CntS(Pool);
inline void Detail(Set *x) {
  printf("Set %u(%u) Sons %u %u Size %u Fa %u\n", x - Pool, x->Val, x->Son[0] - Pool, x->Son[1] - Pool, x->Size, x->Fa - Pool);
}
inline Set* Cnstr(unsigned* x, const unsigned y, Set* Fa) {
  if(!y) return NULL;
  if(y == 1) {
    *(++CntS) = {NULL, NULL, Fa, x[1], 1};
    return CntS;
  }
  unsigned Mid(y >> 1);
  Set* Rt(++CntS);
  *Rt = {Cnstr(x, Mid - 1, Rt), Cnstr(x + Mid, y - Mid, Rt), Fa, x[Mid], 1};
  Rt->PsUp();
//  printf("y %u, Size %u\n", y, Rt->Size);
  return Rt;
}
struct Node {
  Set *S;
  Node *LS, *RS;
  unsigned long long Inv, Sum;
  inline void Del(unsigned L, unsigned R) {
//    printf("%u in [%u, %u]\n", D, L, R);
    if(L == R) {S = NULL; return;}
    unsigned Mid((L + R) >> 1);
    if(D <= Mid) {
      if(RS->S) B = 0, RS->S = RS->S->Rank(), Inv -= B;
      LS->Del(L, Mid);
    }
    else {
      if(LS->S) B = 0, LS->S = LS->S->Rank(), Inv -= LS->S->Size - B;
      RS->Del(Mid + 1, R);
    }
    Sum = LS->Sum + RS->Sum + Inv;
//    printf("S %u Size %u\n", S - Pool, S->Size);
//    S->Prt(), putchar(0x0A);
    S = S->Delete();
//    printf("Del :");
//    if(S) S->Prt(); putchar(0x0A);
//    printf("[%u, %u] %llu Sum %llu\n", L, R, Inv, Sum);
  }
}N[200005], *CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Inv = x->Sum = 0, *(x->S = (++CntS)) = {NULL, NULL, NULL, a[L] = RD(), 1}, b[a[L]] = L; return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  for (unsigned i(L); i <= Mid; ++i)
    A = a[i], B = 0, x->RS->S = x->RS->S->Rank(), x->Inv += B;
  unsigned Ta[R - L + 1];
  for (unsigned i(L), j(Mid + 1), k(0); (i <= Mid) || (j <= R); ++k) {
    if(i > Mid) {Ta[k] = a[j++];continue;}
    if(j > R) {Ta[k] = a[i++];continue;}
    if(a[i] < a[j]) Ta[k] = a[i++];
    else Ta[k] = a[j++];
  }
  memcpy(a + L, Ta, (R - L + 1) << 2);
//  sort(a + L, a + R + 1);
//  for (unsigned k(L); k <= R; ++k) printf("%u ", a[k]); putchar(0x0A);
  x->S = Cnstr(a + L - 1, R - L + 1, NULL);
  x->Sum = x->LS->Sum + x->RS->Sum + x->Inv;
//  printf("[%u, %u] %llu\n", L, R, x->Sum);
}
//  inline void Clr() {}
signed main() {
//  freopen("P3157_2.in", "r", stdin);
//  freopen("P3157.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  Build(N, 1, n);
  printf("%llu\n", N->Sum);
  for (unsigned i(1); i < m; ++i) {
//    printf("Ans = %llu\n", N->Sum);
    D = b[A = RD()];
//    printf("Del %u at %u\n", A, D);
    N->Del(1, n);
    printf("%llu\n", N->Sum);
//    printf("N :"), N->S->Prt(), putchar(0x0A);
  }
//  for (Set *i(Pool + 1); i <= CntS; ++i) Detail(i);
//  }
//  system("pause");
  return Wild_Donkey;
}

