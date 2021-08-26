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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), SzLft(0), A, B, C, D, t, Tmp(0);
long long ATmp, TmpC, TmpN, Ans;
struct Node {
  Node* LS, * RS;
  long long Bot, K;
  unsigned Size;
}N[1000005], * CntN(N), * Root(N);
void PsDw(Node* x) {
  register long long LSTmp(0);
  // printf("PsDw %u's %lld %lld to %u and %u\n", x - N, x->K, x->Bot, x->LS - N, x->RS - N);
  if (x->LS) x->LS->K += x->K, x->LS->Bot += x->Bot, LSTmp = x->LS->Size;
  if (x->RS) x->RS->K += x->K, x->RS->Bot += x->Bot + x->K * LSTmp;
  x->K = x->Bot = 0;
}
void DFS(Node* x) {
  if (x->Size == 1) { Ans = max(Ans, x->Bot); return; }
  PsDw(x);
  if (x->LS) DFS(x->LS);
  if (x->RS) DFS(x->RS);
  return;
}
Node* Add(Node* x) {
  // printf("Adding %u put %lld to %u\n", x - N, TmpC, A);
  ++(x->Size);
  if (x->Size == 2) {
    x->LS = ++CntN, x->RS = ++CntN;
    // printf("LS %u RS %u\n", x->LS - N, x->RS - N);
    x->RS->Bot = x->Bot, x->LS->Bot = TmpC;
    x->LS->Size = x->RS->Size = 1;
    x->K = x->Bot = 0;
    return x;
  }
  PsDw(x);
  if (x->LS) {
    if (A <= x->LS->Size) x->LS = Add(x->LS);
    else A -= x->LS->Size, x->RS = Add(x->RS);
  }
  else x->RS = Add(x->RS);
  if (!(x->LS)) return x->RS;
  if (!(x->RS)) return x->LS;
  if (x->Size > 3) {
    // printf("Now %u Size %u (%u, %u)\n", x - N, x->Size, x->LS->Size, x->RS->Size);
    if ((x->LS->Size * 3) < x->RS->Size) {
      // printf("Rotate %u Sz LS %u RS %u\n", x->RS - N, x->LS->Size, x->RS->Size);
      register Node* TmpNd(x->RS);
      PsDw(TmpNd);
      x->RS = TmpNd->RS;
      TmpNd->RS = TmpNd->LS;
      TmpNd->LS = x->LS;
      x->LS = TmpNd;
      TmpNd->Size = TmpNd->LS->Size + TmpNd->RS->Size;
    }
    if ((x->RS->Size * 3) < x->LS->Size) {
      // printf("Rotate %u Sz RS %u LS %u\n", x->LS - N, x->RS->Size, x->LS->Size);
      register Node* TmpNd(x->LS);
      PsDw(TmpNd);
      x->LS = TmpNd->LS;
      TmpNd->LS = TmpNd->RS;
      TmpNd->RS = x->RS;
      x->RS = TmpNd;
      TmpNd->Size = TmpNd->LS->Size + TmpNd->RS->Size;
    }
  }
  return x;
}
void Chg(Node* x, unsigned Cnt) {
  // printf("Chg %u, Size %u, of %u\n", x - N, x->Size, Cnt);
  if (x->Size <= Cnt) {
    x->Bot += ATmp * SzLft;
    x->K += ATmp;
    SzLft += x->Size;
    return;
  }
  PsDw(x);
  if (x->RS) {
    if (x->RS->Size < Cnt) {
      Chg(x->LS, Cnt - x->RS->Size);
      Chg(x->RS, x->RS->Size);
    }
    else Chg(x->RS, Cnt);
  }
  else Chg(x->LS, Cnt);
}
long long Qry(Node* x) {
  // printf("Qry %u for %u Size %u, witch %lld\n", x - N, A, x->Size, x->Bot);
  if (x->Size == 1) return x->Bot;
  PsDw(x);
  if (x->LS) {
    if (x->LS->Size >= A) return Qry(x->LS);
    else { A -= x->LS->Size; return Qry(x->RS); }
  }
  else return Qry(x->RS);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  N->Bot = 0xafafafafafafafaf, N->Size = 1;
  TmpC = 0, A = 1, Root = Add(Root);
  TmpC = RDsg(), A = 2, Root = Add(Root);
  // for (register unsigned j(1); j <= 3; ++j) {
  //   A = j, printf("%u %lld\n", j, Qry(Root));
  // }
  for (register unsigned i(2); i <= n; ++i) {
    ATmp = RDsg();
    register unsigned L(1), R(i), Mid;
    while (L ^ R) {
      // printf("[%u, %u]\n", L, R);
      Mid = ((L + R) >> 1);
      A = Mid, TmpC = Qry(Root) + Mid * ATmp, A = Mid + 1, TmpN = Qry(Root);
      // printf("For %u here %lld or %lld\n", Mid, TmpC, TmpN);
      if (TmpC > TmpN) {//Choose
        R = Mid;
      }
      else {  //Not
        L = Mid + 1;
      }
    }
    // printf("Choose %u\n", L);
    A = L, TmpC = Qry(Root) + L * ATmp, A = L + 1, Root = Add(Root);
    SzLft = L + 1, Chg(Root, i + 1 - L);
    // for (register unsigned j(1); j <= i + 2; ++j) {
    //   A = j, printf("%u %lld\n", j, Qry(Root));
    // }
  }
  DFS(N);
  printf("%lld\n", Ans);
  // system("pause");
  return Wild_Donkey;
}

/*
5
1 1 1 1 1

5
-1 -1 -1 -1 -1
*/