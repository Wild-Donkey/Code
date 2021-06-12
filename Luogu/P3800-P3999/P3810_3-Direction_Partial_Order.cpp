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
#define Lowbit(x) ((x) & (-(x)))
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
unsigned m, n, NM(0), A, B, C, D, t, Tree[200005], Ans[100005];
inline unsigned Qry(unsigned Pos) {
  unsigned TmpQ(0);
  while (Pos) TmpQ += Tree[Pos], Pos -= Lowbit(Pos);
  return TmpQ;
}
inline void Add(unsigned Pos, unsigned Val) {while(Pos <= m) Tree[Pos] += Val, Pos += Lowbit(Pos);} 

inline void Minus(unsigned Pos, unsigned Val) {while(Pos <= m) Tree[Pos] -= Val, Pos += Lowbit(Pos);}

struct Group {
	unsigned a, b, c, Cnt, Same;
	inline const char operator<(const Group &x) {
	  return (this->b ^ x.b) ? (this->b < x.b) : (this->c < x.c);
  }
}G[100005];
inline const char cmp(const Group &x, const Group &y)  {
  return (x.a ^ y.a) ? (x.a < y.a) : ((x.b ^ y.b) ? (x.b < y.b) : (x.c < y.c));
}
void CDQ(unsigned L, unsigned R) {
//  printf("CDQ [%u, %u]\n", L, R);
  if(L == R) return; 
  register unsigned Mid((L + R) >> 1);
  CDQ(L, Mid);
  CDQ(Mid + 1, R);
  sort(G + L, G + Mid + 1);
  sort(G + Mid + 1, G + R + 1);
  register unsigned PointerL(L), PointerR(Mid + 1);
  while (PointerR <= R) {
    while (G[PointerL].b <= G[PointerR].b && PointerL <= Mid) Add(G[PointerL].c, G[PointerL].Same), ++PointerL;
    G[PointerR].Cnt += Qry(G[PointerR].c),++PointerR;
  }
  while (PointerL > L) --PointerL, Minus(G[PointerL].c, G[PointerL].Same);
//  printf("Cnt1 %u\n", Cnt[1]);
}
int main() {
	// double Ti(clock()), Mti(0);
//	 freopen("P3810_2.in", "r", stdin);
//	 freopen("P3810.out", "w", stdout);
	n = RD(), m = RD();
	for (register unsigned i(1); i <= n; ++i) G[i].a = RD(), G[i].b = RD(), G[i].c = RD();
	sort(G + 1, G + n + 1, cmp);
	for (register unsigned i(1); i <= n; ++i) {if((G[i].a ^ G[i - 1].a) || (G[i].b ^ G[i - 1].b) || (G[i].c ^ G[i - 1].c)) G[++NM] = G[i]; ++(G[NM].Same);}
//	for (register unsigned i(1); i <= NM; ++i) printf("%u Same %u\n", i, G[i].Same);
  CDQ(1, NM);
	for (register unsigned i(1); i <= NM; ++i) Ans[G[i].Cnt + G[i].Same - 1] += G[i].Same;
	for (register unsigned i(0); i < n; ++i) printf("%u\n", Ans[i]);

	return Wild_Donkey;
}
