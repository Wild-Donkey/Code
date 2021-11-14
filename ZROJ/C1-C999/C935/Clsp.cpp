#include<bits/stdc++.h>

using namespace std;

#define int long long
//#define INF 1ll<<30
#define lowbit(x) (x&(-x))

template<typename _T>
inline void read(_T &x)
{
	x=0;char s=getchar();int f=1;
	while(s<'0'||s>'9') {f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
const int INF = 1e18;

const int np = 1e5 + 5; 

int a[np],b[np],a_[np],b_[np];
int n,m,q;
int opt,vl,lim;

inline int judging(int mid)// 有一堆中位数可太 cao 了 
{
	if(opt == 1)
	{
		int pl = upper_bound(b_ + 1,b_ + 1 + n,mid) - b_;
		pl--;
		int pl_ = upper_bound(b_ + 1,b_ + 1 + n,mid - 1) - b_;
		int num ;
		if(pl >= pl_) num= pl - pl_ + 1;
		else num =0 ;
		int yu = pl_ - 1;
		pl = upper_bound(a_ + 1,a_ + 1 + m,mid - vl) - a_;
		pl--;
		pl_ = upper_bound(a_ + 1,a_ + 1 + m,mid -vl - 1) - a_;
		int num_;
		if(pl >= pl_) num_ = pl - pl_ + 1;
		else num_ = 0;
		yu += pl_ - 1;
		if(yu <= lim && lim < yu + num + num_) return 0;
		if(yu + num + num_ <= lim) return -1;
		if(yu > lim) return 1; 
	}
	else
	{
		int pl = upper_bound(a_ + 1,a_ + 1 + m,mid) - a_;
		pl--;
		int pl_ = upper_bound(a_ + 1,a_ + 1 + m,mid - 1) - a_;
		int num ;
		if(pl >= pl_) num= pl - pl_ + 1;
		else num =0 ;
		int yu = pl_ - 1;
		pl = upper_bound(b_ + 1,b_ + 1 + n,mid - vl) - b_;
		pl--;
		pl_ = upper_bound(b_ + 1,b_ + 1 + n,mid -vl - 1) - b_;
		int num_;
		if(pl >= pl_) num_ = pl - pl_ + 1;
		else num_ = 0;
		yu += pl_ - 1;
		if(yu <= lim && lim < yu + num + num_) return 0;
		if(yu + num + num_ <= lim) return -1;
		if(yu > lim) return 1; 
	}
}

signed  main()
{
	
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
	read(m);
	read(n);
	read(q);
	
	int maxn(0);
	for(int i=1;i<=m;i++) read(a[i]),a_[i] = a[i],maxn = max(maxn , a[i]);
	for(int i=1;i<=n;i++) read(b[i]),b_[i] = b[i],maxn = max(maxn , b[i]);
	
	sort(a_ + 1,a_ + 1 + m);
	sort(b_ + 1,b_ + 1 + n);
	
//	int l = 1,r = maxn;
	lim = n + m;
	lim /= 2;
//	m++,a_[m] = INF;
//	cerr<<lim<<'\n';
//	vl = 9;
//	cerr<<judging(9)<<'\n';
	for(int i=1;i<=q;i++)
	{
		read(opt);
		read(vl);
		
		int l = 1,r = maxn + maxn;
		int Ans = 0,flag = 0;
		while(r-l+1 > 2)
		{
			int mid = l + r >>  1;
			int op = judging(mid);
			if(!op) { Ans = mid,flag = 1;break;}
			if(op == -1) l = mid + 1;
			else r = mid - 1;			
		}
		if(flag) 
		{
			cout<<Ans<<'\n';
			continue;
		}
		if(judging(l) == 0) Ans = l;
		if(judging(r) == 0) Ans = r;
		if(!Ans) Ans = l + r >>1;
		
		cout<<Ans<<'\n';
		
	} 
	/* 
	dA zi 你说啥
	第四题？？？
	你怎么数位 dp  
	状态怎么设
	你怎么判断字符串是否匹配
	哦
	
	是
	把5个字符串哈希值放到状态里？？
	然后 dp
	
	但是我数位 dp 已经忘了
	
	太菜了 
	
	对拍吗 T3 
 	*/
 }
/*
3 4 1
1 3 4
2 7 8 9
2 9
*/

