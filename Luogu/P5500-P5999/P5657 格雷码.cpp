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
unsigned long long n, k, a[10005], ans = 0;
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
void prt (unsigned long long x, unsigned long long y) {
//	printf("now %d %d\n", x, y);
	if(x == 1) {
		printf("%lld\n", y % 2);
		return;
	}
	unsigned long long tmp = 1;
	tmp = tmp << (x - 1);
	if (y >= tmp) {
		printf("1");
		prt(x - 1, (tmp << 1) - y - 1);
	}
	else {
		printf("0");
		prt(x - 1, y);
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  cin >> n >> k;
  prt(n, k);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

