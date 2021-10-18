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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
const unsigned long long Mod(998244353);
unsigned long long Ans[100005];
unsigned long long Heal[100005], Infe[100005], Clen[100005];
unsigned m, n, Hd(0), Tl(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  vector<Node*> Son;
  Node* Fa;
  unsigned long long f, P, Q, IP;
  unsigned IdG;
}N[100005], * Q[100005];
unsigned long long Pow(unsigned long long x, unsigned long long y) {
  unsigned long long TmP(1); 
  while (y) {
    if(y & 1) TmP = TmP * x % Mod; 
    x = x * x % Mod, y >>= 1;
  }
  return TmP;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
//  while (1) {
//    printf("%llu\n", Pow(RD(), Mod - 2));
//  }
  n = RD();
  for (unsigned i(1); i <= n; ++i)
    N[i].P = RD(), N[i].P = N[i].P * Pow(RD(), Mod - 2) % Mod;
//  for (unsigned i(1); i <= n; ++i) printf("P[%u] %llu\n", i, N[i].P);
  for (unsigned i(1); i <= n; ++i) N[i].Fa = N + RD(), ++(N[i].Fa->IdG);
  for (unsigned i(1); i <= n; ++i) N[i].Q = RD(), N[i].Q = N[i].Q * Pow(RD(), Mod - 2) % Mod;
  for (unsigned i(1); i <= n; ++i) { N[i].IP = Mod + 1 - N[i].P; if(N[i].IP >= Mod) N[i].IP -= Mod;}
  for (unsigned i(1); i <= n; ++i) if(!N[i].IdG) Q[++Tl] = N + i;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    Cur->f = 1; 
    for (auto i:Cur->Son) Cur->f = (Cur->f * (Mod + 1 - (i->f * i->Q % Mod))) % Mod;
    Cur->f = (Cur->P + (Cur->IP * (Mod + 1 - Cur->f))) % Mod;
    Ans[Cur - N] = Cur->f;
    Cur->Fa->Son.push_back(Cur);
    if(!(--(Cur->Fa->IdG))) Q[++Tl] = Cur->Fa;
  }
  for (unsigned i(1); i <= n; ++i) if(N[i].IdG) {
    Node* Beg(N + i), * Cur(Beg);
    unsigned long long Pi(1);
    Tl = 0;
    do Q[++Tl] = Cur, Cur->IdG = 0, Cur = Cur->Fa; while (Cur != Beg);
    for (unsigned j(1); j <= Tl; ++j) Q[Tl + j] = Q[j];
    for (unsigned k(1); k <= Tl; ++k) {
      Q[k]->f = 1;
      for (auto j:Q[k]->Son) Q[k]->f = (Q[k]->f * (Mod + 1 - (j->f * j->Q % Mod))) % Mod;
      Q[k]->f = (Q[k]->P + (Q[k]->IP * (Mod + 1 - Q[k]->f))) % Mod;
    }
    Hd = Tl << 1;
//    for (unsigned j(1); j <= Hd; ++j) printf("Tl %u Q %u = %u\n", Tl, j, Q[j] - N);
    Heal[0] = Infe[0] = 1;
    for (unsigned j(1); j <= Hd; ++j) Heal[j] = Heal[j - 1] * (Mod + 1 - Q[j]->f) % Mod;
    for (unsigned j(1); j <= Hd; ++j) Infe[j] = Infe[j - 1] * Q[j]->Q % Mod;
    for (unsigned j(Tl + 1); j <= Hd; ++j) {
      Ans[Q[j] - N] = 0;
      for (unsigned Len(1); Len < Tl; ++Len) {
        unsigned long long NoHeal(Mod + 1 - (Heal[j] * Pow(Heal[j - Len], Mod - 2) % Mod));
        unsigned long long Blow((Infe[j - 1] * Pow(Infe[j - Len], Mod - 2) % Mod) * (Mod + 1 - Q[j - Len]->Q) % Mod);
        Ans[Q[j] - N] = (Ans[Q[j] - N] + NoHeal * Blow) % Mod;
      }
      unsigned long long NoHeal(Mod + 1 - (Heal[j] * Pow(Heal[j - Tl], Mod - 2) % Mod));
      unsigned long long Blow(Infe[j - 1] * Pow(Infe[j - Tl], Mod - 2) % Mod);
      Ans[Q[j] - N] = (Ans[Q[j] - N] + Blow * NoHeal) % Mod;
    }
  }
  for (unsigned i(1); i <= n; ++i) printf("%llu ", Ans[i]);
  putchar(0x0A);
//  }
  return Wild_Donkey;
}
/*
817385286 256367026 847973004 143347552 22295561 950357896 812618672 919265979 198131837 648799301
817385286 256367026 847973004 143347552 22295561 950357896 812618672 919265979 198131837 648799301
*/
