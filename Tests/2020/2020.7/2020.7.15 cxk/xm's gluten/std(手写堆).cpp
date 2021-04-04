#include<bits/stdc++.h>
const int S=1<<20;
char frd[S],*ihead=frd+S;
const char *itail=ihead;

inline char nxtChar()
{
	if(ihead==itail)
	    fread(frd,1,S,stdin),ihead=frd;
	return *ihead++;
}

template<class T>
inline void read(T&res)
{
	char ch;
	while(ch=nxtChar(),! isdigit(ch));
	res=ch^48;
	while(ch=nxtChar(),isdigit(ch))
	    res=res*10+ch-48;
}

typedef long long ll;
const int N=1e6+5;
int n;
ll m,tot_h,tot_v,ans;
template<class T>
inline void CkMax(T & x,T y){if(x<y) x=y;}

struct point
{
	int v,h;
	point(){}
	point(int V,int H):
	    v(V),h(H){}
	
	inline bool operator<(const point & a)const
	{
		return v<a.v;
	}
};

struct Heap
{
	point g[N];
	int len;
	
	inline void Push(const point & res)
	{
		int now=++len,nxt=len>>1;
		while(nxt)
		{
			if(res<g[nxt])
			    g[now]=g[nxt],now=nxt,nxt>>=1;
			else break;
		}
		g[now]=res;
	}
	inline void Pop()
	{
		int now=1,nxt=2;
		point res=g[len--];
		while(nxt<=len)
		{
			if(nxt<len&&g[nxt|1]<g[nxt]) nxt|= 1;
			if(g[nxt]<res)
			    g[now]=g[nxt],now=nxt,nxt<<=1;
			else break;
		}
		g[now]=res;
	}
}Q;

int main()
{
//	freopen("gluten10.in","r",stdin);
//	freopen("gluten10.out","w",stdout); 
	read(n);read(m);++m;
	ll res=0;
	for(int i=1,h,v;i<=n;++i)
	{
		read(h);read(v);
		--m;
		res+=v;
		if(!m) break;
		if(h>1)
		{
			point tmp=point(v,h-1);
			Q.Push(tmp);
			tot_h+=tmp.h;
			tot_v+=1ll*tmp.h*tmp.v;
			while(Q.len&&tot_h-Q.g[1].h>=m)
			{
				tot_h-=Q.g[1].h;
				tot_v-=1ll*Q.g[1].h*Q.g[1].v;
				Q.Pop();
			}
		}
	    CkMax(ans,tot_h>=m?
	        res+tot_v-1ll*Q.g[1].h*Q.g[1].v+1ll*(m-tot_h+Q.g[1].h)*Q.g[1].v:res+tot_v);
	}
	std::cout<<ans<<std::endl;
	return 0;
}
