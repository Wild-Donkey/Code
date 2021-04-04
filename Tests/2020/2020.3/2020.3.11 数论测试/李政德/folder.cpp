#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("folder.in","r",stdin);
    freopen("folder.out","w",stdout);
    long long a,b,c,i;
    cin>>a>>b>>c;
    if(c>=b) 
	{
	    cout<<"N0"<<endl<<0;
	    return 0;
    }
    else
    {
    	for(i=1;i<100000000;i++)
    	{
    		if(a*i%b==c) 
    		break;
		}
	}
	cout<<"YES"<<endl<<i;
	return 0;
}
