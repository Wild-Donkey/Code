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
int n, m, a, ans = 0, k, on[105][3], fib[105];
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
  on[1][0] = a = In();
	n = In();
  m = In();
	k = In();
  fib[0] = 0;
  fib[1] = 1;
  for (register int i(2); i <= n; ++i) {
  	fib[i] = fib[i - 1] + fib[i - 2];
  	//printf("%d %d\n", i, fib[i]);
	}
	for (register int i(0); i <= n; ++i) {
		on[i + 2][1] = fib[i];//num of on[1]
		on[i + 1][2] = fib[i];//num of on[2]
	}
	on[2][0] = (m - (on[n - 1][1] + 1) * on[1][0]) / (on[n - 1][2] - 1);//第二次上车人数 
  printf("%d\n", (on[k][1] + 1) * on[1][0] + (on[k][2] - 1) * on[2][0]);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
on[i] on[1] on[2] sum[i]
3			1			1			2			0		2 * on[1]
4			1			2			2			1		2 * on[1] + on[2]
5			2			3			3			2		2 * on[1] + on[2] + on[3]
6			3			5			4			4
7			5			8			6			7
8			8			13		9			12
9			13		21		
10		21		34
*/
