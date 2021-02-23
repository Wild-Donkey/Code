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
int n, m, a[105], b[105], c[105], f[205][205], fa[205][205][105], he[205][205] = {0};
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
	a[0] = IN();
	b[0] = IN();
	n = IN();
	for (register int i = 1; i <= n; ++i) {
    	a[i] = IN();
    	b[i] = IN();
    	c[i] = IN();
	}
	for (register int k(1); k <= n; ++k) {
		for (register int i(a[0]); i >= a[k]; --i) {
			for (register int j(b[0]); j >= b[k]; --j) {
				int dela(i - a[k]), delb(j - b[k]);
				if(f[dela][delb] + c[k] > f[i][j]){
					f[i][j] = f[dela][delb] + c[k];
					he[i][j] = he[dela][delb] + 1;
					for (register int h(1); h <= he[dela][delb]; ++h) {
						fa[i][j][h] = fa[dela][delb][h];
					}
					fa[i][j][he[i][j]] = k;
				}
			}
		}
	}
	printf("%d\n", f[a[0]][b[0]]);
	for (int h(1); h <= he[a[0]][b[0]]; ++h) {
		printf("%d ", fa[a[0]][b[0]][h]);
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
