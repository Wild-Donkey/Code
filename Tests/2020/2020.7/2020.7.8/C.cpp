#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, ans[105],cnt;
bool flg;
char ch;
string s,a[105];
struct Node{
	int have;
	Node *son[27]; 
}N[1005], *cntn=N;
inline int IN() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
void Add(string x,int y){
	int len=x.length();
	Node *now=N;
	for(int i=0; i<len; i++){
		//printf("go %d %d\n",now->have,x[i]-'a'); 
		if(now->son[x[i]-'a']==NULL){
			now->son[x[i]-'a']=++cntn;	
		}
		now=now->son[x[i]-'a'];
	}
	now->have=y;
	return;
}
void Print(int x) {
	//printf("faq\n");
	for(int i=1;i<=x;i++){
		cout<<a[ans[i]];
		if(i<x){
			printf("_"); 
		}
	}
	printf("\n");
	return;
}
void Dfs(int at/*当前位, 和now的儿子节点对应*/, int x/*第x个单词*/){
	Node *now=N; 
	int len=s.length();
	if(at>=len){
		if(at==len){
			Print(x-1);
		}
		return;
	}
	while(now->son[s[at]-'a']!=NULL){//能走 
		now=now->son[s[at]-'a'];
		at++; 
		if(now->have){//搜到了一个分支 
			ans[x]=now->have;
			Dfs(at,x+1);
			ans[x]=0;//还原 
		}
	}
	return;	
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>s;
    n = IN();
    for (register int i = 1; i <= n; i++) {
    	cin>>a[i];
    	//cout<<a[i];
    	Add(a[i],i);
    }
	Dfs(0,1);
	fclose(stdin);
	fclose(stdout);
  return 0;
}
/*
pineapplepenapple
5
apple
pen
applepen
pine
pineapple

pine_apple_pen_apple
pine_applepen_apple
pineapple_pen_apple
*/
