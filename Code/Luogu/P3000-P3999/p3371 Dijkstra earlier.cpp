#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, s/*start*/, f/*from*/, t/*to*/, l/*length*/, fst[10105]/*first，第i个节点的最后一条边*/, nx[500105]/*next,以第i条边的起点为起点的下一条边*/, to[500105]/*第i条边的终点*/, len[500105]/*length，第i条边的长度*/, mi[10105]/*min，到第i条边的最短路*/;
bool vstd[10105]/*visited，记录是否访问过i点的标记*/;
priority_queue<pair<int/*这条变的长度*/, int/*这条边的起点*/>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int main() {
	cin >> n >> m >> s;
	for (int cnt = 1; cnt <= m; cnt++) {
		cin >> f >> t >> l;
		nx[cnt] = fst[f];
		fst[f] = cnt;
		to[cnt] = t;
		len[cnt] = l;//存图（稀疏图）
	}
	memset(mi, 0x3f, sizeof(mi));//一开始最短路都是0
	mi[s] = 0;
	q.push(make_pair(0, s));
	while (!(q.empty())) {/*这一步要访问队首的边*/
		int at = q.top().second;
		q.pop();
		if (vstd[at]) {//每个点只能经过一次
			continue;
		}
		vstd[at] = 1;//标记
		int ats = fst[at];//ats存储当前枚举的边（枚举以at为起点的所有边，尝试使该边的终点的最短路经过at，判断是否更新）
		while (ats) {//只要前一次循环的ats还有下一条边（nx(ats)），就遍历下一条边
			int pnt = to[ats];//pnt存当前边的终点，本次循环更新这个点
			if (mi[at] + len[ats] < mi[pnt]) {//走at的路线更优
				mi[pnt] = mi[at] + len[ats];//经过at更新pnt的最短路
				q.push(make_pair(mi[pnt], pnt));//使pnt入队，尝试更新别的点的最短路
			}
			ats = nx[ats];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (mi[i] >= 0x3f3f3f3f)
			cout << 0x7fffffff << " ";
		else
			cout << mi[i] << " ";
	}
	return 0;
}