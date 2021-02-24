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
int t, n, a[100005], ans = 0;
long long f[100005];
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
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = IN();
    for (register int i = 1; i <= n; i++) {
    	a[i] = IN();
    }
    if(n<=2){
    	printf("%d\n",max(a[1],a[2]));
    	return 0;
	}
    sort(a+1,a+n+1);
	f[1] = a[1];
	f[2] = a[2];
	for (register int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + a[i] + a[1];//一次运最大的 
		f[i] = min(f[i], f[i-2] + (a[2]<<1) + a[i] + a[1]);//一次运最大和次大 
	}
    printf("%lld\n", f[n]);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

