#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
} 
const unsigned long long Mod(1000000007);
unsigned long long Sum[1000005], Ans(0);
unsigned Stack[1000005], STop(0), n, t;
char a[1000005]; 
struct SubStr {
  SubStr* Last, * Nxt, * SubNxt, * Bot;
  unsigned L, R, GrandR, Lay;
  inline void Del () {
    if(Last) Last->Nxt = Nxt;
    if(Nxt) Nxt->Last = Nxt;
  }
}S[500005], * Head(S + 1), * CntS(S);
inline void Clr() {
  Head = (CntS = S) + 1, Ans = 0;
  memset(a, 0, n + 2), memset(Sum, 0, (n + 2) << 3);
  scanf("%s", a + 1), n = strlen(a + 1);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) if(a[i] == '(') Stack[++STop] = i; else {if(STop) --STop; else a[i] = ' ';}
    while (STop) a[Stack[STop--]] = ' ';
    for (unsigned i(1); i <= n; ++i) if((a[i] == '(') && (a[i + 1] == ')')) {
      ++Sum[i], --Sum[i + 2], (++CntS)->L = i, CntS->R = i + 1, CntS->Nxt = CntS + 1;
      while ((a[CntS->L - 1] == '(') && (a[CntS->R + 1] == ')')) --(CntS->L), ++(CntS->R), ++Sum[CntS->L], --Sum[CntS->R + 1];
      CntS->GrandR = CntS->R, CntS->Lay = 1;
    }
    if(CntS == S) {printf("0\n"); continue;}
    for (SubStr* i(Head); i <= CntS; i = i->Nxt) i->Last = i - 1, i->Nxt = i + 1, i->Bot = i, i->SubNxt = NULL;
    CntS->Nxt = CntS->SubNxt = Head->Last = NULL;
    while (Head) if((Head->Nxt) && (Head->Nxt->L == Head->GrandR + 1)) {
      Head->Bot->SubNxt = Head->Nxt;
      Head->Bot = Head->Nxt->Bot;
      Head->Lay += Head->Nxt->Lay;
      Head->GrandR = Head->Nxt->GrandR;
      Head->Nxt = Head->Bot->Nxt;
      if(Head->Nxt) Head->Nxt->Last = Head;
      continue;
    } else {
      if((a[Head->GrandR + 1] == '(') || (a[Head->L - 1] == ')')) {Head = Head->Nxt; continue;}
      if(Head->Lay == 1) {Head->Del(), Head = Head->Nxt;continue;}
      SubStr* Cur(Head);
      for (unsigned long long i(1); i <= Head->Lay; ++i, Cur = Cur->SubNxt) {
        Sum[Cur->L] = (Sum[Cur->L] + i * (Head->Lay - i + 1) - 1) % Mod;
        Sum[Cur->R + 1] = Mod + Sum[Cur->R + 1] - ((i * (Head->Lay - i + 1) - 1) % Mod);
        if(Sum[Cur->R + 1] >= Mod) Sum[Cur->R + 1] -= Mod;
      }
      Head->R = Head->GrandR, Head->SubNxt = NULL, Head->Bot = Head;
      while ((a[Head->L - 1] == '(') && (a[Head->R + 1] == ')')) --(Head->L), ++(Head->R), ++Sum[Head->L], --Sum[Head->R + 1];
      Head->GrandR = Head->R, Head->Lay = 1;
      if ((Head->Last) && (Head->Last->GrandR + 1 == Head->L)) {
        Head = Head->Last;
        Head->Bot->SubNxt = Head->Nxt;
        Head->Bot = Head->Nxt->Bot;
        Head->Lay += Head->Nxt->Lay;
        Head->GrandR = Head->Nxt->GrandR;
        Head->Nxt = Head->Bot->Nxt;
        if(Head->Nxt) Head->Nxt->Last = Head;
      }
    }
    for (unsigned i(1); i <= n; ++i) {
      Sum[i] += Sum[i - 1]; if(Sum[i] >= Mod) Sum[i] -= Mod;
      Ans += Sum[i] * i % Mod;
    }
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}
/*
2
(()())()()
(()()())()
*/
