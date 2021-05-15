#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int getint()
{
	char ch;
	while((ch=getchar()) < '!') ;
	int x = ch^'0';
	while((ch=getchar()) > '!') x = (x*10)+(ch^'0');
	return x;
}

int getqr()
{
	char ch;
	while((ch=getchar())!='Q' && ch!='R') ;
	return ch == 'Q';
}

void putint(int x)
{
	if(x/10) putint(x/10);
	putchar((x%10)^'0');
}

struct query
{
	int l;
	int r;
	int t;
	int id;
};

int sqrtn;

query qi[133335];

bool cmp(query a,query b)
{
	if(a.l/sqrtn != b.l/sqrtn) return a.l < b.l;
	if(a.r/sqrtn != b.r/sqrtn) return (a.l/sqrtn)&1 ? a.r < b.r : a.r > b.r;
	return (a.r/sqrtn)&1 ? a.t < b.t : a.t > b.t;
}

int mmp[1000005];

int lsh(int x)
{
	static int lshtop;
	return mmp[x] ? mmp[x] : mmp[x]=++lshtop;
}

int ai[133335];
int pi[133335];
int fi[133335];
int li[133335];

int apn[266670];
int ansi[133335];

void moalgo(int q)
{
	sort(qi+1,qi+1+q,cmp);

	int cl = 1;
	int cr = 0;
	int ct = 0;
	int cans = 0;
	for(int i=1; i<=q; ++i)
	{
		while(cr < qi[i].r)
		{
			++cr;
			if(!apn[ai[cr]]) ++cans;
			++apn[ai[cr]];
		}
		while(cl > qi[i].l)
		{
			--cl;
			if(!apn[ai[cl]]) ++cans;
			++apn[ai[cl]];
		}
		while(cl < qi[i].l)
		{
			--apn[ai[cl]];
			if(!apn[ai[cl]]) --cans;
			++cl;
		}
		while(cr > qi[i].r)
		{
			--apn[ai[cr]];
			if(!apn[ai[cr]]) --cans;
			--cr;
		}
		while(ct < qi[i].t)
		{
			++ct;
			if(pi[ct]>=cl && pi[ct]<=cr)
			{
				--apn[fi[ct]];
				if(!apn[fi[ct]]) --cans;
				if(!apn[li[ct]]) ++cans;
				++apn[li[ct]];
			}
			ai[pi[ct]] = li[ct];
		}
		while(ct > qi[i].t)
		{
			ai[pi[ct]] = fi[ct];
			if(pi[ct]>=cl && pi[ct]<=cr)
			{
				--apn[li[ct]];
				if(!apn[li[ct]]) --cans;
				if(!apn[fi[ct]]) ++cans;
				++apn[fi[ct]];
			}
			--ct;
		}
		ansi[qi[i].id] = cans;
	}
}

int tai[133335];

int main()
{
	const int n = getint();
	const int q = getint();
	for(int i=1; i<=n; ++i)
	{
		tai[i] = ai[i] = lsh(getint());
	}

	int qn = 0;
	int ti = 0;
	for(int i=1; i<=q; ++i)
	{
		if(getqr())
		{
			++qn;
			qi[qn].l = getint();
			qi[qn].r = getint();
			qi[qn].t = ti;
			qi[qn].id = qn;
		}
		else
		{
			++ti;
			const int pos = getint();
			pi[ti] = pos;
			fi[ti] = tai[pos];
			li[ti] = tai[pos] = lsh(getint());
		}
	}
  
  sqrtn = (pow((long long)n * n * ti / qn, 1.0/3) * 2.5) + 1; // ×îÓÅ¿é³¤ 
	moalgo(qn);

	for(int i=1; i<=qn; ++i)
	{
		putint(ansi[i]);
		putchar('\n');
	}
}
