#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
unsigned n;
unsigned long long Ans(0), Tmp(0);
priority_queue<unsigned long long,vector<unsigned long long>, greater<unsigned long long> >q;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
int main() {
	n = RD();
	for (unsigned i(1); i <= n; ++i) q.push((unsigned long long)RD());
	while (q.size() ^ 1) {
		Tmp = q.top(), q.pop();
		Tmp += q.top(), q.pop();
		q.push(Tmp);
		Ans += Tmp;
	}
	printf("%llu\n", Ans);
	return 0;
}
