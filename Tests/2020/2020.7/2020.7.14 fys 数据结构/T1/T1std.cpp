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
int n, m, tr[10005], st[15][10005][2], A, B, two[10005];
bool flg;
double ans;
char ch;
string s;
inline void read(int &x)
{
    int f=1;
    x=0;
    char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-')
            f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    x*=f;
}
inline void ask() {
	read(A);
	read(B);
	ans = tr[B] - tr[A - 1];
	int now = two[B - A + 1], ponow = 1 << now;
	//printf("%d\n", now);
	ans -= min(st[now][A][0], st[now][B - ponow + 1][0]);
	ans -= max(st[now][A][1], st[now][B - ponow + 1][1]);
	//printf("%d %d\n", min(st[now][A][0], st[now][B - ponow + 1][0]), max(st[now][A][1], st[now][B - ponow + 1][1]));
	printf("%.4lf\n", ans/(B - A - 1));
}
int main() {
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	read(n);
	m = 0;
	for (register int i(1); i <= n; ++i) {
		if (i >= 1 << (m + 1)) {
			two[i] = m + 1;
			m++;
		}
		else {
			two[i] = m;
		}
		read(A);
		st[0][i][0] = A;
		st[0][i][1] = A;
		tr[i] = tr[i - 1] + A;//sum
		//printf("%d %d\n", i, tr[i]); 
	}
	for(register int i(2) , tmp(0); i <= n; i = i << 1, ++tmp) {
		int j(1);
		while (j + i <= n + 1) {
			st[tmp + 1][j][0] = min(st[tmp][j][0], st[tmp][j + (i >> 1)][0]);//min
			st[tmp + 1][j][1] = max(st[tmp][j][1], st[tmp][j + (i >> 1)][1]);//max
			//printf("%d %d %d %d %d\n", tmp, i, j, st[tmp][j][0], st[tmp][j][1]);
			++j;
		}
	}
	read(m);
	for (register int i(1); i <= m; ++i) {
		ask();
	}
	return 0;
}
