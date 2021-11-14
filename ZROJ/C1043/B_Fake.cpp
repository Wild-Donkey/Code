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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
const unsigned long long Mod(1000000007);
unsigned long long Sum[1000005], Ans(0);
unsigned Stack[1000005], STop(0);
unsigned Cnt(0), Deled(0);
unsigned n, t;
char a[1000005], Flg(0);
struct SubStr {
  SubStr* Nxt, * SubNxt, * Bot;
  unsigned L, R, GrandR, Lay;
}S[500005], * CntS(S);
signed main() {
  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  for (t = RD(); t; --t) {
    CntS = S, Cnt = Ans = 0, memset(a, 0, n + 2), memset(Sum, 0, (n + 2) << 3), scanf("%s", a + 1), n = strlen(a + 1);
    for (unsigned i(1); i <= n; ++i) if(a[i] == '(') Stack[++STop] = i; else {if(STop) --STop; else a[i] = ' ';}
    while (STop) a[Stack[STop--]] = ' ';
    for (unsigned i(1); i <= n; ++i) if((a[i] == '(') && (a[i + 1] == ')')) {
      ++Sum[i], --Sum[i + 2], (++CntS)->L = i, CntS->R = i + 1, CntS->Nxt = CntS + 1;
      while ((a[CntS->L - 1] == '(') && (a[CntS->R + 1] == ')')) --(CntS->L), ++(CntS->R), ++Sum[CntS->L], --Sum[CntS->R + 1];
      CntS->GrandR = CntS->R, CntS->Lay = 1;
    }
    if(CntS == S) {printf("0\n"); continue;}
    for (SubStr* i(S + 1); i < CntS; i = i->Nxt) i->Nxt = i + 1, i->Bot = i, i->SubNxt = NULL;
    CntS->Nxt = CntS->SubNxt = NULL, CntS->Bot = CntS, Flg = 1;
    while (Flg) {
      Flg = 0;
//      if(t <= 1) printf("Row %u %u\n", Cnt, Deled);
      SubStr* Hd(S + 1);
      while (Hd) {
        if((Hd->Nxt) && (Hd->Nxt->L == Hd->GrandR + 1)) {
          Hd->Bot->SubNxt = Hd->Nxt;
          Hd->Bot = Hd->Nxt->Bot;
          Hd->Lay += Hd->Nxt->Lay;
          Hd->GrandR = Hd->Nxt->GrandR;
          Hd = Hd->Nxt = Hd->Bot->Nxt;
          Flg = 1;
        } else {
          if ((Hd->Lay == 1) || (a[Hd->L - 1] == ')') || (a[Hd->GrandR + 1] == '(')) {++Cnt, Hd = Hd->Nxt; continue;}
          SubStr* Cur(Hd);
          for (unsigned long long i(1); i <= Hd->Lay; ++i, Cur = Cur->SubNxt) {
            Sum[Cur->L] = (Sum[Cur->L] + i * (Hd->Lay - i + 1) - 1) % Mod;
            Sum[Cur->R + 1] = Mod + Sum[Cur->R + 1] - ((i * (Hd->Lay - i + 1) - 1) % Mod);
            if(Sum[Cur->R + 1] >= Mod) Sum[Cur->R + 1] -= Mod;
            ++Deled;
          }
          Hd->R = Hd->GrandR, Hd->SubNxt = NULL, Hd->Bot = Hd;
          while ((a[Hd->L - 1] == '(') && (a[Hd->R + 1] == ')')) --(Hd->L), ++(Hd->R), ++Sum[Hd->L], --Sum[Hd->R + 1];
          Hd->GrandR = Hd->R, Flg = Hd->Lay = 1, Hd = Hd->Nxt;
        }
      }
    }
    for (unsigned i(1); i <= n; ++i) {Sum[i] += Sum[i - 1]; if(Sum[i] >= Mod) Sum[i] -= Mod; Ans += Sum[i] * i % Mod;}
    printf("%llu %u\n", Ans, Cnt);
  }
  return Wild_Donkey;
}
/*
254777291433210 4010147936
2
(()())()()
(()()())()
*/
