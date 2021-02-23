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
int t, n, a[105], b[105], f[205][205] = {0}, ans = 0;
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
    a[0] = IN();
    b[0] = IN();
    for (register int i = 1; i <= n; i++) {
    	a[i] = IN();
    	b[i] = IN();
    }
    for (register int k(1); k <= n; k++) {
    	for (register int i(a[0]); i >= a[k]; --i) {
	    	for (register int j(b[0]); j >= b[k]; --j) {
    			f[i][j] = max(f[i][j], f[i - a[k]][j - b[k]] + 1);
			}
		}
	}
	printf("%d\n",f[a[0]][b[0]]); 
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

