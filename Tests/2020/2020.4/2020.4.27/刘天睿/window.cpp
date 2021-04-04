#include <iostream> 
#include <cmath>
#include <cstdio>
using namespace std;
int n,k,a[1000001],q[1000001],head,rear;
/*
	思想：循环队列
*/ 
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	head=0;
	rear=0;
	//大的 
	for(int i=1;i<k;i++)
    {
        while(rear>=head&&a[q[rear]]>=a[i]){
			rear--;
		}
        q[++rear]=i;
    }
    for(int i=k;i<n+1;i++)
    {
        while(rear>=head&&a[q[rear]]>=a[i]){
			rear--; 
		} 
        q[++rear]=i;
        if(i-q[head]>=k){
			head++; 
		}
        cout<<a[q[head]]<<" "; 
    }
    
    //小 
    cout<<endl;   
    for(int i=1;i<k;i++)
    {
        while(rear>=head&&a[q[rear]]<=a[i]){
			rear--;
		} 
        q[++rear]=i;
    }
    for(int i=k;i<=n;i++)
    {
        while(rear>=head&&a[q[rear]]<=a[i]){
        	rear--;
		}
        q[++rear]=i;

        if(i-q[head]>=k){
        	head++;
		}
        cout<<a[q[head]]<<" "; 
    }
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
