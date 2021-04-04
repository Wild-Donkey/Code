#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 525525525
#include <vector>
using namespace std;

int n,m,a[100010];

bool ok(int max){
	long long t=0;
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i]>max)	return 0;
		if(a[i]+t>max){
			res++;
			t=a[i];
		}
		else if(t==max){
			res++;
			t=a[i];
		}
		else if(a[i]+t==max){
			res++;
			t=0;
		}
	
		else t+=a[i];
	}
	if(t!=0)	res++;
	if(res <= m)	return 1;
	return 0;
}
long long sum=0;
int main()
{
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		sum+=a[i];
	}
//	if(sum==0){
//		cout<<0<<endl;
//		return 0;
//	}
	int l=1,r=INF;
	while(l<r){
		long long mid=(l+r)/2;
		if(ok(mid))	r=mid;
		else l=mid+1;
//		cout << mid << endl;
	}
	printf("%d\n",l);

	return 0;
}
/*
7 5
200 300 300 200 500 221 420
*/

