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
int n, m, ans = 0, now = 0;
bool flg;
char ch;
string s;
priority_queue <int> q;
struct BUDing {
	int T1, T2;
}B[1000005];
bool cmp (BUDing x, BUDing y) {
 	return x.T2 < y.T2;
};
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
  for (register int i(1); i <= n; ++i) {
    B[i].T1 = In();
    B[i].T2 = In();
  }
  sort(B + 1, B + n + 1, cmp);
  for (register int i(1); i <= n; ++i) {
  	//printf("%d %d\n", B[i].T1, B[i].T2);
  	if (now + B[i].T1 <= B[i].T2) {
  		now += B[i].T1;
  		q.push(B[i].T1);
  		ans++;
		}
		else {
			if (q.size()) {
				if (q.top() > B[i].T1 && now - q.top() + B[i].T1 <= B[i].T2) {
					now -= q.top();
					now += B[i].T1;
					q.pop();
					q.push(B[i].T1);
				}
			}
		}
	}
	printf("%d\n", ans);
  ///printf();
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

