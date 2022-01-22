#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long Ans(0), Sum[100005];
unsigned n, m, a[100005];
unsigned A, B, C, D;
vector<unsigned> Fit[100005];
inline void DFS(unsigned Dep){
	if(Dep>n){++Ans; return;}
	for(unsigned i(0); i <= 9; ++i){
		a[Dep] = i, Sum[Dep] = Sum[Dep - 1] + a[Dep];
		char Flg(0);
		for(auto j:Fit[Dep])
			if((Sum[Dep] - Sum[j - 1]) % 9){Flg = 1; break;}
		if(Flg) continue;
    DFS(Dep + 1);
	}
}
signed main() {
	n = RD(), m = RD();
	for(int i(1);i <= m;++i) A = RD(), B = RD(), Fit[B].push_back(A);
	DFS(1);
	printf("%llu\n", Ans);
	return 0;
}
