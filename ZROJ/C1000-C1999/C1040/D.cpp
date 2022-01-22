#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
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
unordered_map<unsigned, char> Sqr;
unsigned Log[100005], Bin[20], a[100005][20];
unsigned m, n;
unsigned A, B, C, t;
unsigned Ans[500005];
struct Que {
  unsigned L, R, Id, Pos;
  inline const char operator < (const Que& x) const {return Pos < x.Pos;}
}Q[1000005], * CntQ(Q);
struct Node {
  Node* LS, * RS;
  unsigned Val, Tag;
  inline void PsDw(unsigned Len) {
    if(Tag) {
      LS->Tag += Tag, LS->Val += ((Len + 1) >> 1) * Tag;
      RS->Tag += Tag, RS->Val += (Len >> 1) * Tag;
      Tag = 0;
    }
  }
  inline void Chg(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {Val += (R - L + 1), ++Tag;return;}
    unsigned Mid((L + R) >> 1);
    PsDw(R - L + 1);
    if(A <= Mid) LS->Chg(L, Mid);
    if(Mid < B) RS->Chg(Mid + 1, R);
    Val = LS->Val + RS->Val;
  }
  inline void Qry(unsigned L, unsigned R) {
    if((A <= L) && (R <= B)) {C += Val;return;}
    unsigned Mid((L + R) >> 1);
    PsDw(R - L + 1);
    if(A <= Mid) LS->Qry(L, Mid);
    if(Mid < B) RS->Qry(Mid + 1, R);
  }
}N[200005], * CntN(N);
inline void Build (Node* x, unsigned L, unsigned R) {
  x->LS = x->RS = NULL, x->Val = x->Tag = 0;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
inline unsigned ClcAnd (unsigned x, unsigned y) {
  unsigned LgLen(Log[y - x + 1]);
  return a[x][LgLen] & a[y - Bin[LgLen] + 1][LgLen];
}
inline void Clr() {
  memset(Ans, 0, (m + 1) << 2);
	n = RD(), m = RD(), CntN = N, CntQ = Q;
}
signed main() {
//  freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);
	for (unsigned i(0); i <= 32768; ++i) Sqr[i * i] = 1;
	for (unsigned i(1), j(0); i <= 100000; i <<= 1, ++j) Log[i] = j, Bin[j] = i;
	for (unsigned i(1); i <= 100000; ++i) Log[i] = max(Log[i], Log[i - 1]);
	t = RD();
	for (unsigned T(1); T <= t; ++T) {
		Clr();
		for (unsigned i(1); i <= n; ++i) a[i][0] = RD();
		for (unsigned i(1), j(0); (i << 1) <= n; i <<= 1, ++j)
		  for (unsigned k(n - (i << 1) + 1); k; --k)
		    a[k][j + 1] = a[k][j] & a[k + i][j];
		for (unsigned i(1); i <= m; ++i) {
			A = RD(), B = RD();
		  (++CntQ)->Pos = A - 1, CntQ->L = A, CntQ->R = B, CntQ->Id = i;
		  (++CntQ)->Pos = B, CntQ->L = A, CntQ->R = B, CntQ->Id = i;
    }
    sort(Q + 1, CntQ + 1), Build(N, 1, n), (CntQ + 1)->Pos = n + 10;
    for (unsigned i(1), RP, Now, q(1); i <= n; ++i) {
      Now = a[i][0], RP = i;
      while (Q[q].Pos < i) {
        A = Q[q].L, B = Q[q].R, C = 0, N->Qry(1, n);
//        printf("Pos %u [%u, %u] is %u\n", i - 1, A, B, C);
        if(Q[q].Pos ^ Q[q].R) Ans[Q[q].Id] -= C;
        else Ans[Q[q].Id] += C;
        ++q;
      }
      while (1) {
  			unsigned BL(RP + 1), BR(n + 1), BMid;
  			while (BL < BR) {
  			  BMid = (BL + BR) >> 1;
//          printf("[%u, %u] = %u\n", i, BMid, ClcAnd(i, BMid));
  			  if(ClcAnd(i, BMid) ^ Now) BR = BMid;
  			  else BL = BMid + 1;
        }
        if(BL > n) {
//          printf("[%u, %u] = %u\n", i, n, ClcAnd(i, n));
          if(Sqr[ClcAnd(i, n)]) A = RP, B = n, N->Chg(1, n);
          break;
        }
        Now = ClcAnd(i, BL - 1);
//        printf("[%u, %u] = %u\n", i, BL - 1, Now);
        if(Sqr[Now]) A = RP, B = BL - 1, N->Chg(1, n);
        RP = BL;
      }
		}
		for (Que* i(CntQ); i->Pos >= n; --i) {
      A = i->L, B = i->R, C = 0, N->Qry(1, n);
      Ans[i->Id] += C;
    }
		for (unsigned i(1); i <= m; ++i) printf("%u\n", Ans[i]);
	}
	//  system("pause");
	return Wild_Donkey;
}
/*
2
8 8
52 62 29 6 27 0 34 8
5 6
1 3
3 5
6 8
2 6
2 7
3 8
2 4
3 2
1 2 3
2 2
1 3
*/
