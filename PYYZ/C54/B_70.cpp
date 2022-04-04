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
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return x;
}
bitset<1000005> No;
struct Node;
struct Edge {
  Node *To[2];
  unsigned Val;
}Ed[100005];
unsigned Pri[100005], Cnt[1000005], TmpP[1000005];
unsigned Stack[1000005], *STop(Stack);
unsigned long long Ans(0), Tmp(0);
unsigned m, n, CntP(0);
unsigned A, B, C, D, t;
struct Node {
  vector <Edge*> E;
  map<unsigned, unsigned> Val;
  inline void DFS(Edge* Fa) {
//    printf("DFS %u %u\n", this, Fa);
    Val.clear();
    unordered_map<unsigned, unsigned> TmpM;
    for (auto i:E) if(i != Fa){
      Node*Cur(i->To[i->To[0] == this]);
      Cur->DFS(i);
//      for (unsigned j(1); j <= 10; ++j) printf("%u ", TmpM[j]); putchar(0x0A);
      for (auto j:Cur->Val) {
        unsigned G(Gcd(j.first, i->Val));
        if(G == 1) Tmp += j.second;
        for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
          if(Cnt[k] < 0x3f3f3f3f) {
            if(Cnt[k] & 1) Tmp -= (unsigned long long)j.second * TmpM[k];
            else Tmp += (unsigned long long)j.second * TmpM[k];
          }
          unsigned ToG(G / k);
          if(Cnt[ToG] < 0x3f3f3f3f && (k ^ ToG)) {
            if(Cnt[ToG] & 1) Tmp -= (unsigned long long)j.second * TmpM[ToG];
            else Tmp += (unsigned long long)j.second * TmpM[ToG];
          }
        }
      }
      for (auto j:Cur->Val) {
        unsigned G(Gcd(j.first, i->Val));
//        printf("Add %u\n", G);
        Val[G] += j.second;
        for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
          unsigned ToG(G / k);
          if(Cnt[k] < 0x3f3f3f3f) TmpM[k] += j.second; 
          if(Cnt[ToG] < 0x3f3f3f3f && (ToG ^ k)) TmpM[ToG] += j.second;
        }
      }
//      printf("%u Now %llu\n", this, Tmp);
    }
    if(Fa) ++Val[Fa->Val];
//    printf("%u:", this);
//    for (auto i:Val) printf("(%u,%u)", i.first, i.second); putchar(0x0A);
  }
  inline void DFS2(Edge* Fa) {
    Val.clear();
    for (auto i:E) if(i != Fa){
      Node*Cur(i->To[i->To[0] == this]);
      Cur->DFS2(i);
      for (auto j:Cur->Val) Val[Gcd(j.first, i->Val)] += j.second;
    }
    if(Fa) ++Val[Fa->Val];
  }
}N[100005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Cnt[1] = 0, Cnt[0] = 0;
  for (unsigned i(2); i <= 1000000; ++i) {
    if(!No[i]) Pri[++CntP] = i, Cnt[i] = 1;
    for (unsigned j(1), k(i << 1); (k <= 1000000) && (j <= CntP); ++j, k = Pri[j] * i) {
      No[k] = 1, Cnt[k] = Cnt[i] + 1;
      if(!(i % Pri[j])) Cnt[k] = 0x3f3f3f3f;
    }
  }
  n = RD();
  for (unsigned i(1); i < n; ++i) {
    Ed[i].To[0] = N + (A = RD());
    Ed[i].To[1] = N + (B = RD());
    Ed[i].Val = RD();
    N[A].E.push_back(Ed + i);
    N[B].E.push_back(Ed + i);
  }
  N[1].DFS(NULL), Ans = Tmp;
  printf("%llu\n", Ans);
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), Tmp = 0;
    Ed[A].To[0]->DFS2(Ed + A);
    Ed[A].To[1]->DFS2(Ed + A);
    --(Ed[A].To[1]->Val[Ed[A].Val]);
    for (auto j:Ed[A].To[0]->Val) {
      unsigned G(Gcd(Ed[A].Val, j.first));
      if(G == 1) Tmp += j.second;
      for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
        unsigned ToG(G / k);
        if(Cnt[k] < 0x3f3f3f3f) TmpP[k] += j.second, *(++STop) = k;
        if(Cnt[ToG] < 0x3f3f3f3f && (ToG ^ k)) TmpP[ToG] += j.second, *(++STop) = ToG;
      }
    }
    for (auto j:Ed[A].To[1]->Val) {
      unsigned G(j.first);
      for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
        if(Cnt[k] < 0x3f3f3f3f) {
          if(Cnt[k] & 1) Tmp -= (unsigned long long)j.second * TmpP[k];
          else Tmp += (unsigned long long)j.second * TmpP[k];
        }
        if(Cnt[G / k] < 0x3f3f3f3f && ((k * k) ^ G)) {
          if(Cnt[G / k] & 1) Tmp -= (unsigned long long)j.second * TmpP[G / k];
          else Tmp += (unsigned long long)j.second * TmpP[G / k];
        }
      }
    }
    --(Ed[A].To[0]->Val[Ed[A].Val]);
    ++(Ed[A].To[0]->Val[Ed[A].Val = B]);
    Ans -= Tmp, Tmp = 0;
    while (STop > Stack) TmpP[*(STop--)] = 0;
    for (auto j:Ed[A].To[0]->Val) {
      unsigned G(Gcd(Ed[A].Val, j.first));
      if(G == 1) Tmp += j.second;
      for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
        unsigned ToG(G / k);
        if(Cnt[k] < 0x3f3f3f3f) TmpP[k] += j.second, *(++STop) = k;
        if(Cnt[ToG] < 0x3f3f3f3f && (ToG ^ k)) TmpP[ToG] += j.second, *(++STop) = ToG;
      }
    }
    for (auto j:Ed[A].To[1]->Val) {
      unsigned G(j.first);
      for (unsigned k(sqrt(G)); k; --k) if(!(G % k)){
        if(Cnt[k] < 0x3f3f3f3f) {
          if(Cnt[k] & 1) Tmp -= (unsigned long long)j.second * TmpP[k];
          else Tmp += (unsigned long long)j.second * TmpP[k];
        }
        if(Cnt[G / k] < 0x3f3f3f3f && ((k * k) ^ G)) {
          if(Cnt[G / k] & 1) Tmp -= (unsigned long long)j.second * TmpP[G / k];
          else Tmp += (unsigned long long)j.second * TmpP[G / k];
        }
      }
    }
    while (STop > Stack) TmpP[*(STop--)] = 0;
    Ans += Tmp;
    printf("%llu\n", Ans);
  }
//  }
  return Wild_Donkey;
}

