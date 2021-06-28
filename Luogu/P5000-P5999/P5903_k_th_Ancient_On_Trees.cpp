#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Seed, Log[500005], Bin[20], Hd(0), List[500005], InList[500005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline unsigned Rand(unsigned x) {
	x ^= x << 13, x ^= x >> 17, x ^= x << 5;return Seed = x;
}
unsigned long long Prt(0);
char Short(1);
struct Node {
  Node *Fa[20], *Son, *Bro, *LonSon, *Top;
  unsigned Len, DFSr, Deep;
}N[500005], *Root, *Top[500005];
void Link(Node *x, Node *y) {
  y->Bro = x->Son, x->Son = y;
}
void DFS1(Node *x) {
  Node *now(x->Son);
  x->Len = 1;
  while(now) {
    now->Deep = x->Deep + 1;
    now->Fa[0] = x;
    for (register unsigned i(0); now->Fa[i]; ++i) {
      now->Fa[i + 1] = now->Fa[i]->Fa[i];
    }
    DFS1(now);
    if(now->Len + 1 > x->Len) {
      x->Len = now->Len + 1;
      x->LonSon = now;
    }
    now = now->Bro;
  }
}
void DFS2(Node *x) {
//  printf("DFS2 %u\n", x - N);
  if(Short) Top[++Hd] = x, x->Top = x;
  Node *now(x->Son);
  x->DFSr = ++Cnt;
  InList[Cnt] = x - N;
  if(x->LonSon) {
    Short = 0;
    x->LonSon->Top = x->Top;
    DFS2(x->LonSon);
    Short = 1;
  }
  while(now) {
    if(now != x->LonSon) {
      DFS2(now);
    }
    now = now->Bro;
  }
}
signed main() {
  // double Ti(clock()), Mti(0);
//  freopen("P5903_4.in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Seed = RD();
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    if(!A) {
      Root = N + i;
      continue;
    }
    Link(N + A, N + i);
  }
  Root->Deep = 1;
  DFS1(Root), DFS2(Root);
  for (register unsigned i(1), L, R; i <= Hd; ++i) {
    register Node *x(Top[i]);
//    printf("%u %u\n", i, x - N);
    L = x->DFSr, R = L + x->Len - 1;
    for (register unsigned j(L); j <= R; ++j) {
      List[j] = x - N;
      if(x->Fa[0]) x = x->Fa[0];
      else break;
    }
  }
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) {
    Log[i] = j, Bin[j] = i;
  }
  for (register unsigned i(3); i <= n; ++i) {
    Log[i] = max(Log[i], Log[i - 1]);
  }
  for (register unsigned i(1), Delta; i <= m; ++i) {
    A = ((Rand(Seed) ^ Ans) % n) + 1;
    B = (Rand(Seed) ^ Ans) % N[A].Deep;
//    printf("%u's %u_th Ancient\n", A, B);
    if(!B) {Ans = A, Prt ^= (unsigned long long)i * Ans; continue;}
    register Node *x(N[A].Fa[Log[B]]);
    B -= Bin[Log[B]];
//    printf("Then %u 's %u_th\n", x - N, B);
    Delta = x->Top->Len - x->Len;
    if(Delta >= B) {
//      printf("Find %u %u %u %u\n", x->Top->DFSr, Delta, B, x->Top->DFSr + Delta - B);
      Ans = InList[x->Top->DFSr + Delta - B];
    } else {
      Ans = List[x->Top->DFSr + B - Delta];
    }
    Prt ^= (unsigned long long)i * Ans;
//    printf("%u %u\n", i, Ans);
  }
  printf("%llu\n", Prt);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
