#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
int n,ans=0;
double t1,t2,s1,s2,h,s,v,ch,cw;
bool flg;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lf %lf %lf %lf %lf %d",&h,&s,&v,&cw,&ch,&n);
    if(h>ch){
        t1 = sqrt(2 * (h - ch) / 10);
    }
    else{
        t1 = 0;
    }
    t2 = sqrt(2 * h / 10);
    s1 = s - (t1 * v) + cw;
    s2 = s - (t2 * v);
    //printf("%lf %lf\n", t1, t2);
    //printf("%lf %lf\n", s1, s2);
    if (s1 < -0.0001){
        printf("0\n");
        return 0;
    }
    if (s1 > n - 1){
        s1 = n - 1;
    }
    if (s2 > n - 0.9999){
        printf("0\n");
        return 0;
    }
    if (s1 - int(s1) >= 0.9999){
        ans++;
    }
    if (s2 < -0.0001){
        ans += int(s1) + 1;
        printf("%d\n", ans);
        return 0;
    }
    if(s2 - int(s2)<=0.0001){
        ans++;
    }
    ans += int(s1) - int(s2);
    printf("%d\n", ans);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}