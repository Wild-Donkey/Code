#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxn=100001;
int an[Maxn],l,r,a,ans,answer;
int main()
{
	cin>>l>>r;
	for(int i=2;i<=r;i++)
	{
		a=i;
		ans=0; 
		if(a/10000==2)
			ans++;//万位
		a%=10000;
		if(a/1000==2)
			ans++;//千位
		a%=1000;
		if(a/100==2)
			ans++;//百位
		a%=100;
		if(a/10==2)
			ans++;//十位
		a%=10;
		if(a==2)
			ans++;//个位
		an[i]=ans+an[i-1];
	}
	answer=an[r]-an[l-1];
	cout<<answer;
	return 0;
}
