#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
typedef vector<int> VI;
template<class T> inline int size(const T&c) { return c.size(); }
 
int V,E;
vector<vector<int> > edges;
vector<vector<int> > backEdges;
vector<int> scc;
vector<int> order;
vector<vector<int>> groups;
vector<char> vis;
 
vector<int> groupType;
vector<int> groupCnt;
 
void dfs1(int x) {
  if(vis[x]) return;
  vis[x]=true;
  FOREACH(it, edges[x]) dfs1(*it);
  order.push_back(x);
}
 
void dfs2(int x) {
  if(vis[x]) return;
  vis[x] = true;
  groups.back().push_back(x);
  scc[x] = size(groups)-1;
  FOREACH(it, backEdges[x]) dfs2(*it);
}
 
void calcSCC() {
  order.clear();
  vis.assign(V, 0);
  REP(i, V) if(!vis[i]) dfs1(i);
  vis.assign(V, 0);
  scc.assign(V, -1);
  FORD(i, V-1, 0) if(!vis[order[i]]) {
    groups.push_back(VI());
    dfs2(order[i]);
  }
}
 
bool checkOK() {
  groupType.assign(size(groups), 1);
  REP(g, size(groups)) {
    for(int x : groups[g]) {
      int cnt = 0;
      for(int y : edges[x]) if(scc[y]==g) {
        ++cnt;
      }
      if(cnt>1) return false;
      if(cnt==0) groupType[g]=0;
    }
  }
  return true;
}
 
void calcGroupCnt() {
  groupCnt = groupType;
  REP(g, size(groups)) {
    for(int x : groups[g]) {
      for(int y : backEdges[x]) if(scc[y]!=g) {
        int h = scc[y];
        groupCnt[g] = max(groupCnt[g], groupType[g] + groupCnt[h]);
      }
    }
  }
}

int main(){
  freopen("t2.in", "r", stdin);
  freopen("std.out", "w", stdout);
    scanf("%d%d",&V,&E);
    edges.resize(V);
    backEdges.resize(V);
    REP(i,E){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        edges[u].push_back(v);
        backEdges[v].push_back(u);
    }
    calcSCC();
    if(!checkOK()) return puts("-1"),0;
    calcGroupCnt();
    int res = *max_element(groupCnt.begin(), groupCnt.end());
    if(res>0) --res;
    printf("%d",res);
    return 0;
}
