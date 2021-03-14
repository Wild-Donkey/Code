#include <iostream>
#include <cstdio>
using namespace std;
//��Ŀ�и���p
int p;
//�ݴ����е�����
long long a[100007];
//�߶����ṹ�壬v��ʾ��ʱ�Ĵ𰸣�mul��ʾ�˷������ϵ�lazytag��add�Ǽӷ������ϵ�
struct node{
    long long v, mul, add;
}st[400007];
//buildtree
void bt(int root, int l, int r){
//��ʼ��lazytag
    st[root].mul=1;
    st[root].add=0;
    if(l==r){
        st[root].v=a[l];
    }
    else{
        int m=(l+r)/2;
        bt(root*2, l, m);
        bt(root*2+1, m+1, r);
        st[root].v=st[root*2].v+st[root*2+1].v;
    }
    st[root].v%=p;
    return ;
}
//���Ĵ��룬ά��lazytag
void pushdown(int root, int l, int r){
    int m=(l+r)/2;
//�������ǹ涨�����ȶȣ����ӵ�ֵ=�˿̶��ӵ�ֵ*�ְֵĳ˷�lazytag+���ӵ����䳤��*�ְֵļӷ�lazytag
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
//�ܺ�ά����lazytag
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
//�Ѹ��ڵ��ֵ��ʼ��
    st[root].mul=1;
    st[root].add=0;
    return ;
}
//update1���˷���stdl�˿��������ߣ�stdr�˿�������ұߣ�l��������ߣ�r�������ұ�
void ud1(int root, int stdl, int stdr, int l, int r, long long k){
//���籾����͸���������û�н���
    if(r<stdl || stdr<l){
        return ;
    }
//����������������������
    if(l<=stdl && stdr<=r){
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return ;
    }
//�������������ͱ������н���������Ҳ�в�����Ĳ���
//�ȴ���lazytag
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud1(root*2, stdl, m, l, r, k);
    ud1(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//update2���ӷ����ͳ˷�ͬ��
void ud2(int root, int stdl, int stdr, int l, int r, long long k){
    if(r<stdl || stdr<l){
        return ;
    }
    if(l<=stdl && stdr<=r){
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return ;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud2(root*2, stdl, m, l, r, k);
    ud2(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//���ʣ���updateһ��
long long query(int root, int stdl, int stdr, int l, int r){
    if(r<stdl || stdr<l){
        return 0;
    }
    if(l<=stdl && stdr<=r){
        return st[root].v;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    return (query(root*2, stdl, m, l, r)+query(root*2+1, m+1, stdr, l, r))%p;
}
int main(){
    int n, m;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    bt(1, 1, n);
    while(m--){
        int chk;
        scanf("%d", &chk);
        int x, y;
        long long k;
        if(chk==1){
            scanf("%d%d%lld", &x, &y, &k);
            ud1(1, 1, n, x, y, k);
        }
        else if(chk==2){
            scanf("%d%d%lld", &x, &y, &k);
            ud2(1, 1, n, x, y, k);
        }
        else{
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
