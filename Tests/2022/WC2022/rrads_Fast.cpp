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
const unsigned BS(1<<20);
char buf[BS],*P1,*P2;
inline char gc(){
	if(P1==P2)P2=(P1=buf)+fread(buf,1,BS,stdin);
	return P1==P2?EOF:*(P1++);
}
inline unsigned RD(){
	unsigned x(0);char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')x=x*10+ch-48, ch=gc();
	return x;
}
char buf1[BS],*P3=buf1;
inline void pc(char c){
	if(P3==buf1+BS) fwrite(buf1,1,BS,stdout),P3=buf1;
	*(P3++)=c;
}
inline void print(unsigned long long x){
	if(!x){
		pc('0');
		return;
	}
	static char st[20],tp;
	while(x)st[++tp]=x%10,x/=10;
	while(tp)pc('0'+st[tp--]);
}
const inline unsigned Dif(const unsigned &x, const unsigned &y) { return (x < y) ? (y - x) : (x - y); }
bitset<500005> Ava;
unsigned long long Ans[500005], Tmp, Cur;
unsigned a[500005], m, n, B, NL, NR;
unsigned C, D;
char Flg(0);
struct Qry {
  unsigned L, R, Nu, Bl;
  const inline char operator < (const Qry& x) const {
    return (Bl ^ x.Bl) ? (Bl < x.Bl) : (R > x.R);
  }
}Q[500005];
struct Link {
  unsigned Pre, Aft, Pos;
}N[500005];
struct Back{
  unsigned *Pos, Val;
}Stack[1000005], *STop(Stack);
inline void Init(unsigned Le, unsigned Ri) {
  for (unsigned i(Le); i <= Ri; ++i) Ava[a[i]] = 1;
  unsigned Hd(0), Tl(0);
  Cur = 0;
  for (unsigned i(1); i <= n; ++i) 
    if (Ava[i]) {N[Hd].Aft = i, N[i].Pre = Hd; if(!Hd) Tl = i; else Cur += Dif(N[i].Pos, N[Hd].Pos); Hd = i, Ava[i] = 0; }
  N[Hd].Aft = 0;
}
inline void Del(Link* x) {
  unsigned TA(x->Pos), TB(N[x->Pre].Pos), TC(N[x->Aft].Pos);
  if (TB) {
    if (Flg) *(++STop) = Back{&(N[x->Pre].Aft), N[x->Pre].Aft};
    N[x->Pre].Aft = x->Aft, Cur -= Dif(TB, TA);
  }
  if (TC) {
    if (Flg) *(++STop) = Back{&(N[x->Aft].Pre), N[x->Aft].Pre};
    N[x->Aft].Pre = x->Pre, Cur -= Dif(TC, TA);
  }
  if (TB && TC) Cur += Dif(TB, TC);
}
signed main() {
//   freopen("rrads2.in", "r", stdin);
//   freopen("rrads.out", "w", stdout);
  n = RD(), m = RD(), B = (n / sqrt(m)) + 1;
  for (unsigned i(0); i < n; ++i) N[a[i] = RD()].Pos = i + 1;
  for (unsigned i(1); i <= m; ++i) Q[i].L = RD() - 1, Q[i].R = RD() - 1, Q[i].Nu = i, Q[i].Bl = Q[i].L / B;
  sort(Q + 1, Q + m + 1);
  for (unsigned i(1), j(0); i <= m; ++j) {
    if ((Q[i].L / B) ^ j) continue;
    unsigned Le(j * B);
    Init(NL = Le, NR = Q[i].R), Tmp = Cur, STop = Stack;
    while ((Q[i].L < (j + 1) * B) && (i <= m)) {
      while (STop > Stack) *(STop->Pos) = STop->Val, --STop;
      Cur = Tmp, Flg = 0, NL = Le;
      while (NR > Q[i].R) Del(N + a[NR--]);
      Flg = 1, Tmp = Cur;
      while (NL < Q[i].L) Del(N + a[NL++]);
      Ans[Q[i].Nu] = Cur, ++i;
    }
  }
  for (unsigned i(1); i <= m; ++i) print(Ans[i]), pc(0x0A);
	fwrite(buf1,1,P3-buf1,stdout);
  return Wild_Donkey;
}
