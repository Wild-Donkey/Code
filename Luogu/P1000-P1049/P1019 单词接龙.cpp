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
int n, m, a[105][105], ans = 0, len1, len2, vsd[105] = {0};
bool flg;
char ch;
string s[105];
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
bool Check (int x, int y, int len) {
	for (register int i(0); i < len; ++i) {
		if (s[x][len1 - len + i] != s[y][i]) {
			//printf("%d %d %d\n", x, y, i);
			return 0;
		}
	}
	return 1;
}
void DFS (int val, int now) {
	//printf("%d	%d\n", val, now);
	if (val < 0) {
		return;
	}
	ans = max(val, ans);
	for (register int i(1); i <= n; ++i) {
		if (vsd[i] < 2) {
			vsd[i]++;
			DFS(val + s[i].length() - a[now][i], i);
			vsd[i]--;
		}
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  for (register int i(1); i <= n; ++i) {
    cin >> s[i];
  }
  cin >> ch;
  for (register int i(1); i <= n; ++i) {//枚举前面的单词
		len1 = s[i].length(); 
  	for (register int j(1); j <= n; ++j) {//枚举后面的单词
  		a[i][j] = 0x3f3f3f3f;
  		len2 = s[j].length();
  		for (register int k(1); k <= min(len1, len2) - 1; ++k) {//枚举重合的长度 
  			if (Check(i, j, k)) {
  				a[i][j] = k;
  				break;
				}
			}
		}
	}
	for (register int i(1); i <= n; ++i) {
		if (ch == s[i][0]) {
			a[0][i] = 1;
		}
		else {
			a[0][i] = 0x3f3f3f3f;
		}
	}
	/*for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
			printf("%d	", a[i][j]);
		}
		printf("\n");
	}*/
	DFS (1, 0);
	printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

