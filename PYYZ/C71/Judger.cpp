#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
using namespace std;

#define _pe -5
#define _pc -2
#define _wa -1
#define _ok 0
#define _fl 3

void quitf(int _result ,string _message ,int _partial = 0)
{
	if(_result == _ok)
	{
		std::cout << 100 << std::endl;
		std::cerr << "ok ";
		std::cerr << _message << std::endl;
	}
	else if(_result == _wa || _result == _pc)
	{
		std::cout << _partial << std::endl;
		if(_result == _wa)std::cerr << "wrong answer ";
		else std::cerr << "partial " << _partial << " point(s) ";
		std::cerr << _message << std::endl;
	}
	else
	{
		if(_result == _fl)
			std::cout << "Crashed: Failed to run." << std::endl;
		else std::cout << "Crashed: Unrecognized verdict." << std::endl;
		std::cerr << _message << std::endl;
	}exit(0);
}

ll cnt[11111111],n;

#define _in 1
#define _out 2
#define _ans 3

void userexcept()
{
	quitf(_wa, "Unexpected EOF or character.");
}

char tmp[1005];
void userexcept(ll _l,ll _r,ll _v)
{
	string info;
	stringstream wrln;
	wrln << _v << "violates range [ " << _l << " , " << _r <<" ].";
	wrln.getline(tmp,1000);
	info=tmp;
	quitf(_wa, info);
}

ifstream opt[5];

void initspj()
{
	opt[_in].open("split.in");
	opt[_out].open("split.out");
	opt[_ans].open("answer");
}

ll readInt(ll _l,ll _r,int _typ)
{
	ll _v;
	if(!(opt[_typ] >> _v))userexcept();
	if(_v < _l || _v > _r)userexcept(_l, _r, _v);
	return _v;
}

void sysexcept()
{
	quitf(_fl, "Unexpected EOF or character in preserved files.");
}

void sysexcept(ll _l,ll _r,ll _v)
{
	string info;
	stringstream wrln;
	wrln << _v << " violates range [ " << _l << " , " << _r <<" ] in preserved files.";
	wrln.getline(tmp,1000);
	info=tmp;
	quitf(_fl, info);
}

ll preservedReadInt(ll _l,ll _r,int _typ)
{
	ll _v;
	if(!(opt[_typ] >> _v))sysexcept();
	if(_v < _l || _v > _r)sysexcept(_l, _r, _v);
	return _v;
}
int ttt;
inline void exec()
{
	n=preservedReadInt(1,1000000000000000000ll,_in);
	int oc=readInt(-1,10000000,_out);
	if(!oc)quitf(_wa, "Invalid output.");
	if(n==3||n==5||n==(3+5))
	{
		if(oc!=-1)quitf(_wa, "Expected No Solution.");
		return;
	}if(oc==-1)quitf(_wa, "Expected a valid solution.");
	ttt+=oc;
	if(ttt>1e7)quitf(_wa, "Answers too large.");
	ll tot=0,mxx=0;
	for(register int i=1;i<=oc;i++)
	{
		ll x=readInt(1,10000000,_out),y=readInt(1,n,_out);
		if(cnt[x])quitf(_wa, "Invalid output.");
		cnt[x]+=y,tot+=y;
		if(mxx<x)mxx=x;
	}if(tot!=n)quitf(_wa, "The sum of all Ci does not equal to n.");
	for(register int i=mxx;i;i--)
	{
		if(cnt[i]%i!=0)quitf(_wa, "This status will never be achieved.");
		cnt[i-1]+=cnt[i]/i,cnt[i]=0; 
	}if(cnt[0]!=1)quitf(_wa, "This status will never be achieved.");
	cnt[0]=0;
}
int main(int argc,char*argv[])
{
	initspj();
	int T=preservedReadInt(1,10000,_in);
    while(T--)exec();
	quitf(_ok, "Accepted.");
}
