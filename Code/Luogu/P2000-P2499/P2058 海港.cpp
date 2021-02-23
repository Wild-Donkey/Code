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
int ans, m, n, Ti[300005], na[300005], le = 1, cnt = 0, ti, now[300005];
char ch;
string s;
inline int In() {
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
  n = In();
  ans = 0;
  memset(now, 0, sizeof(now));
  for (register int i(1); i <= n; ++i) {
    ti = In();
		m = In();
    for (register int j(1); j <= m; ++j) {
    	na[++cnt] = In();
    	if (na[cnt] == na[cnt - 1]) {
    		if(j > 1) {
    			--cnt;
    			continue;
				}
			}
    	Ti[cnt] = ti;
    	if(now[na[cnt]] == 0) {
    		ans++;
			}
    	now[na[cnt]]++;
		}
		while (Ti[le] + 86400 <= Ti[cnt]) {
			now[na[le]]--;
			if(now[na[le++]] <= 0) {
				ans--;
			}
		}
		printf("%d\n", ans); 
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

