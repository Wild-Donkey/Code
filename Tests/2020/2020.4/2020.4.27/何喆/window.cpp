#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
struct node{int num,val;};
int x;
deque<node> MIN;
deque<node> MAX;
int ans[3][1000005];     
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
    int n,m,k,cnt=1;
    cin>>n>>k;
    node tmp;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        tmp.num=i; tmp.val=x;
        while(!MIN.empty()&&x>=MIN.back().val) MIN.pop_back();
        while(!MAX.empty()&&x<=MAX.back().val) MAX.pop_back();
        MIN.push_back(tmp); MAX.push_back(tmp);
        while(i-k>=MIN.front().num) MIN.pop_front();
        while(i-k>=MAX.front().num) MAX.pop_front();
        if (i>=k) ans[0][cnt]=MIN.front().val,ans[1][cnt]=MAX.front().val,cnt++;
    }
    for(int i=1;i<cnt;i++)
    	printf("%d ",ans[1][i]);
    puts("");
    for(int i=1;i<cnt;i++)
    	printf("%d ",ans[0][i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
