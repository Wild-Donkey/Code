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
#define Lbt(x) ((x)&((~(x))+1))
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
struct Infor {
  unsigned x;
  int y;
  char Ty;
}Tip[2000005];
int Tree[2000005][2];
unsigned Li[2000005], *CntL(Li);
unsigned n, m, Lgm(0), C;
int A, B, D;
unsigned Cnt(0), Ans(0), Tmp(0);
char buf[300000], *Top(buf + 300000),*P3(buf);
inline void pc(char c){
	if(P3==Top) fwrite(buf,1,300000,stdout),P3=buf;
	*(P3++)=c;
}
inline void print(unsigned x){
	static char st[10],tp;
	while(x) st[++tp]=x%10, x/=10;
	while(tp)pc('0'+st[tp--]);
}
inline void ChgI(unsigned x) {while (x <= m) Tree[x][0] += B, x += Lbt(x);}
inline void ChgF(unsigned x) {while (x <= m) Tree[x][1] += B, x += Lbt(x);}
inline void Calc(unsigned x) {while (x) A += Tree[x][0], B += Tree[x][1], x -= Lbt(x);}
inline void Qry() {
  unsigned Cur;
  int TmA(0), TmB(0);
  for (unsigned i(Lgm); ~i; --i) if((Cur = Ans + (1 << i)) <= m) {
    TmA = A + Tree[Cur][0], TmB = B + Tree[Cur][1];
//    printf("lG %u %u %u Pos %u To %u %u\n", i, A, B, Ans, TmA, TmB);
    if(TmA < TmB) Ans = Cur, A = TmA, B = TmB;
  }
//  printf("Atlast %u: %u < %u\n", Ans, A, B);
  C = A, A = 0, B = 0, Calc(Ans + 1);
//  printf("Done %u(%u) Pre %u(%u)\n", B, Ans + 1, C, Ans);
  if(B < C) return;
  Ans = 0, TmA = A = 0, C = B;
  for (unsigned i(Lgm); ~i; --i) if((Cur = Ans + (1 << i)) <= m) {
    TmA = A + Tree[Cur][1];
//    printf("lG %u %u Pos %u To %u\n", i, A, Ans, TmA);
    if(TmA >= B) Ans = Cur, A = TmA;
  }
//  printf("Ans %u Get %u\n", Ans, A);
}
//  inline void Clr() {}
signed main() {
//  freopen("P6619_-1.in", "r", stdin);
//  freopen("P6619.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    if(RD() & 1) C = Tip[i].Ty = RD(), *(CntL++) = Tip[i].x = (RD() + C), Tip[i].y = RD();
    else Tip[i] = Tip[RD()], Tip[i].y = -(Tip[i].y);
  }
  sort(Li, CntL), CntL = unique(Li, CntL), m = CntL - Li, Li[m] = Li[m - 1] + 1, ++m; 
//  for (unsigned i(0); i < m; ++i) printf("%u ", Li[i]); putchar(0x0A);
  while ((1 << Lgm) <= m) ++Lgm; --Lgm;
//  printf("m = %u Lg %u\n", m, Lgm);
  for (unsigned i(1); i <= n; ++i) {
    B = Tip[i].y;
    if(Tip[i].Ty) ChgF(1), B = -B, ChgF(lower_bound(Li, CntL, Tip[i].x) - Li + 1);
    else ChgI(lower_bound(Li, CntL, Tip[i].x) - Li + 1);
    A = B = D = Ans = 0, Qry();
//    printf("Li[%u] = %u\n", Ans - 1, Li[Ans - 1]);
    if(!C) pc('P'), pc('e'), pc('a'), pc('c'), pc('e');
    else print(Li[Ans] - 1), pc(' '), print(C << 1);
    pc(0x0A);
  }
  fwrite(buf,1,P3 - buf,stdout);
//  }
  return Wild_Donkey;
}

