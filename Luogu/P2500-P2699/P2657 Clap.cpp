#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
const int MOD(1000000007);
inline unsigned int RD() {
	register unsigned int rdtp(0);
	register char rdch(getchar());
	while ((rdch > '9') || (rdch < '0')) {
		rdch = getchar();
	}
	while ((rdch <= '9') && (rdch >= '0')) {
		rdtp *= 10;
		rdtp += rdch - '0'; 
		rdch = getchar();
	}
	return rdtp;
}
unsigned int n, a[1005], f[1050][1005][2]/*f[i][j][k]:? j ???????^(k == 0) ?? &(k == 1)????????*/;
unsigned long long Ans(0), Time1;
int main() {
	while(1) {
		system("P2657_Make.exe");
		Time1 = clock();
		system("P2657_Std.exe");
		printf("stdtm %llu\n", clock() - Time1);
		Time1 = clock();
		system("P2657_Windy.exe");
		printf("FYStm %llu\n", clock() - Time1);
		if(system("fc P2657.out std.out")) {
			break;
		}
	}
	return 0; 
}

