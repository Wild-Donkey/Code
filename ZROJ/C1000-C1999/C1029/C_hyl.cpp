#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,a[N],t,f[N],cnt;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) read(a[i]);
}

inline void Dp(int k,int fa,int mid){
    f[k]=a[k];
    vector<int> v;v.clear();
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dp(to,k,mid);if(cnt>=m) return;
        v.push_back(f[to]);
    }
    if(cnt>=m) return;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int now=v[i];
        if(f[k]+now<=mid) f[k]+=now;
        else{cnt+=v.size()-i;break;}
    }
}

inline bool Check(int mid){
    cnt=0;Dp(1,0,mid);return cnt<m;
}

inline int Binary(){
    int l=-INF,r=0;
    for(int i=1;i<=n;i++) r+=a[i];
    for(int i=1;i<=n;i++) l=Max(l,a[i]);
    int ans=r;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(mid)){
            r=mid-1;ans=mid;
        }
        else l=mid+1;
    }return ans;
}

inline void Clear(){
    tail=0;for(int i=1;i<=n;i++) head[i]=0;
}

signed main(){
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
    // dd now=clock();
    read(t);
    for(int i=1;i<=t;i++){
        Init();int Ans=Binary();
        printf("Case #%lld: %lld\n",i,Ans);
        Clear();
    }
    dd now2=clock();
    // printf("Time:%lf\n",(now2-now)/CLOCKS_PER_SEC);
    return 0;
}
