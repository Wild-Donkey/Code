#include<iostream>
using namespace std;
int n,n1,n2,a1[205],a2[205],ans1=0,ans2=0;
int a[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
	cin>>n>>n1>>n2;
	for(int i=0;i<n1;i++)
		cin>>a1[i];
	for(int i=0;i<n2;i++)
		cin>>a2[i];
	for(int i=0;i<n;i++)
	{
		ans1+=a[a1[i%n1]][a2[i%n2]];
		ans2+=a[a2[i%n2]][a1[i%n1]];
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
