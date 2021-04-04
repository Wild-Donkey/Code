#include<iostream>
#include<cstdio>

using namespace std;

int k,m,n;
int a[1000001],p[1000001],q[1000001];
int head,tail;

void queue_minn()
{
	head=1;
        tail=0;//为啥要这样呢?因为head要严格对应首元素，tail要严格对应尾元素，所以当tail>=head时，说明有元素。而一开始队列为空，说一要这样赋值。其实这跟普通队列一样。
        for(int i=1;i<=n;++i)
        {//a[i]表示当前要处理的值
            while(head<=tail&&q[tail]>=a[i])
                tail--;//只要队列里有元素，并且尾元素比待处理值大，即表示尾元素已经不可能出场，所以出队。直到尾元素小于待处理值，满足"单调"。
            q[++tail]=a[i];//待处理值入队。
            p[tail]=i;//同时存下其编号
            while(p[head]<=i-k)
                head++;//如果队首元素已经"过时"，出队。
            if(i>=k)printf("%d ",q[head]);//输出最值，即队首元素。i>=k表示该输出，至于why就自己看题目。
        }
        printf("\n");

}

void queue_maxx()
{
	head=1;
        tail=0;
        for(int i=1;i<=n;++i)
        {
            while(head<=tail&&q[tail]<=a[i])
                tail--;
            q[++tail]=a[i];
            p[tail]=i;
            while(p[head]<=i-k)
                head++;
            if(i>=k)printf("%d ",q[head]);
        }
        printf("\n");
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(tail>=head&&p[tail]>=a[i])
			tail--;
		tail++;
		p[tail]=a[i];
		q[tail]=i;
		while(q[head]<=i-k)
			head++;
		if(i>=k)
			printf("%d ",p[head]);
	}
	printf("\n");
	head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(tail>=head&&p[tail]<=a[i])
			tail--;
		tail++;
		p[tail]=a[i];
		q[tail]=i;
		while(q[head]<=i-k)
			head++;
		if(i>=k)
			printf("%d ",p[head]);
	}
	printf("\n");
	return 0;
}
