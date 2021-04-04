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
int Do, A, B, C, D, E, m, n, cnt = 0;
bool flg;
char ch;
int main() {
  // freopen(".in","r",stdin);
  // freopen("t2.in","w",stdout);
  srand(time(0));
	n = rand() % 500 + 501;
	m = rand() % 50000 + 50001;
	printf("%d %d\n", n, m);
	for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
			printf ("%d ", rand() % 100001);
		}
		printf("\n");
	}
  for (register int i(1); i <= m; ++i) {
  	Do = rand() % 10001;
  	if (Do == 10000) {
  		printf("2\n");
  		++cnt;
  		continue;
		}
    A = rand() % n + 1;
    B = rand() % n + 1;	
    C = A + rand() % (n - A + 1);
    D = B + rand() % (n - B + 1);
    E = rand() % 100001;
    printf("%d %d %d %d %d %d\n", Do % 2, A, B, C, D, E);
  }
  printf("%d\n", cnt);
	// fclose(stdin);
	// fclose(stdout);
  return 0;
}

