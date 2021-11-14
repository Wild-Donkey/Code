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
unsigned long long b[1000005], a[1005][1005], * CntB;
unsigned Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Size;
unsigned m, n, Have[1000005], Ask[1005][1005];
char InTmp[15], Flg(0), QAns(0);
struct Node {
  Node* LS, * RS;
}N[200005], * CntN(N), * Last(N), * Root[1005];
void Hash() {
  char StrPos(0); ++Cnt;
  while (InTmp[StrPos] < 'a') ++StrPos;
  while (InTmp[StrPos] >= 'a') b[Cnt] = b[Cnt] * 27 + InTmp[StrPos] - '`', InTmp[StrPos++] = 0;
}
void Add(Node* x, unsigned short L, unsigned short R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) { if (x->LS < x) { if (x->LS) *(++CntN) = *(x->LS); else *(++CntN) = *N; x->LS = CntN; } Add(x->LS, L, Mid); }
  else { if (x->RS < x) { if (x->RS) *(++CntN) = *(x->RS); else *(++CntN) = *N; x->RS = CntN; }  Add(x->RS, Mid + 1, R); }
}
void Merge(Node* x, Node* y, unsigned short L, unsigned short R) {
  // printf("%u <- %u [%u, %u]\n", x - N, y - N, L, R);
  if (L == R) { Flg = 1; return; }
  unsigned Mid((L + R) >> 1);
  if (y->LS) {
    if (x->LS) *(++CntN) = *(x->LS), x->LS = CntN, Merge(CntN, y->LS, L, Mid);
    else x->LS = y->LS;
  }
  if (y->RS) {
    if (x->RS) *(++CntN) = *(x->RS), x->RS = CntN, Merge(CntN, y->RS, Mid + 1, R);
    else x->RS = y->RS;
  }
}
void Qry(Node* x, unsigned short L, unsigned short R) {
  if (L == R) { QAns = 1;return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) { if (x->LS) return Qry(x->LS, L, Mid); }
  else { if (x->RS) return Qry(x->RS, Mid + 1, R); }
}
inline const char Cmp(const unsigned x, const unsigned y) { return Have[x] > Have[y]; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned short i(1); i <= n; ++i) {
    scanf("%s", &InTmp), Hash(), a[i][++a[i][0]] = b[Cnt], scanf("%s", &InTmp);
    for (;;) {
      scanf("%s", &InTmp);
      if (InTmp[0] == ';') break;
      else Hash(), a[i][++a[i][0]] = b[Cnt];
    }
  }
  sort(b + 1, b + Cnt + 1), CntB = unique(b + 1, b + Cnt + 1);
  for (unsigned short i(1); i <= n; ++i) {
    Ask[i][0] = a[i][0];
    for (unsigned short j(1); j <= a[i][0]; ++j) {
      Ask[i][j] = lower_bound(b + 1, CntB, a[i][j]) - b;
      // printf("%u ", Ask[i][j]);
    }
    // putchar('\n');
  }
  Size = CntB - b;
  // printf("Size %u\n", Size);
  for (unsigned short i(1); i <= n; ++i) {
    Flg = 0, Last = CntN;
    if (Have[Ask[i][1]]) Flg = 1;
    else {
      for (unsigned short j(2); j <= Ask[i][0]; ++j)
        if (!Have[Ask[i][j]]) { Flg = 1; break; }
      if (!Flg) {
        Root[i] = ++CntN, * CntN = *N;
        sort(Ask[i] + 2, Ask[i] + Ask[i][0] + 1, Cmp);
        for (unsigned short j(2); j <= Ask[i][0]; ++j) {
          QAns = 0, A = Have[Ask[i][j]], Qry(Root[i], 1, n);
          if (QAns) continue;
          if (Root[Have[Ask[i][j]]]) Merge(Root[i], Root[Have[Ask[i][j]]], 1, n);
          if (Flg) break;
          A = Have[Ask[i][j]], Add(Root[i], 1, n);
        }
      }
    }
    if (!Flg) Have[Ask[i][1]] = i;
    else { CntN = Last; if (!(Have[Ask[i][1]])) Root[i] = NULL; }
    printf(Flg ? "greska\n" : "ok\n");
  }
  // system("pause");
  return Wild_Donkey;
}
/*
4
asdlffkjfj : ;
bkdfgkufdg : asdlffkjfj ;
cdkfugdfgr : bkdfgkufdg ;
dieurhhgfd : bkdfgkufdg cdkfugdfgr ;
*/