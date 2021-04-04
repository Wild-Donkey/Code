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
long long n, m, a[1005], ans = 0, cnt = 0;
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
long long Po(long long x, long long y){
	if(y==0) {
		return 1;
	}
	if(y==1) {
		return x%1000000007;
	}
	long long yy=y>>1, tmp=Po(x,yy);
	if(y%2){
		return (((tmp*tmp)%1000000007)*x)%1000000007;
	}
	return (tmp*tmp)%1000000007;
}
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    n = IN();
    m = IN();
    ans=Po(n, m);
    for (register int i = 1; i <= m; i++) {
      a[i] = IN();
  	}
  	int i=a[1];
  	cnt++;
  	while(i!=1){
  		i=a[i];
  		cnt++;
	}
	ans=(ans*cnt)%1000000007;
    printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
1 2

4

2 2
2 1

8
*/

