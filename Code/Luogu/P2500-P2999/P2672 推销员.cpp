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
using namespace std;
long long t, n, ans = 0, maxExtra[100005];
bool flg;
char ch;
string s;
struct Fml{
	long long tir, adr;
}F[100005],f[100005];
bool cmp (Fml x, Fml y) {
	return x.tir > y.tir;
}
inline long long IN() {
  char ich = getchar();
  long long intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = IN();
    for (register int i = 1; i <= n; i++) {
    	F[i].adr= IN();
    }
    for (register int i = 1; i <= n; i++) {
    	F[i].tir = IN();
	}
	sort(F + 1, F + n + 1, cmp);
    F[0].tir = 0;
    F[0].adr = 0;
    for (register int i = 1; i <= n; i++) {
    	f[i].tir = f[i - 1].tir + F[i].tir;
    	/*if (F[f[i - 1].adr].adr < F[i].adr){
    	   	f[i].adr = i;
		}*/
		f[i].adr = max(f[i - 1].adr, F[i].adr);
    }
    for (register int i = n; i >= 1; i--){
		maxExtra[i] = max(maxExtra[i + 1], (F[i].adr << 1) + F[i].tir);
	}
	for (register int i = 1; i <= n; i++) {
		/*if(F[f[i].adr].adr == F[f[n].adr].adr) {//前i累中包括最远的 
			printf("%d\n", f[i].tir + (F[f[i].adr].adr << 1)找前i大的劳累值, 走其中最长的路);
		}
		else {*/
			printf("%lld\n", max(f[i].tir + (f[i].adr << 1)/*找前i大的劳累值, 走其中最长的路*/, /*(F[f[n].adr].adr << 1) + */f[i-1].tir + maxExtra[i]/*F[f[n].adr].tir*//*最远的加前i - 1劳累的*/));
		//} 
	}
	// fclose(stdin);
	// fclose(stdout);
  return 0;
}

