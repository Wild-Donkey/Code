#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define INF 1ll<<30
#define ill unsigned long long 

template<typename _T>
inline void read(_T &x)
{
	x=0;char s=getchar();int f=1;
	while(s<'0'||s>'9') {f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}


const int np = 2e6 + 5;

const ill base = 131;
int siz[np << 1],ch[2][np << 1],pri[np << 1];
int val[np << 1],cnt,rot;//\xb5\xda?\xcc\xe2\xbf?\xe4\xcf\xde\xd6?\xe0\xc9\xd9 
ill sum[np << 1],p_[np << 1];
//ill sum2[np],p2[np];

//#define ls(x) (ch[0][x])
//#define rs(x) (ch[1][x])
//
//inline int New(int a)
//{
//	++cnt;
//	siz[cnt] = 1,pri[cnt] = rand(),val[cnt] = sum[cnt] = a;
//	ls(cnt) = rs(cnt) = 0;
//	return cnt;
//}
//
//inline void pushup(int x)
//{
//	siz[x] = siz[ls(x)] + siz[rs(x)] + 1;
//	sum[x] = sum[rs(x)] + val[x] * p_[siz[rs(x)]] + sum[ls(x)] * p_[siz[rs(x)] + 1];// + p_[siz[ls(x)]] * val[x] + p_[siz[(ls(x))] + 1] * sum[rs(x)];
////	sum2[x] =  (((sum2[rs(x)] + ((val[x] * p2[siz[rs(x)]]) % mod)) % mod)+ ((sum2[ls(x)] *  p2[siz[rs(x)] + 1]) % mod)) % mod;
//}
//
//inline void split(int now,int k,int &x,int &y)
//{
//	if(!now) return (void)(x = y =0 );
//	if(siz[ls(now)] + 1 <= k)
//	{
//		x = now;
//		split(rs(now),k - siz[ls(now)]  -1,rs(x),y);
//		pushup(x);
//	}
//	else
//	{
//		y = now;
//		split(ls(now),k,x,ls(y));
//		pushup(y);
//	}
//}
//
//inline int Merge(int x,int y)
//{
//	if(!x || !y) return x | y;
//	if(pri[x] < pri[y])
//	{
//		rs(x) = Merge(rs(x),y);
//		pushup(x);
//		return x;
//	}
//	else
//	{
//		ls(y) = Merge(x,ls(y));
//		pushup(y);
//		return y;
//	}
//}
//
//inline bool check(int l,ill &t)
//{
//	int x,y;
//	split(rot,l,x,y);
////	split(x,l-1,x,z);
//	if(sum[x] == sum[y]) 
//	{
//		t = sum[x];
//		rot = Merge(x,y);
//		return 1;
//	}
//	else
//	{
//		rot = Merge(x,y);
//		return 0;
//	}
////	ill Ans = sum[z];
////	return Ans;
//}

//inline ill Hash2(int l,int r)
//{
//	int x,y,z;
//	split(rot,r,x,y);
//	split(x,l-1,x,z);
//	ill Ans = sum2[z];
//	rot = Merge(Merge(x,z),y);
//	return Ans;	
//}
//inline void insert(int p,int a)
//{
//	int x,y;
//	split(rot,p,x,y);
//	rot = Merge(Merge(x,New(a)),y);
//}
//inline void del(int p)
//{
//	int x,y,z;
//	split(rot,p,x,y);
//	split(x,p-1,x,z);
//	rot = Merge(x,y);
//}
//inline void solve(int p,int a)
//{
//	int x,y,z;
//	split(rot,p,x,y);
//	split(x,p-1,x,z);
//	val[z] = a;
//	rot = Merge(Merge(x,z),y);
//}

char c[np];
int sta[np << 1],top;
//ill q[np << 1];
map<ill,bool> mapp;

inline ill Hash(int l,int r)
{
	return sum[r] - sum[l-1] * p_[r-l+1];
}

signed  main()
{
	
//	freopen("data.in","r",stdin);
//	freopen("")
	p_[0] =1;// p2[0] = 1;
	for(int i=1;i<=2e6 + 10;i++) p_[i] = p_[i - 1] * base;//,p2[i] = p2[i - 1] * base2,p2[i] %=mod;
	int len;
	read(len);
	scanf("%s",c + 1);
//	int len = strlen(c + 1);
	for(int i=1;i<=len;i++) sum[i] = sum[i - 1] * base + (c[i]-'a'+1);
	
	if(!(len & 1))
	{
		printf("NOT POSSIBLE\n");
		return 0;
	}
	
//	for(int i=1;i<=len;i++) insert(i-1,c[i]-'a' + 1);
	
	int half = (len - 1)/2;
	
//	cout<<(Hash(4,5) == Hash(2,3));
	
//	int vis = 0;
	ill q(0),p(0);int a = len-half+1;
	for(int i=1;i<=len;i++)
	{
		if(i <= half)
		{
			q = sum[i - 1];
			ill uop = Hash(i + 1,half + 1);
			int len_ = half-(i-1);//pos - (i + 1) + 1;
			q *= p_[len_];
			q +=uop;
//			q *= 
			if(q == Hash(len-half + 1,len)) 
			{
				sta[++top] = i;
				if(!mapp[q] && top > 1)
				{
					printf("NOT UNIQUE\n");
					return 0;
				}
				mapp[q] = 1;
				if(top > 1) top--;				
			}			
		}
		else
		{
			q = Hash(half+1,i-1);
			
			q *= p_[len - i];
//			if(q == Hash(1,half)) cout<<i<<" "<<"!";
			if(i + 1 <= len) q += Hash(i+1,len);
			if(q == Hash(1,half))
			{
				sta[++top] = i;
				if(!mapp[q] && top > 1)
				{
					printf("NOT UNIQUE\n");
					return 0;
				}
				mapp[q] = 1;
				if(top > 1) top--;				
			}
		}
	}
	
	if(top == 0)
	{
		printf("NOT POSSIBLE\n");
		return 0;		
	}
	if(top == 1)
	{
		int num(0);
		for(int i=1;i<=len;i++)
		{
			if(i ==sta[1]) continue;
			num++;
			cout<<c[i];
			if(num == half) return 0;
		}
	}
	
	printf("NOT UNIQUE\n");
 }
