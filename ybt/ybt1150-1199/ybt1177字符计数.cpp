#include<iostream>
using namespace std;
int x[100005],Ans[1005]= {0},n,t;
char a;
int main() {
	n=0;
	t=n;
	while(cin>>a)
		x[++n]=int(a);
	for(int i=1; i<=n; i++)
		Ans[x[i]]++;
	for(int i=int('z'); i>=int('a'); i--)
		if(Ans[t]<=Ans[i])
			t=i;
	a=char(t);
	cout<<a<<" "<<Ans[t];
	return 0;
}
