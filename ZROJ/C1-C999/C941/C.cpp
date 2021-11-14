#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define C(x,y) ((((Fac[x]*Inv[y])%(MOD[Pr]))*Inv[(x)-(y)])%MOD[Pr])
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
unsigned Pr, MOD[5] = {2, 3, 4679, 35617, 999911659}, n, m, k;
unsigned Fac[36000], Inv[36000], f[1005], Ans[4];
struct Pnt{
	unsigned X, Y;
	const inline char operator <(const Pnt &x) const{
		return (this->X ^ x.X) ? (this->X < x.X) : (this->Y < x.Y);
	}
}Pn[1005];
unsigned Power(unsigned long long base, unsigned p){
	unsigned long long res(1);
	while(p){
		if(p & 1) res = (res * base) % MOD[Pr];
		base = (base * base) % MOD[Pr];
		p >>= 1;
	}
	return res;
}
void Prework(){
	Fac[0]=1;
	for(int i=1;i < MOD[Pr];++i) Fac[i] = (Fac[i-1] * i) % MOD[Pr];
	Inv[MOD[Pr] - 1] = Power(Fac[MOD[Pr] - 1], MOD[Pr] - 2);
	for (register unsigned i(MOD[Pr] - 2); i < 0x3f3f3f3f; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % MOD[Pr];
	return;
}
unsigned Lucas (unsigned x, unsigned y) {
	register unsigned TmpL(1);
	if(!(x | y)) return 1;
	if(x % MOD[Pr] < y % MOD[Pr]) return 0;
	return Lucas(x / MOD[Pr], y / MOD[Pr]) * C(x % MOD[Pr], y % MOD[Pr]) % MOD[Pr];
}
unsigned Pa(unsigned x, unsigned y, unsigned x2, unsigned y2) {
	if((x > y) || (x2 > y2)) return 0;
	if(x2 <= y) return Lucas(x2 - x + y2 - y, x2 - x);
	register unsigned TmpP(MOD[Pr] + Lucas(x2 - x + y2 - y, x2 - x) - Lucas(x2 - x + y2 - y, y2 - x + 1));
	if(TmpP >= MOD[Pr]) TmpP -= MOD[Pr];
	return TmpP;
}
unsigned Sol() {
	Prework();
	for (register unsigned i(1); i <= k; ++i) {
		f[i] = Pa(0, 0, Pn[i].X, Pn[i].Y);
		for (register unsigned j(1); j < i; ++j) {
			if(Pn[i].Y >= Pn[j].Y) {
				f[i] += MOD[Pr] - (f[j] * Pa(Pn[j].X, Pn[j].Y, Pn[i].X, Pn[i].Y) % MOD[Pr]);
				if(f[i] >= MOD[Pr]) f[i] -= MOD[Pr]; 
			}
		}
	}
	return f[k];
}
void Exgcd(int &x, int &y, unsigned a, unsigned b) {
	if(b == 0) {
		x = 1, y = 0;
		return;
	}
	Exgcd(y, x, b, a % b);
	y -= (a / b) * x;
  return;
}
int main(){
	n = RD() - 1, m = RD() - 1, k = RD();
	if(n > m) {printf("1\n"); return 0;}
	for (register unsigned i(1); i <= k; ++i) {
    Pn[i].X = RD(), Pn[i].Y = RD();
    if(Pn[i].X > Pn[i].Y) --i, --k;
  }
  sort(Pn + 1, Pn + k + 1);
	Pn[++k].X = n, Pn[k].Y = m;
	for (Pr = 0; Pr < 4; ++Pr) Ans[Pr] = Sol();
	for (register unsigned i(1); i < 4; ++i) {
		int Tmpa, Tmpb;
    Exgcd(Tmpa, Tmpb, MOD[i], MOD[i - 1]);
    Tmpb = (Tmpb * ((long long)Ans[i] - Ans[i - 1]) % MOD[i]) + MOD[i];
    if(Tmpb >= MOD[i]) Tmpb -= MOD[i];
		MOD[i] *= MOD[i - 1];
		Ans[i] = ((long long)MOD[i - 1] * Tmpb + Ans[i - 1]) % MOD[i];
	}
	Pr = 4;
	printf("%u\n", Power(233, Ans[3]));
	return 0;
}
