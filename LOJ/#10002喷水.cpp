//����ο�����p10
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
		double s=t;//s:��һ����ͷ���ǵ��Ҷ�
		for(int i=1; a[i].x<=s&&i<=cnt; i++) //���ǵ��Ѹ��ǵ��Ҷ�
		{
		//	cout<<a[i].x<<"	"<<a[i].y<<"	"<<s<<endl;
			if(t<a[i].y)
				t=a[i].y;//���£�ʹѡ�����ţ�������Զ��
		}
	//	cout<<"t	"<<t<<"	s	"<<s<<"	l	"<<L<<endl;
		if(t==s&&s<L) { //�޷��������ϲ㣩����δ������
			cout<<-1<<endl;
			bj=0;//���޽���
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
