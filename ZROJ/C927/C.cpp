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
const unsigned long long MOD(1000000007);
unsigned a[200005], Bin[200005], b[200005], Up[200005], Down[200005], UpCnt[200005], DownCnt[200005], Tmp[200005], f[200005];
unsigned m, n, Max(0), Ans(0), Now(0), A, B, C, D;
struct Node {
  Node *LS, *RS;
  unsigned Val;
}N[5000005], *Root[200005], *CntN(N);
void Add (Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->Val += B;
    if(x->Val >= MOD) x->Val -= MOD; 
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) {
    if(!(x->LS)) x->LS = ++CntN, x->LS->LS = x->LS->RS = NULL, x->LS->Val = 0; 
    Add(x->LS, L, Mid);
  } else {
    if(!(x->RS)) x->RS = ++CntN, x->RS->LS = x->RS->RS = NULL, x->RS->Val = 0; 
    Add(x->RS, Mid + 1, R);
  }
  x->Val = 0;
  if(x->LS) x->Val = x->LS->Val;
  if(x->RS) x->Val += x->RS->Val;
  if(x->Val >= MOD) x->Val -= MOD; 
  return;
}
void Qry1(Node *x, unsigned L, unsigned R) {
//  printf("Qry %u %u [%u, %u]\n", x - N, x->Val, L, R);
  if(A <= L) {
    B += x->Val;
    if(B >= MOD) B -= MOD; 
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(x->RS) Qry1(x->RS, Mid + 1, R);
  if(A <= Mid) if(x->LS) Qry1(x->LS, L, Mid);
  return;
}
void Qry2(Node *x, unsigned L, unsigned R) {
//  printf("Qry %u %u [%u, %u]\n", x - N, x->Val, L, R);
  if(A >= R) {
    B += x->Val;
    if(B >= MOD) B -= MOD; 
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(x->LS) Qry2(x->LS, L, Mid);
  if(A > Mid) if(x->RS) Qry2(x->RS, Mid + 1, R);
  return;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD() + 1;
  Bin[0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    Bin[i] = Bin[i - 1] << 1;
    if(Bin[i] >= MOD) Bin[i] -= MOD; 
  }
  for (register unsigned i(n - 1); i; --i) a[i] = b[i] = RD();
  sort(a + 1, a + n);
  D = unique(a + 1, a + n) - a;
  for (register unsigned i(1); i < n; ++i) b[i] = lower_bound(a + 1, a + D, b[i]) - a + 1;// printf("%u %u\n", i, b[i]);
  f[0] = 0x3f3f3f3f, ++D;
  Root[0] = ++CntN, Root[0]->LS = Root[0]->RS = NULL, Root[0]->Val = 0, A = D, B = 1, Add(Root[0], 1, D);
  for (register unsigned i(1); i < n; ++i) {
    Tmp[i] = lower_bound(f, f + Now + 1, b[i], greater<unsigned>()) - f;
//    printf("Qry Root %u\n", Tmp[i] - 1);
    A = b[i] + 1, B = 0; if(A) Qry1(Root[Tmp[i] - 1], 1, D);
    UpCnt[n - i] = B, A = b[i]; 
    if(Tmp[i] > Now) {
      Now = Tmp[i];
      f[Now] = b[i];
      Root[Now] = ++CntN, Root[Now]->LS = Root[Now]->RS = NULL, Root[Now]->Val = 0;
    } else {
      f[Tmp[i]] = max(f[Tmp[i]], b[i]);
    }
    Add(Root[Tmp[i]], 1, D);
  }
  for (register unsigned i(1); i < n; ++i) Up[i] = Tmp[n - i];// printf("%u %u\n", i, Up[i]);
  Now = 0, memset(f, 0, sizeof(f)), CntN = N;
  Root[0] = ++CntN, Root[0]->LS = Root[0]->RS = NULL, Root[0]->Val = 0, A = 1, B = 1, Add(Root[0], 1, D);
  for (register unsigned i(1); i < n; ++i) {
    Tmp[i] = lower_bound(f, f + Now + 1, b[i]) - f;
    A = b[i] - 1, B = 0; if(A) Qry2(Root[Tmp[i] - 1], 1, D);
    DownCnt[n - i] = B, A = b[i]; 
    if(Tmp[i] > Now) {
      Now = Tmp[i];
      f[Tmp[i]] = b[i];
      Root[Now] = ++CntN, Root[Now]->LS = Root[Now]->RS = NULL, Root[Now]->Val = 0;
    } else {
      f[Tmp[i]] = min(f[Tmp[i]], b[i]);
    }
    Add(Root[Tmp[i]], 1, D);
  }
  --n;
  for (register unsigned i(1); i <= n; ++i) {
    if(Max < Up[i] + (Down[i] = Tmp[n - i + 1]) - 1) {
      Max = Up[i] + Down[i] - 1;
      Ans = ((unsigned long long)UpCnt[i] * DownCnt[i] % MOD) * Bin[n - Max] % MOD;
    } else {
      if(Max == Up[i] + Down[i] - 1) {
        Ans += ((unsigned long long)UpCnt[i] * DownCnt[i] % MOD) * Bin[n - Max] % MOD;
        if(Ans >= MOD) Ans -= MOD;
      }
    }
  }
  printf("%u %u\n", Max, Ans);
  return Wild_Donkey;
}
/*
2
1 1

4
2 1 3 4

8
6 5 2 7 3 8 6 5
*/
