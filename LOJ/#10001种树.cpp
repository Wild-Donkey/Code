#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct suggestion {
	int left,right,number;
} a[5005];
int h,n,ans=0;
bool tr[30005]= {0};
bool cmp(suggestion x,suggestion y) {
	return x.right<y.right;
}
int main() {
	cin>>n>>h;
	for(int i=1; i<=h; i++)
		cin>>a[i].left>>a[i].right>>a[i].number;
	sort(a+1,a+1+h,cmp);
	
	for(int i=1; i<=h; i++) {
		
		int cnt=0;
		for(int j=a[i].left; j<=a[i].right; j++)
			cnt+=tr[j];
		if(cnt>=a[i].number)
			continue;
			
		int j=a[i].right+1;
		cnt=a[i].number-cnt;
		while(cnt) {
			if(tr[--j])
				continue;
			tr[j]=1;
			cnt--;
			ans++;
		//	cout<<j<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
