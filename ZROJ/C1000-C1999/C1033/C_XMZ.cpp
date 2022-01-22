#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5,mod=258280327;
int T,n,m;
vector<char> s[N];
char S[N];
int nxt[N];
void upd(int pos){
	for(int i=0;i<s[pos-1].size();i++){
		s[pos].push_back(s[pos-1][i]);
	}
	for(int i=0;i<s[pos-2].size();i++){
		s[pos].push_back(s[pos-2][i]);
	}
}
int calc(){
	for(int i=0;i<m;i++){
		S[i+1]=s[n][i];
		nxt[i+1]=0;
	}
	
	nxt[1]=0;
	int j=0;
	for(int i=2;i<=m;i++){
		while(j&&S[i]!=S[j+1]) j=nxt[j];
		if(S[i]==S[j+1]) j++;
		nxt[i]=j;
	}
	return nxt[m]%mod;
}
int main()
{
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
	scanf("%d",&T);
	s[1].push_back('a');
	s[2].push_back('b');
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<=2){
			printf("0\n");
			continue;
		}
		for(int i=3;i<=n;i++){
			s[i].clear();
			upd(i);
		}
		
		printf("%d\n",calc());
	}
	return 0;
}
/*
2
4 3
5 5
*/

