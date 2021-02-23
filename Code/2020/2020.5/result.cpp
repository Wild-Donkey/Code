#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, s[20]= {0},s150=0;
struct stu {
	string name;
	int sco;
} a[130000];
bool cmp(stu x,stu y) {
	return(x.name<y.name);
}
int main() {
	freopen("result.in","r",stdin);
	freopen("result.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].name>>a[i].sco;
		if(a[i].sco==150) {
			s150++;
		}
		s[a[i].sco/10]++;
	}
	cout<<"1~9 10~19 20~29 30~39 40~49 50~59 60~69 70~79 80~89 90~99 100~109 110~119 120~129 130~139 140~149"<<endl;
	for(int i=0; i<=14; i++) {
		printf("%d ",s[i]);
	}
	cout<<endl;
	sort(a+0,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		cout<<a[i].name<<" "<<a[i].sco<<endl;
	}
	cout<<s150<<endl;
	if(s150==0) {
		cout<<"NO"<<endl;
	} else {
		for(int i=1; i<=n; i++) {
			if(a[i].sco==150) {
				cout<<a[i].name<<endl;
			}
		}
	}
	return 0;
}
