//´úÂë²Î¿¼À¶Êép10
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
struct Seg {
	int a,b;
} a[20005];
bool cmp(Seg x,Seg y) {
	return x.a<y.a;
}
void Read() {
	cin>>n;
	cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i].a;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i].b;
	}
	return;
}
void Solve() {
	
}
int main() {
	Read();
	sort(a+1,a+cnt+1,cmp);
	Solve();
	return 0;
}
