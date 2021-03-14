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
string a[15][15], tmp;
int n, m, ans = 0, b[15], A, B;
bool flg;
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
  for (register int i(0); i < n; ++i) {
    for (register int j(0); j < n; ++j) {
    	cin >> a[i][j];
		}
  }
  for (register int i(1); i < n; ++i) {
  	if (a[i][i] == a[0][i]) {
  		b[0] = i;
  		break;
		}
	}
	if (b[0] == 0) {
		printf("ERROR!\n");
		return 0;
	}
	for (register int i(1); i < n; ++i) {
		for (register int j(1); j < n; ++j) {
			if (a[i][j].length() == 2) {
				ch = a[i][j][0];
				break;
			}
		}
	}
	for (register int i(1); i < n; ++i) {
		if (a[0][i][0] == ch) {
			b[1] = i;
			break;
		}
	}
	if (b[1] == 0) {
		printf("ERROR!\n");
		return 0;
	}
	for (register int i(1); i <= (n - 3); ++i) {
		tmp = a[b[i]][b[1]];
		for (register int j(1);	j < n; ++j) {
			if (a[0][j] == tmp) {
				b[i + 1] = j;
				break;
			}
		}
		if (b[i + 1] == 0) {
			printf("ERROR!\n");
			return 0;
		}
	}
	for (register int i(1); i < n; ++i) {//Cheak
		for (register int j(0); j <= (n - 2); ++j) {
			if (a[0][b[j]] == a[0][i]) {
				A = j;
			}
		}
		for (register int j(1); j < n; ++j) {
			for (register int k(0); k <= (n - 2); ++k) {
				if (a[0][b[k]] == a[0][j]) {
					B = k;
				}
			}
			if (a[i][j].length() == 1) {
				if (a[i][j] != a[0][b[A + B]]) {
					printf("ERROR!\n");
					return 0;
				}
			}
			else {
				if (a[i][j][1] != a[0][b[A + B - (n - 1)]][0]) {
					printf("ERROR!\n");
					return 0;
				}
			}
		}
	}
	for (register int i(1); i < n; ++i) {
		for (register int j(0); j <= (n - 2); ++j) {
			if (a[0][b[j]] == a[0][i]) {
				cout << a[0][i] << "=" << j << " ";
			}
		}
	}
	printf("\n%d\n", n - 1);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

