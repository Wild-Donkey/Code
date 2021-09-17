#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define MOD (10007)
#define  N  (10005)
using namespace std;

int Son[N][26],End[N],Fail[N];
int n,m,sz,f[105][N],ans;
char s[N];
queue<int>q;

void Insert(char s[])
{
    int now=0,len=strlen(s);
    for (int i=0; i<len; ++i)
    {
        int x=s[i]-'A';
        if (!Son[now][x]) Son[now][x]=++sz;
        now=Son[now][x];
    }
    End[now]|=1;
}

void Build_Fail()
{
    for (int i=0; i<26; ++i)
        if (Son[0][i])
            q.push(Son[0][i]);
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        for (int i=0; i<26; ++i)
        {
            if (!Son[now][i])
            {
                Son[now][i]=Son[Fail[now]][i];
                continue;
            }
            End[Son[now][i]]|=End[Son[Fail[now]][i]];
            Fail[Son[now][i]]=Son[Fail[now]][i];
            q.push(Son[now][i]);
        }

    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%s",s),Insert(s);
    Build_Fail();
    f[0][0]=1;
    for (int i=1; i<=m; ++i)
        for (int j=0; j<=sz; ++j)
            for (int k=0; k<26; ++k)
                if (!End[Son[j][k]])
                    (f[i][Son[j][k]]+=f[i-1][j])%=MOD;
    for (int i=0; i<=sz; ++i)
      (ans+=f[m][i])%=MOD, printf("%u %u\n", i, f[m][i]);
    int sum=1;
    for (int i=1; i<=m; ++i)
        sum=sum*26%MOD;
    printf("Ans %u\n", ans);
    printf("%d\n",(sum-ans+MOD)%MOD);
}
