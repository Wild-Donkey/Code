#include<iostream>
#include<cstdio>

using namespace std;

int k,m,n;
int a[1000001],p[1000001],q[1000001];
int head,tail;

void queue_minn()
{
	head=1;
        tail=0;//ΪɶҪ������?��ΪheadҪ�ϸ��Ӧ��Ԫ�أ�tailҪ�ϸ��ӦβԪ�أ����Ե�tail>=headʱ��˵����Ԫ�ء���һ��ʼ����Ϊ�գ�˵һҪ������ֵ����ʵ�����ͨ����һ����
        for(int i=1;i<=n;++i)
        {//a[i]��ʾ��ǰҪ�����ֵ
            while(head<=tail&&q[tail]>=a[i])
                tail--;//ֻҪ��������Ԫ�أ�����βԪ�رȴ�����ֵ�󣬼���ʾβԪ���Ѿ������ܳ��������Գ��ӡ�ֱ��βԪ��С�ڴ�����ֵ������"����"��
            q[++tail]=a[i];//������ֵ��ӡ�
            p[tail]=i;//ͬʱ��������
            while(p[head]<=i-k)
                head++;//�������Ԫ���Ѿ�"��ʱ"�����ӡ�
            if(i>=k)printf("%d ",q[head]);//�����ֵ��������Ԫ�ء�i>=k��ʾ�����������why���Լ�����Ŀ��
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
