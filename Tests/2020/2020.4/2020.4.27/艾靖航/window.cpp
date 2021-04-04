#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
#include<set>
#include<map>
#define LL long long
#define rg register
#define us unsigned
#define eps 1e-6
#define INF 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
#define tmid ((tr[k].l+tr[k].r)>>1)
#define nmid ((l+r)>>1)
#define Thispoint tr[k].l==tr[k].r
#define pushup tr[k].wei=tr[ls].wei+tr[rs].wei
#define pub push_back
#define lth length
using namespace std;
inline void Read(int &x){
	int f=1;
	char c=getchar();
	x=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
#define N 1000010
int n,k,a[N];
deque<int>qmx,qmn;
int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	Read(n),Read(k);
	for(rg int i=1;i<=n;i++)Read(a[i]);
	for(rg int i=1;i<=n;i++){
		while(!qmn.empty()&&a[qmn.back()]>a[i])qmn.pop_back();
		qmn.push_back(i);
		if(i>=k){
			while(!qmn.empty()&&qmn.front()<=i-k)qmn.pop_front();
			cout<<a[qmn.front()]<<" ";
		}
	}
	puts("");
	for(rg int i=1;i<=n;i++){
		while(!qmx.empty()&&a[qmx.back()]<a[i])qmx.pop_back();
		qmx.push_back(i);
		if(i>=k){
			while(!qmx.empty()&&qmx.front()<=i-k)qmx.pop_front();
			cout<<a[qmx.front()]<<" ";
		}
	}
	puts("");
	fclose(stdin),fclose(stdout);
	return 0;
}
