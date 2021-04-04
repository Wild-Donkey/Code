#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int n,k;
int a[N];
int q_min[N],q_max[N]; 
void min_q()
{
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&q_min[head]+k<=i) head++; 
	    while(head<=tail&&a[i]<a[q_min[tail]]) tail--;
	    q_min[++tail]=i;
	    if(i>=k) printf("%d ",a[q_min[head]]);
	}
}
void max_q()
{
	int head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(head<=tail&&q_max[head]+k<=i) head++;
        while(head<=tail&&a[i]>a[q_max[tail]]) tail--;
        q_max[++tail]=i;
        if(i>=k) printf("%d ",a[q_max[head]]);
    }
} 
int main()
{
	freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	min_q();
	puts("");
	max_q();
}
