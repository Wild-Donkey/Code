#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10005],b[10005]= {0},c[10005];
bool flg=0;
int main() {
	freopen("vote.in","r",stdin);
	freopen("vote.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+0,a+n+1);
	int j=0;
	for(int i=1; i<=n; i++) {
		if(a[i]!=a[i-1]) {
			j++;
			c[j]=a[i];
		}
		b[j]++;
	}
	n/=4;
	for(int i=1; i<=j; i++) {
		if(b[i]>n) {
			printf("%d ",c[i]);
			flg=1;
		}
	}
	if(!flg) {
		cout<<"No such person."<<endl;
	}
	return 0;
}
