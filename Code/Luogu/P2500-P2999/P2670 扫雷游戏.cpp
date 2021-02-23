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
int m, n, a[105][105] = {0}, ans = 0;
bool flg[105][105] = {0};
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
  m = In(); 
  for (register int i(1); i <= n; ++i) {
    cin >> s;
    for (register int j(0); j < m; ++j) {
    	if (s[j] == '*') {
    		flg[i][j + 1] = 1;
    		a[i + 1][j]++;
    		a[i + 1][j + 1]++;
    		a[i + 1][j + 2]++;
    		a[i][j]++;
    		a[i][j + 2]++;
    		a[i - 1][j]++;
    		a[i - 1][j + 1]++;
    		a[i - 1][j + 2]++;
			}
		}
  }
  for (register int i(1); i <= n; ++i) {
  	for (register int j(1); j <= m; ++j) {
  		if (flg[i][j]) {
  			printf("*");
			}
			else {
				printf("%d", a[i][j]);
			}
		}
		printf("\n");
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

