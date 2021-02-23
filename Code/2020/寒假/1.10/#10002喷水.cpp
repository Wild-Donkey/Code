//代码参考蓝书p10
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n,cnt,L,h,x,r;
struct Seg {
	double x,y;
} a[20005];
bool cmp(Seg x,const Seg y) {
	return x.x<y.x;
}
void Read() {
	cin>>n>>L>>h;
	cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>x>>r;
		if(r<=h/2)
			continue;
		cnt++;
		a[cnt].x=x-sqrt(r*r-h*h/4.0);
		a[cnt].y=x+sqrt(r*r-h*h/4.0);
	}
	return;
}
void Solve() {
	double t=0;
	int ans=0,bj=1;
	while(t<L) {
		ans++;
		double s=t;//s:上一个喷头覆盖的右端
		for(int i=1; a[i].x<=s&&i<=cnt; i++) //覆盖到已覆盖的右端
		{
		//	cout<<a[i].x<<"	"<<a[i].y<<"	"<<s<<endl;
			if(t<a[i].y)
				t=a[i].y;//更新，使选择最优（覆盖最远）
		}
	//	cout<<"t	"<<t<<"	s	"<<s<<"	l	"<<L<<endl;
		if(t==s&&s<L) { //无法继续（断层）并且未覆盖完
			cout<<-1<<endl;
			bj=0;//打无解标记
			break;
		}
	}
	if(bj)
		cout<<ans<<endl;
	return;
}
int main() {
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		Read();
		sort(a+1,a+cnt+1,cmp);
		Solve();
	}
	return 0;
}
