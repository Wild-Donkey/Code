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
#include <bitset>
using namespace std;
int t, n, m, ed;
long long a[100050], b[100050], biger[100050], smaller[100050], ans = 0, tr[100050];
char ch;
string s;
struct Li {
	long long val;
};
int Lowb (int x) {
	return x & (-x);
}
inline long long IN() {
	char ich = getchar();
	long long intmp = 0;
	while (((ich < '0') || (ich > '9'))) {
		ich = getchar();
	}
	while ((ich <= '9') && (ich >= '0')) {
		intmp *= 10;
		intmp += ich - '0';
		ich = getchar();
	}
	return intmp;
}
struct Node {
	int L,R;
	long long SU;
	Node *ls,*rs;
} N[100100],*cntn=N;
void Add (int x) {//将第y个元素加1
	//printf("Add %d\n", x); 
	int now = x;
	while (now <= n) {
		tr[now] ++;
		//printf("Add tr[%d]=%lld\n", now, tr[now]); 
		now += Lowb(now); 
	}
	return;
}
int Find (int x) {
	if(x == 0) {
		return 0;
	}
	//printf("Find %d\n", x); 
	int now = x, ansf = 0; 
	while(now) {
		ansf += tr[now];
		//printf("Find Left tr[%d]%lld ans%lld\n",now, tr[now], ansf); 
		now -= Lowb(now);
	}
	return ansf;
}
int main() {
	n = IN();
	for(register int i=1; i<=n; i++) {
		a[i] = IN();
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	ed = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + ed + 1, a[i]) - b;//离散化
		//printf("%d %d\n", i, a[i]); 
	}
	memset(tr, 0, sizeof(tr));
	smaller[0] = 0;
	smaller[1] = 0;
	Add(a[1]);
	for (int i = 2; i <= n; i++) {
		Add(a[i]);
		smaller[i] = Find(a[i] - 1);
		//printf("%d	%lld\n", i, smaller[i]); 
	}
	memset(tr, 0, sizeof(tr));
	biger[n] = 0;
	Add(a[n]);
	for (int i = n - 1; i >= 1; i--) {
		Add(a[i]);
		//printf("%d\n", ed);
		biger[i] = n - i + 1 - Find(a[i]);
		//printf("%d	%lld\n", i, biger[i]); 
	}
	for (int i = 2; i < n; i++) {
		ans += biger[i] * smaller[i];
	}
	printf("%lld\n",ans); 
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
