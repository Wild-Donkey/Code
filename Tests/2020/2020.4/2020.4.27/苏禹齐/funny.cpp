#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll k,m;
ll a,g,tot,ans,b,temp;
ll mi[20];
int main()
{
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	mi[0]=1;
    for(int i=1;i<19;i++)
		mi[i]=mi[i-1]*10;
    int t;
    scanf("%d",&t);
   	while(t--){
	   	scanf("%lld%lld",&k,&m);
      	for(int i=0;i<10;i++)
        	if(k==mi[i]&&m!=i+1){
            	printf("0\n");
				return 0;
        	}
	    a=1;
	    g=k; 
	    tot=k;
	    while(g){
	       a*=10;
	       g=g/10;
	    }
	    ans=0;
	    b=a/10;
	    while(k){
	     	ans+=(k-(b-1));
	     	b=b/10;
	     	k=k/10;
	    }
	    temp=m-ans;
	    if(temp<0){
	    	cout<<"0"<<endl;
			return 0;
	    }
		if(temp==0){
	        cout<<k<<endl;
	        return 0;
	    }
	    ans=0;
	    ll y;
	    while(1){
	       	tot*=10;
	       	y=(tot-a);
	       	if(y>=temp){
	            ans=a+temp;
	            break;
	        }
	        else
	        	temp-=y;
	        a=a*10;
	    }
    	printf("%lld\n",ans-1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
