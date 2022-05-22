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
unsigned m, n(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[100005];
struct Seg {
  Seg *LS, *RS;
  unsigned Val;
  inline void Insert(Seg* x, unsigned L, unsigned R);
  inline void Find(Seg* x, unsigned L, unsigned R) {
//    printf("Find %u [%u, %u]\n", Val - (x ? x->Val : 0), L, R);
    if(A <= L && R <= B) { Ans += Val - (x ? x->Val : 0);return; }
    unsigned Mid((L + R) >> 1);
    if(A <= Mid && LS) LS->Find(x ? x->LS : NULL, L, Mid);
    if(B > Mid && RS) RS->Find(x ? x->RS : NULL, Mid + 1, R);
  }
}S[2000005], *Ver[100005], *CntS(S);
inline void Seg::Insert(Seg* x, unsigned L, unsigned R) {
  if(x) *this = *x;
  ++Val;
  if(L == R) {return;}
  unsigned Mid((L + R) >> 1);
  if(A <= Mid) (LS = ++CntS)->Insert(x ? x->LS : NULL, L, Mid);
  else (RS = ++CntS)->Insert(x ? x->RS : NULL, Mid + 1, R);
}
struct Node{
  vector<Node*> Son;
  Node *E[26], *Fa, *Fail, *Heavy, *Top;
  unsigned Dep, SizeF, SizeT, FailR, TrieR;
  char My;
  inline void DFST() {
    TrieR = ++Cnt;
    if(Heavy) Heavy->Top = Top, Heavy->DFST();
    for (char i(0); i < 26; ++i) 
      if(E[i] && (E[i] != Heavy)) E[i]->Top = E[i], E[i]->DFST();
  }
  inline void DFSF ();
}N[100005], *List[100005], *Rev[100005], *Last(N), *CntN(N);
inline void Node::DFSF () {
//  printf("DFS %u\n", this - N);
  Rev[FailR = ++Cnt] = this, SizeF = 1;
  for (auto i:Son) i->DFSF(), SizeF += i->SizeF; 
}
inline void BFS() {
  Node* Que[CntN - N + 3], **Hd(Que), **Tl(Que);
  for (char i(0); i < 26; ++i) if(N->E[i]) *(++Tl) = N->E[i];
  while (Hd < Tl) {
    Node *Cur(*(++Hd)), *Back(Cur->Fa->Fail);
//    printf("Cur %u Fa %u\n", Cur - N, Back - N);
    Cur->Dep = Cur->Fa->Dep + 1;
    while (Back && (!(Back->E[Cur->My]))) Back = Back->Fail;
    if(Back && Back->E[Cur->My]) Cur->Fail = Back->E[Cur->My];
    else Cur->Fail = N;
    for (char i(0); i < 26; ++i) if(Cur->E[i]) *(++Tl) = Cur->E[i];
  }
  for (Node** i(Tl); i > Que; --i) {
    (*i)->SizeT = 1;
    unsigned Mx(0);
    for (char j(0); j < 26; ++j) if((*i)->E[j]) {
      (*i)->SizeT += (*i)->E[j]->SizeT;
      if(Mx < (*i)->E[j]->SizeT)
        Mx = ((*i)->Heavy = (*i)->E[j])->SizeT;
    }
  }
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  scanf("%s", a + 1);
  A = strlen(a + 1), m = RD();
  while (A && (a[A] ^ 'P')) --A;
//  printf("A %u\n", A);
  for (unsigned i(1); i <= A; ++i) {
//    printf("Cur %u\n", Last - N);
    if(a[i] == 'P') {List[++n] = Last; continue;}
    if(a[i] == 'B') {Last = (Last->Fa ? Last->Fa : N); continue;}
    if(!(Last->E[a[i] -= 'a']))
      (Last->E[a[i]] = ++CntN)->Fa = Last, (Last = CntN)->My = a[i];
  }
  BFS(), N->DFST(), Cnt = 0;
//  printf("Done\nFa:");
//  for (Node *i(N); i <= CntN; ++i) printf("%u ", i->Fail - N); putchar(0x0A);
  for (Node *i(N + 1); i <= CntN; ++i) i->Fail->Son.push_back(i);
//  for (Node *i(N); i <= CntN; ++i) printf("%u ", i->Son.size()); putchar(0x0A);
  N->Top = N, N->DFSF();
//  for (unsigned i(1); i <= n; ++i) printf("%u ", List[i] - N); putchar(0x0A); 
  for (unsigned i(1); i <= Cnt; ++i)
    A = Rev[i]->TrieR, (Ver[i] = ++CntS)->Insert(Ver[i - 1], 1, Cnt);
//  for (unsigned i(1); i <= Cnt; ++i)
//    printf("Ver %u Node %u Add %u\n", i, Rev[i] - N, Rev[i]->TrieR);
//  printf("m %u\n", m);
  for (unsigned i(1); i <= m; ++i) {
    Node *QrySt(List[RD()]), *ModleSt(List[RD()]);
//    printf("Qr %u Md %u\n", QrySt - N, ModleSt - N);
//    printf("DFSR Qr %u Md %u Size %u\n", QrySt->FailR, ModleSt->TrieR, QrySt->SizeF);
    Seg *Frm(Ver[QrySt->FailR - 1]), *Too(Ver[QrySt->FailR + QrySt->SizeF - 1]);
//    printf("Frm %u Too %u\n", Frm - S, Too - S);
    Ans = 0;
    while (ModleSt) {
      A = ModleSt->Top->TrieR, B = ModleSt->TrieR;
//      printf("Qry [%u, %u]\n", A, B);
      Too->Find(Frm, 1, Cnt);
      ModleSt = ModleSt->Top->Fa;
    }
    printf("%u\n", Ans);
  }
//  }
  return Wild_Donkey;
}
/*
abcdPBBBBbcP
1
2 1
*/

