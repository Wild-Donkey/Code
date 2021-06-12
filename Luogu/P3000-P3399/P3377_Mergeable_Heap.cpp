#include <cstdio>
#include <iostream>
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
unsigned m, n, A, B, t, Ans(0);
char Exist[100005];
struct Node {
  Node *LS, *RS;
  unsigned s, Val;
}N[100005], *C, *D; 
struct Set {
  Set *Fa;
  Node *Root;
}S[100005];
Node *Find(Set *x) {
  Set *Tmpx(x);
  while(Tmpx->Fa != Tmpx) Tmpx = Tmpx->Fa;
  return (x->Fa = Tmpx)->Root;
}
Node *Meld (Node *x, Node *y) {
  if(x->Val > y->Val || (x->Val == y->Val && x - N > y - N)) swap(x, y);
  if(x->RS) x->RS = Meld(x->RS, y);
  else x->RS = y;
  if(x->LS) {
    if(x->LS->s < x->RS->s) swap(x->LS, x->RS); // ���� 
    x->s = x->RS->s + 1;
  } else x->LS = x->RS, x->RS = NULL, x->s = 1; // ֻ��һ������ 
  return x;
}
int main() {
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) N[i].Val = RD();
  for (register unsigned i(1); i <= n; ++i) N[i].s = 1;
  for (register unsigned i(1); i <= n; ++i) S[i].Root = N + i;
  for (register unsigned i(1); i <= n; ++i) S[i].Fa = S + i;
  for (register unsigned i(1); i <= m; ++i) if(RD() & 1) {
    A = RD(), B = RD();
    if(Exist[A] || Exist[B]) continue;// ��ɾ�� 
    C = Find(S + A), D = Find(S + B);
    if(C != D) S[B].Fa->Fa = S[A].Fa, S[A].Fa->Root = Meld(C, D);  // ������ͬ, �ϲ�, ���²��鼯
  } else {
    A = RD();
    if(Exist[A]) {printf("-1\n");continue;}
    C = Find(S + A);  // ��
    printf("%u\n", C->Val); 
    Exist[C - N] = 1; // ɾ��
    if(C->LS && C->RS) S[A].Fa->Root = Meld(C->LS, C->RS);  // �ϲ���������
    else if(C->LS) S[A].Fa->Root = C->LS;                   // û�������� 
    else S[A].Fa->Root = NULL;                              // û����������û�������� 
  }
  return Wild_Donkey;
}
