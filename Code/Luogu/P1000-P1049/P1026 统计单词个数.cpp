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
int k, n, m, ans = 0;
bool flg, vsd[205];
string b[10];//s是t的前缀, 则只保留s, 匹配时先考虑长的 
char a[205];
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
	k = In();
  for (register int i(0); i < n; ++i) {
    for (register int j(1); j <= 20; ++j) {
    	cin >> a[i * 20 + j];
		}
  }
  m = In();
  for (register int i(1); i <= m; ++i) {
  	cin >> b[m];
	} 
	for (register int i(1); i < m; ++i) {//从长到短 
		for (register int j(m); j > i; --j) {
			if(b[j].length() > b[j - 1].length()) {
				swap (b[j], b[j - 1]);
			}
		}
	}
	for (register int i(m); i > 1; --i) {//i为前缀 
		for (register int j(1); j < i; ++j) {
			flg = 1;
			for (register int k(0); k < b[i].length()) {
				if (b[i][k] != b[j][k]) {
					flg = 0;
					break;
				}
			}
			if (flg) {
				--m;
				for (register int k(j); k <= m; ++k) {
					b[k] = b[k + 1];
				}
				--j;
				--i;
			}
		}
	}
	for (register int l(1); l <= m; ++l) {
		for (register int r(l); r <= m; ++r) {
			
		}
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

