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
	printf("%d\n", n = rand() % 5000 + 5001);
	for (register int i = 1; i <= n; i++) {
		printf("%d ", rand() % 50000 + 50001);
	}
	printf("\n%d\n", m = rand() % 500000 + 1000001);
	int A, B;
	for(register int i = 1; i <= m; i++) {
		A = rand() % n + 1;
		B = rand() % n + 1;
		if(B - A < 2){
			i--;
		}
		else{
			printf("%d %d\n", A, B);
		}
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}

