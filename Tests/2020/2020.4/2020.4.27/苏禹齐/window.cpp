#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000005],k,front=0,rear=0;
struct node{ 
	int v,index;
}q[1000005];
void min(){
	int front=1,rear=0;
	for(int i=1;i<=n;i++){
		while(front<=rear&&q[rear].v>=a[i])
			rear--;
		q[++rear].v=a[i];
		q[rear].index=i;
		if(i-k>=q[front].index)
			front++;
		if(i>=k){
			printf("%d",q[front].v);
			if(i!=n)
				printf(" ");
		}	
	}
	printf("\n");
}
void max(){
	int front=1,rear=0;
	for(int i=1;i<=n;i++){
		while(front<=rear&&q[rear].v<=a[i])
			rear--;
		q[++rear].v=a[i];
		q[rear].index=i;
		if(i-k>=q[front].index)
			front++;
		if(i>=k){
			printf("%d",q[front].v);
			if(i!=n)
				printf(" ");
		}	
	}
	printf("\n");
}
int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		while(front<=rear&&q[rear].v<=a[i])
			rear--;
		q[++rear].v=a[i];
		q[rear].index=i;
	}
	min();
	max();
	fclose(stdin);
    fclose(stdout);
	return 0;
}
