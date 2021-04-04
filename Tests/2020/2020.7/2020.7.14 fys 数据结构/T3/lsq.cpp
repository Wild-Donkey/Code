#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

#define INF -1<<30

struct node{
	int val;
	int num;
	
	node(int a,int b):val(a),num(b){};
	
	friend bool operator <(const node& p,const node& l)
	{
		return p.val<l.val;
	}
	
};

multiset<node> s;
int f[500005];

int main()
{
	
	//freopen("t3_25.in","r",stdin);
	//freopen("my.txt","w",stdout);	
	int n;
	
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1,x;i<=n;i++)
	{
		
		cin>>x;
		s.insert(node(x,i));
		f[i]=x;
	}
	
	int m;

	cin>>m;
	int py=n;
	
	for(int i=1;i<=m;i++)
	{
		int x;
		int g;
		cin>>x;
		multiset<node>::iterator it;
		if(x == 0)
		{
			it=s.end();
			if( it == s.begin())
			{
				cout<<-1061109567<<'\n';
				continue;
			}
			it--; 
			node u=*it;
			cout<< u.val<<'\n';
		}
		if(x == 1)
		{
			cin>>g;
			
			s.insert(node(g,++py));
			f[py]=g;
		}
		if(x == 2 )
		{
			cin>>g;
			if(f[g] == INF)
			{
				continue;
			}
			if(g >py)continue;
			
			multiset<node>::iterator it=s.find(node(f[g],g));
			s.erase(it);
			f[g]=INF;
		}
		
	}
} 





/*
5
3 5 3 2364 4
11
0
2 4
0
2 2
0
2 1
2 1
0
2 5
2 3
0
*/
/*

2364
5
4
4
-1061109567
*/

/*
5
532 2534 7324 354 56
8
0
2 123
0
2 3
1 0
0
2 6
0
*/

/*
7324
7324
2534
2534

*/
