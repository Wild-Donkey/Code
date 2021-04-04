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
int t, n, a[200005], Ma, sum[200005];
unsigned long long ans = 0, mo = 998244353;
bool flg;
char ch;
string s;
inline int IN() {
  char ich = getchar();
  int intmp = 0, insign = 1;
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
unsigned long long c2 (int x) {
	unsigned long long tmp = x - 1;
	tmp *= x;
	tmp /= 2;
	return tmp % mo;
}
unsigned long long c3 (int x) {
	unsigned long long tmp = x - 2;
	tmp *= x - 1;
	tmp *= x;
	tmp /= 6;
	return tmp % mo;
}
int main() {
  // freopen(".in","r",stdin); 
  // freopen(".out","w",stdout);
  n = IN();
  memset(a, 0, sizeof(a));
  for (register int i = 1; i <= n; ++i){
  	t = IN();
  	Ma = max(Ma, t);
  	a[t]++;
	}
	for (register int i = 1; i <= Ma; ++i) {
		sum[i] = sum[i - 1] + a[i];
		if(a[i] >= 3) {
			ans += c3(a[i]);
		}
	}
	ans %= mo;
	for (register int i = 1; i <= Ma; ++i) {
		ans += (sum[min(Ma, i * 2 - 1)] - a[i]) * c2(a[i]);
	}
	ans %= mo;
	cout << ans;
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

