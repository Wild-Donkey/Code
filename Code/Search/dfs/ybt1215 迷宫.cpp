#include<iostream>
#include<cstring>
using namespace std;
int xr[4] = { 0,1,0,-1 };
int yr[4] = { -1,0,1,0 };//操作记录
int x_1, x_2, y_1, y_2, T, n;
char a;
bool vsd[100][100], flag;
void dfs(int x, int y) {//深搜
	if (flag) {
		return;
	}
	if ((x < 0) || (y < 0)) {
		return;
	}
	if ((x >= n) || (y >= n)) {
		return;
	}
	if (vsd[x][y]) {
		return;
	}
	vsd[x][y] = 1;
	if ((x == x_2) && (y == y_2)) {
		cout << "YES" << endl;
		flag = true;//打标记
		return;
	}
	for (int i = 0; i < 4; i++) {
		dfs(x + xr[i], y + yr[i]);
	}
	return;
}
int main() {
	cin >> T;
	for (int o = 1; o <= T; o++) {//多组数据
		memset(vsd, false, sizeof(vsd));//清空数组
		flag = false;//初始化flag
		cin >> n;//输入矩阵大小
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				if (a == '#') {
					vsd[i][j] = 1;//禁止通行可以用已访问到等效代替
				}
			}
		}
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		if (vsd[x_1][y_1] || vsd[x_2][y_2]) {//特判起点或终点是“#”的时候
			cout << "NO" << endl;
			continue;
		}
		else {//从x_1,y_1的位置开始搜
			dfs(x_1, y_1);
		}
		if (!flag) {//到最后也没有连通
			cout << "NO" << endl;
		}
	}
	return 0;
}