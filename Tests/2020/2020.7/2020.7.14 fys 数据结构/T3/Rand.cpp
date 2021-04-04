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
int t, n, m, a[10005], ans = 0;
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
	//freopen("t1_2.in","w",stdout);
	srand(time(0));
	printf("%d\n", n = rand() % 10000 + 90000);
	for (register int i = 1; i <= n; i++) {
		printf("%d ", rand() % 50000 + 50000);
	}
	printf("\n%d", m = rand() % 10000 + 90000);
	int Do;
	for(register int i = 1; i <= m; i++) {
		printf("\n%d", Do = rand() % 2);
		switch (Do) {
			case 0 : {
				break;
			}
			case 1 : {
				printf(" %d", rand() % 50000 + 350000);
				n++;
				break;
			}
			case 2 : {
				printf(" %d", rand() % (n - 10000) + 10000);
				break;
			}
		}
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}

