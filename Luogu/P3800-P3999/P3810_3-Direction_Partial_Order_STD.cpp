#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
#define maxk 200010
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(isdigit(ch)==0 && ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    int f=0;char ch[20];
    if(!x){puts("0");return;}
    if(x<0){putchar('-');x=-x;}
    while(x)ch[++f]=x%10+'0',x/=10;
    while(f)putchar(ch[f--]);
    putchar('\n');
}
typedef struct node
{
    int x,y,z,ans,w;	
}stnd;
stnd a[maxn],b[maxn];
int n,cnt[maxk];
int k,n_;
bool cmpx(stnd u,stnd v)
{
    if(u.x==v.x)
    {
        if(u.y==v.y)
            return u.z<v.z;
        return u.y<v.y;
    }
    return u.x<v.x;
}
bool cmpy(stnd u,stnd v)
{
    if(u.y==v.y)
        return u.z<v.z;
    return u.y<v.y;
}
struct treearray
{
    int tre[maxk],kk;
    int lwbt(int x){return x&(-x);}
    int ask(int i){int ans=0; for(;i;i-=lwbt(i))ans+=tre[i];return ans;}
    void add(int i,int k){for(;i<=kk;i+=lwbt(i))tre[i]+=k;}
}t;
void cdq(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq(l,mid);cdq(mid+1,r);
    sort(a+l,a+mid+1,cmpy);
    sort(a+mid+1,a+r+1,cmpy);
    int i=mid+1,j=l;
    for(;i<=r;i++)
    {
        while(a[j].y<=a[i].y && j<=mid)
            t.add(a[j].z,a[j].w),j++;
        a[i].ans+=t.ask(a[i].z);
    }
    for(i=l;i<j;i++)
        t.add(a[i].z,-a[i].w);
}
int main()
{
	 freopen("P3810_2.in", "r", stdin);
	 freopen("P3810_std.out", "w", stdout);
    n_=read(),k=read();t.kk=k;
    for(int i=1;i<=n_;i++)
        b[i].x=read(),b[i].y=read(),b[i].z=read();
    sort(b+1,b+n_+1,cmpx);
    int c=0;
    for(int i=1;i<=n_;i++)
    {
        c++;
        if(b[i].x!=b[i+1].x || b[i].y!=b[i+1].y || b[i].z!=b[i+1].z )
            a[++n]=b[i],a[n].w=c,c=0;
    }
    for (register unsigned i(1); i <= n; ++i) printf("%u Same %u\n", i, a[i].w);
    cdq(1,n); 	
    for(int i=1;i<=n;i++)
        cnt[a[i].ans+a[i].w-1]+=a[i].w;
    for(int i=0;i<n_;i++)
        write(cnt[i]);
    return 0;
}
