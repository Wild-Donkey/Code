#include<iostream>
using namespace std;
int N,a[100005];
void qs(int l,int r)
{
	int m=(l+r)/2;
	int i=l,j=r;
	while(i<j)
	{
		while(a[i]<=a[m])
			i++;
		while(a[j]>=a[m])
			j--;
		if(i<j)
		{
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	qs(l,i);
	qs(j,r);
	return;
}
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	qs(1,N);
	for(int i=1;i<=N;i++)
		cout<<a[i]<<" ";
	return 0;
}
