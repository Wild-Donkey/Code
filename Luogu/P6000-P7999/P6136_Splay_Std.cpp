#include<bits/stdc++.h>


using namespace std;

#define INF 1<<30
#define int long long 
#define s(x) t[x].si
#define v(x) t[x].val
#define f(x) t[x].fa
#define c(x) t[x].cnt
#define lson(x) t[x].ch[0]
#define rson(x) t[x].ch[1] 

template<typename _T>
inline void read(_T &x)
{
 x= 0 ;char s=getchar();int f=1;
 while(s<'0'||'9'<s){f=1;if(s=='-')f=-1;s=getchar();}
 while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
 x*=f;
 }

const int p=2e6+5;

struct node{
 int cnt;
 int si;
 int val;
 int fa;
 int ch[2];
}t[p];

int root,tot;

inline void pushup(int x)
{
 s(x) = s(lson(x)) + s(rson(x))+c(x);
}

inline void rotate(int x)
{
 int y = f(x);
 int z = f(y);
 int k = rson(y) == x;
 t[z].ch[rson(z) == y] = x;f(x) = z;
 t[y].ch[k] = t[x].ch[k^1];f(t[x].ch[k^1]) = y;
 t[x].ch[k^1] = y;f(y) = x;
 pushup(y);
 pushup(x);
}

inline void splay(int x,int goal)
{
 while(f(x)!=goal)
 {
  int y = f(x);
  if(f(y)!=goal) (lson(f(y)) == y) ^ (lson(y) == x) ? rotate(x) : rotate(y);
  rotate(x);
 }
 if(!goal) root = x;
}

inline void insert(int x)
{
 int u = root,ff = 0;
 while(u&& v(u)!=x)
 {
  ff =u;
  u = t[u].ch[x > v(u)]; 
 }
 if(u){c(u)++;}
 else
 {
  u = ++tot;
  if(ff){t[ff].ch[x> v(ff)] = u;}
  f(u) = ff;
  v(u) = x;
  c(u) = s(u) = 1;
  lson(u) = rson(u) = 0;
 }
 splay(u,0);
}

inline void Find(int x)
{
 int u =root;
 if(!u) return ;
 while(t[u].ch[x> v(u)] && v(u)!=x) u = t[u].ch[x> v(u)];
 splay(u,0);
}

inline int prenxt(int x,int fl)
{
 int u = root;
 if((v(u) < x && fl) ||(v(u)> x&&!fl)) return v(u);
 u = t[u].ch[fl];
 while(t[u].ch[fl^1]) u = t[u].ch[fl^1];
 return u;
}

inline void Del(int x)
{
 Find(x);
 int last = prenxt(x,0);
 int nxt = prenxt(x,1);
 splay(last, 0);
 splay(nxt , last);
 int g = lson(nxt);
 if(c(g)>1) c(g)-- ,splay(g,0);
 else lson(nxt) = 0;
 return ;
}

inline int k_th(int x)
{
 int u =root;
 while(2333)
 {
  int y = lson(u);
  if(s(y) + c(u) < x) 
  {
   x-=s(y) + c(u);
   u = rson(u);
  }
  else
  {
   if(s(y)+1<=x) return v(u);
   else u = lson(u);
  }
 }
}
int n,m;
signed main()
{
  freopen("P6136_6.in", "r", stdin);
  freopen("std.out", "w", stdout);
 read(n);
 read(m);
 int la =0 ;
 insert(-INF);
 insert(INF);
 int ans = 0; 
 for(int i=1,x;i<=n;i++)
 {
  read(x);
  insert(x);
  }
 for(int i=1,opt,x;i<=m;i++)
 {
  read(opt);
  read(x);
  x ^= la;
  switch(opt)
  {
  case 1:insert(x);break;
  case 2:Del(x);break;
  case 3:insert(x);Find(x);la = s(lson(root));Del(x);break;
  case 4:la = k_th(x+1);break;
  case 5:insert(x);la = v(prenxt(x,0));Del(x);break;
  case 6:insert(x);la = v(prenxt(x,1));Del(x);break;
  }
    if(opt!=1 && opt!=2) {
      ans^=la;
      if(i >= 329200) {
        printf("%u %u %u\n", i, opt, la);
      } 
    }
 }
 
 cout<<ans;
 
 return 0;
}
