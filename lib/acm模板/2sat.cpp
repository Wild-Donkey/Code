//2sat
#include <cstdio>
#define min(a,b) (a<b?a:b)
const int maxn=1e6+10;
struct EDGE{
    int t,next;
}edge[maxn<<2];
int head[maxn<<1],low[maxn<<1],dfn[maxn<<1],stack[maxn<<1],scc[maxn<<1];
bool in[maxn<<1];
int cur,n,tim,top,cnt,m;
void add(int u,int v){
    edge[++cur].t=v;
    edge[cur].next=head[u];
    head[u]=cur;
}
void tarjan(int u)
{
    low[u]=dfn[u]=++tim;
    stack[top++]=u;in[u]=true;
    for(int i=head[u]; i; i=edge[i].next){
        int v=edge[i].t;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else   if(in[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        cnt++;
        do{
            v=stack[--top];
            in[v]=false;
            scc[v]=cnt;
        }while(u!=v);
    }
}
bool two_SAT(){
    for(int i=1; i<=2*n; i++)
        if(!dfn[i])
            tarjan(i);//tarjan��ǿ��ͨ���� 
    for(int i=1; i<=n; i++)
        if(scc[i]==scc[i+n])//a�����ͷ�a������ͬһ��ǿ��ͨ������ԭ�����޽� 
            return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m;i++){
        int a,b,aval,bval;
        scanf("%d%d%d%d",&a,&aval,&b,&bval);//xaΪaval��xbΪbval 
        int nota=aval^1,notb=bval^1;//��������a��ʾ����aѡ0�������a+n��ʾ����aѡ1������� 
        add(a+nota*n,b+bval*n);//����(��a��b) 
        add(b+notb*n,a+aval*n);//����(��b��a) 
    }
    if(two_SAT()){
        printf("POSSIBLE\n");
        for(int i=1; i<=n; i++)
            printf("%d ",scc[i]>scc[i+n]);
    }else
        printf("IMPOSSIBLE");
    return 0;
}
