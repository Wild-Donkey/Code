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
int t, n, a, ans = 0, sum = 0, maxx = -0x3f3f3f3f;
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
    	a = IN();
    	maxx = max(maxx, a);
    	sum += a;
    	if(sum < 0) {
    		sum = 0;
		}
		if(sum > ans) {
			ans = sum;
		}
    }
    printf("%d\n", ans==0 ? maxx : ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

