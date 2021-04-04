#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,c;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	cin>>a>>b>>c;
	long long x;
	if(c>=b){
	cout<<"N0"<<endl;
	cout<<"O";
	return 0;
	}
	 long long i=1;
	while(i) 
	{
		x=i*a;
		if(x%b==c) {
		cout<<"YE5"<<endl;
		cout<<x/a;
		return 0;
		}
		i++;
	}
 } 
