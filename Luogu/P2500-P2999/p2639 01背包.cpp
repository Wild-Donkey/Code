#include<iostream>
#include<cstdio>
using namespace std;
int h,n,a[505],f[45005];
int main()
{
	cin>>h>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=h;j>=a[i];j--)//��λ���ԅ�����i����
			f[j]=max(f[j-a[i]]+a[i],f[j]);
	cout<<f[h];
	return 0;
}
