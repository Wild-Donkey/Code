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
int A, B, C, D, E, F, m, n, a[10005], ans = 0;
bool flg;
char ch;
int main() {
  // freopen(".in","r",stdin);
  // freopen("t1.in","w",stdout);
  srand(time(0));
	n = rand() % 20 + 81;
	m = rand() % 10000 + 90001;
	printf("%d %d\n", n, m);
  for (register int i(1); i <= m; ++i) {
    A = rand() % n + 1;
    B = rand() % n + 1;	
    C = rand() % n + 1;
    D = A + rand() % (n - A + 1);
    E = B + rand() % (n - B + 1);
    F = C + rand() % (n - C + 1);
    printf("%d %d %d %d %d %d\n", A, B, C, D, E, F);
  }
	// fclose(stdin);
	// fclose(stdout);
  return 0;
}

