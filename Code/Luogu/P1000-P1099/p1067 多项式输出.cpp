#include<iostream> 
#include<cstdio>
using namespace std;
int a[105];
int main()
{
	cin>>a[0];
	for(int i=1;i<=a[0]+1;i++)
		cin>>a[i];
	if((a[1]!=0)&&(a[1]!=1)&&(a[1]!=-1))
		cout<<a[1]<<"x^"<<a[0];
	if(a[1]==1)
		cout<<"x^"<<a[0];
	if(a[1]==-1)
		cout<<"-x^"<<a[0];
	for(int i=a[0]-1;i>=2;i--)
	{
		if(a[a[0]-i+1]>1)
			cout<<"+";
		if(a[a[0]-i+1]==0)
			continue;
		if(a[a[0]-i+1]==1)
			cout<<"+x^"<<i;
		if(a[a[0]-i+1]==-1)
			cout<<"-x^"<<i;
		if((a[a[0]-i+1]!=1)&&(a[a[0]-i+1]!=-1))
			cout<<a[a[0]-i+1]<<"x^"<<i;
	}
	
	if(a[a[0]]==1)
		cout<<"+x";
	if(a[a[0]]==-1)
		cout<<"-x";
	if((a[a[0]]!=1)&&(a[a[0]]!=-1)&&(a[a[0]]!=0))
	{
		if(a[a[0]]>0)
			cout<<"+";
		cout<<a[a[0]]<<"x";
	}
		
	if(a[a[0]+1]>0)
		cout<<"+";
	if(a[a[0]+1]!=0)
		cout<<a[a[0]+1];
	return 0;
}
