#include<bits/stdc++.h>
using namespace std;
int n,head[10005],cnt=0,col=0,sum;
int top=1,sta[10005],color[10005],tim[10005],low[10005],ins[10005];//color记录染色后点的颜色。
int in[10005],out[10005];//in和out分别是入度和出度。
struct net {
  int to,next;
} e[1000000];
void add(int x,int y) {
  cnt++;
  e[cnt].to=y;
  e[cnt].next=head[x];
  head[x]=cnt;
}
void tarjian(int x) { //常规缩点
  sum++;
  tim[x]=low[x]=sum;
  sta[top]=x;
  top++;
  ins[x]=1;
  for(int w=head[x]; w!=0; w=e[w].next) {
    if(ins[e[w].to]==0) {
      tarjian(e[w].to);
      low[x]=min(low[x],low[e[w].to]);
    } else if(ins[e[w].to]==1)
      low[x]=min(low[x],tim[e[w].to]);
  }
  if(tim[x]==low[x]) {
    col++;
    do {
      top--;
      color[sta[top]]=col;
      ins[sta[top]]=-1;
    } while(sta[top]!=x);
  }
  return ;
}
int hym[1000000][3];
int main() {
  freopen("P2746_3.in", "r", stdin); 
  int i,k=0;
  cin>>n;
  for(i=1; i<=n; i++) {
    int x;
    cin>>x;
    while(x!=0) {
      k++;
      add(i,x);
      hym[k][1]=i;
      hym[k][2]=x;//记下边，方便之后统计入度和出度。
      scanf("%d",&x);
    }
  }
  for(i=1; i<=n; i++) {
    if(!ins[i]) tarjian(i);
    printf("%d %d\n", i, color[i]);
  }
  for(i=1; i<=k; i++)
    if(color[hym[i][1]]!=color[hym[i][2]]) { //同种颜色不需要统计，不同颜色更改出度和入度。
      out[color[hym[i][1]]]++;
      in[color[hym[i][2]]]++;
    }
  int ans1=0,ans2=0;
  for(i=1; i<=col; i++) {
    //cout<<in[i]<<' '<<out[i]<<endl;
    if(in[i]==0)  ans1++;
    if(out[i]==0) ans2++;
  }
  if(col==1) cout<<1<<endl<<0;
  else
    cout<<ans1<<endl<<max(ans1,ans2);
  return 0;
}
