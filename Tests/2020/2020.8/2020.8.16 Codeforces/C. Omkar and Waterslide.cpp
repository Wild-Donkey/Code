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
int n, t;
long long A, Lst, Pls;
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
  t = In();
  for (register int T(1); T <= t; ++T) {
  	n = In();
  	Lst = Pls = 0;
  	for (register int i(1); i <= n; ++i) {
  		A = In();
  		if(A + Pls < Lst) {
  			Pls += Lst - A - Pls;
			}
			Lst = A + Pls;
  	}
		printf("%lld\n", Pls);
	}
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}

