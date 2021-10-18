#include<bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1ll<<30

template<typename _T>
inline void read(_T &x)
{
	x=0;char s=getchar();int f=1;
	while(s<'0'||s>'9') {f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}

int len[23333],n,m;
char a[2333];
char b[2333];

inline int solve(int x,int typ){
	int base = n + m;
	for(int i=1;i <= 63;i ++,base *= 2)
	{
		if(x <= base)
		{
			if(i == 1)
			{
				if(typ == 1){
					if(x <= n) putchar(a[x]);
					else  putchar(b[x-n]);
					
				}
				else{
					if(x <= m)putchar (b[x]);
					else putchar(a[x-m]);
				}
				return x;
			}
			return solve(x -= (base/2),typ ^ 1);
		}
	}	
}

signed  main()
{
  freopen("A.in", "r", stdin);
  freopen("A.ans", "w", stdout);
	int T;
	read(n),read(m),read(T);
	scanf("%s",a + 1);
	scanf("%s",b + 1);
	
	while(T--)
	{
		int x;
		read(x);
		int base = n + m;
		int ans = 0;
		for(int i=1;i <= 63;i ++,base *= 2)
		{
			if(x <= base)
			{
				if(i == 1){
					if(x <= n)putchar(a[x]);
					else putchar(b[x-n]);
					break;
				}
				else {
					ans = solve(x -= (base/2),0);
					break;
				}
			}
		}
		puts("");
//		printf("%lld\n",ans);
	}
 }
/*
5 5 1
White Space
20

*/


