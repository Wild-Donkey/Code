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
#include <vector>
#define Wild_Donkey 0
#define Lbt(x) ((x)&((~(x))+1))
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
const unsigned BS(1 << 20);
char buf1[BS],*P3=buf1;
inline void Ptc(char c){
	if(P3==buf1+BS) fwrite(buf1,1,BS,stdout),P3=buf1;
	*(P3++)=c;
}
inline void print(unsigned x){
	if(!x){
		Ptc('0');
		return;
	}
	static char st[10],tp;
	while(x)st[++tp]=x%10,x/=10;
	while(tp) Ptc('0'+st[tp--]);
}
struct El {
  unsigned a, b, Num;
  inline const char operator<(const El& x) const{return (a ^ x.a) ? (b <= x.b) : 1;}
}E[500005], Cur;
struct Qry {
  unsigned Num, Pos;
  inline const char operator<(const Qry& x) const{return Pos < x.Pos;}
}Q[1000005];
unsigned Tree[500005], aS[500005], bS[500005], Left[500005], Ans[500005];
unsigned STop(0), m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Add(unsigned x) {while(x <= n) ++Tree[x], x += Lbt(x); }
inline void Ask(unsigned x) {A = 0; while(x) A += Tree[x], x -= Lbt(x); }
//  inline void Clr() {}
signed main() {
//  freopen("stack.in", "r", stdin);
//  freopen("stack.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  E[0].b = 0x3f3f3f3f, E[0].a = E[0].Num = 0;
  for (unsigned i(1); i <= n; ++i) aS[i] = RD();
  for (unsigned i(1); i <= n; ++i) bS[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    Cur.a = aS[i], Cur.b = bS[i], Cur.Num = i;
    while (STop && (E[STop] < Cur)) --STop;
    Left[i] = E[STop].Num + 1, E[++STop] = Cur;
  }
  for (unsigned i(1); i <= m; ++i) {
    Q[i << 1].Num = Q[(i << 1) - 1].Num = i;
    Q[i << 1].Pos = (aS[i] = RD()) - 1;
    Q[(i << 1) - 1].Pos = (bS[i] = RD());
    Ans[i] = 0x3f3f3f3f;
  }
//  return 0;
  sort(Q + 1, Q + (m << 1) + 1), B = 1;
//  return 0; 
  while (!(Q[B].Pos)) ++B;
//  for (unsigned i(1); i <= n; ++i) printf("%u ", Left[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) {
    Add(Left[i]);
    Ask(i + 1), C = A;
    while (Q[B].Pos == i) {
      unsigned N(Q[B].Num);
      if(bS[N] == i) Ask(aS[N]), Ans[N] += A;
      else Ans[N] -= C;
      ++B;
    }
  }
  for (unsigned i(1); i <= m; ++i) print(Ans[i] - 0x3f3f3f3f), Ptc(0x0A);
  fwrite(buf1,1,P3-buf1,stdout);
//  }
  return Wild_Donkey;
}
/*
10 4
3 1 3 1 2 3 3 2 1 1
10 10 2 9 7 5 4 7 6 1
1 4
7 8
7 10
1 8
*/
