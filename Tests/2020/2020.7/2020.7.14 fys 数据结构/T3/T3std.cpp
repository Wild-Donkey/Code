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
int t, n, m, a[400005], ans = 0, cnt = 0, cnt1 = 0, Dui[400005][2], Do, Num[400005]/*下标为i的元素在树中位置为Num[i]*/;
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
void Add (int x) {
	//printf("Add %d\n", x); 
	cnt++;
	cnt1++;
	Num[cnt] = cnt;
	Dui[cnt][0] = x;
	Dui[cnt][1] = cnt1;
	int now = cnt;
	while (Dui[now][0] > Dui[now >> 1][0]) {
		swap(Dui[now][0], Dui[now >> 1][0]);
		swap(Dui[now][1], Dui[now >> 1][1]);
		Num[Dui[now][1]] = now;
		Num[Dui[now >> 1][1]] = now >> 1;
		now = now >> 1;
	}
	//printf("Added %d %d\n", cnt, Num[cnt]); 
	return;
}
void Del(int x) {
	if(Num[x] == 0) {
		return;
	}
	int now = Num[x];
	Num[x] = 0; 
	//printf("Del %d %d\n", x, now); 
	Dui[now][0] = Dui[cnt][0];//权值 
	Dui[now][1] = Dui[cnt][1];//下标 
	cnt--;
	while (Dui[now][0] < max(Dui[now << 1][0], Dui[(now << 1) + 1][0])) {//比其中一个儿子小 
		if(Dui[now << 1][0] <= Dui[(now << 1) + 1][0]){
			//printf("Gori %d %d\n",now, (now << 1) + 1); 
			swap(Dui[now][0], Dui[(now << 1) + 1][0]);
			swap(Dui[now][1], Dui[(now << 1) + 1][1]);
			Num[Dui[now][1]] = now;
			Num[Dui[(now << 1) + 1][1]] = (now << 1) + 1;
			now = (now << 1) + 1;
		}
		else {
			//printf("Gole %d %d\n",now, now << 1); 
			swap(Dui[now][0], Dui[now << 1][0]);
			swap(Dui[now][1], Dui[now << 1][1]);
			Num[Dui[now][1]] = now;
			Num[Dui[now << 1][1]] = now << 1;
			now = now << 1;
		}
	}
	while (Dui[now][0] > Dui[now >> 1][0]) {
		swap(Dui[now][0], Dui[now >> 1][0]);
		swap(Dui[now][1], Dui[now >> 1][1]);
		Num[Dui[now][1]] = now;
		Num[Dui[now >> 1][1]] = now >> 1;
		now = now >> 1;
	}
	//printf("Deled %d %d\n", cnt, Dui[now][0]); 
	return;
}
int main() {
	//freopen("t3_25.in","r",stdin);
	//freopen("t3_25.out","w",stdout);
	n = IN();
	memset(Dui, 0, sizeof(Dui));
	Dui[0][0] = 0x3f3f3f3f;
	for (register int i = 1; i <= n; i++) {
		Add(IN());
	}
	m = IN();
	for (register int i = 1; i <= m; i++) {
		Do = IN();
		switch (Do) {
			case 0 : {
				if(cnt == 0){
					printf("%d\n",-0x3f3f3f3f); 
				}
				else{ 
					printf("%d\n", Dui[1][0]);
				}
				break;
			}
			case 1 : {
				Add(IN());
				break;
			}
			case 2 : {
				Del(IN());
				break;
			}
		}
	}
	return 0;
}

