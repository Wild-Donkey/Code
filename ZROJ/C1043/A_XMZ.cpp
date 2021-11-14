#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
bool check(int n,int L,int R){
	int l=0,r=n;
	bool flg=0;
	while(l<=r){
		if(l==L&&r==R){
			flg=1;
			break;
		}
		int mid=(l+r)>>1;
		if(L>mid) l=mid+1;
		else if(R<=mid) r=mid;
		else break;
	}
	return flg;
}
int main()
{
  freopen("A.in", "r", stdin);
  freopen("A.ans", "w", stdout);
	scanf("%d",&T);
	while(T--){
		int L,R,lim;
		scanf("%d%d%d",&L,&R,&lim);
		bool flg=0;
		lim=min(2*R,lim);
		for(int i=R;i<=lim;i++){
			if(check(i,L,R)){
				flg=1;
				printf("%d\n",i);
				break;
			}
		}
		if(!flg) printf("-1\n");
	}
	return 0;
}
/*
1234564 123486423 1324564684 
-1

*/
