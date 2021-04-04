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
int n, T;
bool flg;
char ch;
string s;
struct Obj {
	long long Powlow, Pow, Mindlow, Mind;
	bool vsd;
}O[100005];
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
bool Cmp (Obj x, Obj y) {
	if (x.Powlow == y.Powlow) {
		return x.Mindlow <= y.Mindlow;
	}
	return x.Powlow < y.Powlow;
}
void DFS (int dep, int npo, int nmi, int spo, int smi) {
	if (dep == n) {
		if (O[0].Powlow > spo) {
			O[0].Powlow = spo;
			O[0].Mindlow = smi;
			return;
		}
		if (O[0].Powlow == spo) {
			if (O[0].Mindlow > smi) {
				O[0].Mindlow = smi;
				return;
			}
		}
		return;
	}
	for (register int i(1); i <= n; ++i) {
		if (!O[i].vsd) {
			O[i].vsd = 1;
			long long tmp1(0), tmp2(0);
			if (npo < O[i].Powlow) {
				tmp1 = O[i].Powlow - npo;
			}
			if (nmi < O[i].Mindlow) {
				tmp2 = O[i].Mindlow - nmi;
			}
			DFS(dep + 1, npo + O[i].Pow + tmp1, nmi + O[i].Mind + tmp2, spo + tmp1, smi + tmp2);
			O[i].vsd = 0;
		}
	}
	return; 
}
bool Checkpo (int x) {
	int now = x;
	for (register int i(1); i <= n; ++i) {
		if (now < O[i].Powlow) {
			return 0;
		}
		now += O[i].Pow;
	}
	return 1;
}
bool Checkmi (int x) {
	int nowm = x, nowp = O[0].Powlow;
	int cnt(1), zcnt(0);
	while (cnt) {
		//printf("%d %d\n", cnt, zcnt);
		cnt = 0;
		for (register int i(1); i <= n; ++i) {
			if (O[i].vsd ^ O[0].vsd) {
				continue;
			}
			if (O[i].Powlow <= nowp && O[i].Mindlow <= nowm) {
				cnt++;
				O[i].vsd = !O[i].vsd;
				nowp += O[i].Pow;
				nowm += O[i].Mind;
			}
		}
		zcnt += cnt;
	}
	O[0].vsd = !O[0].vsd;
	if (zcnt == n) {
		//printf("%d Yes!\n", x);
		return 1;
	}
	for (register int i(0); i <= n; ++i) {
		O[i].vsd = 0;
	}
	//printf("%d No!\n", x);
	return 0;
} 
int main() {
  freopen("forever.in","r",stdin);
  freopen("forever.out","w",stdout);
  T = In();
	n = In();
	memset (O, 0, sizeof(O));
  for (register int i(1); i <= n; ++i) {
    O[i].Powlow = In();
    O[i].Mindlow = In();
    O[i].Pow = In();
    O[i].Mind = In();
  }
  if (T == 1) {//无需求解 
		printf("0 0\n");
		return 0;
	}
	if (T == 2) {//直接输出 
		printf("%lld %lld\n", O[1].Powlow, O[1].Mindlow);
		return 0;
	}
	if (T == 3 || T == 4 || T == 9 || T == 5 || T == 6) {//DFS 
		O[0].Powlow = 0x3f3f3f3f3f3f;
		O[0].Mindlow = 0x3f3f3f3f3f3f;
		DFS(0, 0, 0, 0, 0);
		printf("%lld %lld\n", O[0].Powlow, O[0].Mindlow);
		return 0;
	}
  sort (O + 1, O + n + 1, Cmp);	
  if (T == 7 || T == 8) {//贪心 
		for (register int i(1); i <= n; ++i) {
			if (O[0].Pow < O[i].Powlow) {
				O[0].Powlow += O[i].Powlow - O[0].Pow;//差多少, 一开始加多少 
				O[0].Pow += O[i].Powlow - O[0].Pow;
			}
			O[0].Pow += O[i].Pow;
		}
  	printf("%lld 0\n", O[0].Powlow);
  	return 0;
	}
	/*for (register int i(1); i <= n; ++i) {
		printf("%lld %lld %lld\n", i, O[i].Powlow, O[i].Mindlow);
	}*/
  int l(0), r(1000000000), m;	//二分答案 
  while (l < r) {
  	m = (l + r) >> 1;
  	if (Checkpo(m)) {
  		r = m;
		}
		else {
			l = m + 1;
		}
	}
	O[0].Powlow = l;
	l = 0;
	r = 1000000000;
	Checkmi(2);
  while (l < r) {
  	//printf("%d %d\n", l, r);
  	m = (l + r) >> 1;
  	if (Checkmi(m)) {
  		r = m;
		}
		else {
			l = m + 1;
		}
	}
	O[0].Mindlow = l;
	printf("%d %d\n", O[0].Powlow, O[0].Mindlow);
  return 0;
}
