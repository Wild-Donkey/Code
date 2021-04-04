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
int Tmp[2000005], t, n, a[1000005][2], b[1000005][2], adr[2000005], adre[2000005], adrto[2000005], dm[2000005], dmto[2000005];
long long ans = 0;
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
void turn (int x) {
	int tmp = a[0][x];
	a[0][x] = a[1][x + 1];
	a[1][x + 1] = tmp;
	tmp = a[1][x];
	a[1][x] = a[0][x + 1];
	return;
}
void Merge(int l, int r) {
	if(l == r) {
		return;
	}
	int m = (l + r) >> 1, i = l, j = m + 1, k = l;
	Merge(l, m);
	Merge(m + 1, r);
	while(i <= m && j <= r) {
		if(adr[i] <= adr[j]) {
			Tmp[k++]=adr[i++];
		}
		else {
			Tmp[k++]=adr[j++];
			ans+=m-i+1;
		}
	}
	while(i <= m) {
		Tmp[k++]=adr[i++];
	}
	while(j<=r) {
		Tmp[k++]=adr[j++];
	}
	for(int b=l; b<=r; b++) {
		adr[b]=Tmp[b];
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = IN();
  for (register int i(1); i <= n; ++i) {
  	a[0][i] = IN();
  	adre[a[0][i]] = i;
  }
  for (register int i(1); i <= n; ++i) {
  	a[1][i] = IN();
  	adre[a[1][i]] = i + n;
  	dm[a[1][i]] = a[0][i];
  	dm[a[0][i]] = a[1][i];
  }
  for (register int i(1); i <= n; ++i) {
  	b[0][i] = IN();
  	adrto[b[0][i]] = i;
  }
  for (register int i(1); i <= n; ++i) {
  	b[1][i] = IN();
  	adrto[b[1][i]] = i + n;
  	dmto[b[1][i]] = b[0][i];
  	dmto[b[0][i]] = b[1][i];
  }
  for (register int i(1); i <= n << 1; ++i) {
  	if (adre[i] <= n) {
  		if (adrto[i] <= n) {
  			if ((adre[i] + adrto[i]) % 2) {
  				printf("dldsgay!!1\n");
  				return 0;
  			}
			}
			else {
				if (!((adre[i] + adrto[i] - n) % 2)) {
  				printf("dldsgay!!1\n");
  				return 0;
				}
			}
		}
		else {
  		if (adrto[i] <= n) {
				if (!((adre[i] + adrto[i] - n) % 2)) {
  				printf("dldsgay!!1\n");
  				return 0;
				}
			}
			else {
				if ((adre[i] + adrto[i]) % 2) {
  				printf("dldsgay!!1\n");
  				return 0;
				}
			}
		}
	}
	for (register int i(1); i <= n << 1; ++i) {
		if (dm[i] != dmto[i]) {
  		printf("dldsgay!!1\n");
  		return 0;
		}
	}
	for (register int i(1); i <= n; ++i) {
		adr[i] = (adrto[a[0][i]] - 1) % n + 1;
	}
	Merge(1, n);
	printf("%lld\n", ans);
  //printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
2
1 4
3 2
1 2
3 4
*/
