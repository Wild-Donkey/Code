#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, ans = -0x3fffffff, f[105][105][105], minif_1[105][105][105], minif_2[105][105][105], spmnf[105][105];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {//处理零维区间
		for (int j = 1; j <= n; j++) {
			cin >> spmnf[i][j];
			if (spmnf[i][j] > ans) {
				ans = spmnf[i][j];
			}
		}
	}
	for (int i = 2; i <= n; i++) {//处理一维区间//枚举长度
		for (int j = 1; j + i - 1 <= n; j++) {//处理第一维坐标
			for (int k = 1; k <= n; k++) {//处理第二维坐标
				if (i == 2) {
					minif_1[i][k][j] = spmnf[k][j] + spmnf[k][j + 1];
					if (minif_1[i][k][j] > ans) {
						ans = minif_1[i][k][j];
					}
					minif_2[i][j][k] = spmnf[j][k] + spmnf[j + 1][k];
					if (minif_2[i][j][k] > ans) {
						ans = minif_2[i][j][k];
					}
				}
				else {
					minif_1[i][k][j] = minif_1[i - 1][k][j] + spmnf[k][j + i - 1];
					if (minif_1[i][k][j] > ans) {
						ans = minif_1[i][k][j];
					}
					minif_2[i][j][k] = minif_2[i - 1][j][k] + spmnf[j + i - 1][k];
					if (minif_2[i][j][k] > ans) {
						ans = minif_2[i][j][k];
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {//处理二维区间//枚举矩阵高度
		for (int j = 2; j <= n; j++) {//枚举矩阵宽度
			for (int k = 1; k + i - 1 <= n; k++) {//枚举点的纵坐标
				for (int l = 1; l + j - 1 <= n; l++) {//枚举点的横坐标
					if ((j > 2) && (i > 2)) {//够大
						f[j][k][l] = f[j][k][l] + minif_1[j][k + i - 1][l];
					}
					else {
						if (i == 2) {
							f[j][k][l] = minif_1[j][k][l] + minif_1[j][k + 1][l];
						}
						else {
							f[j][k][l] = minif_2[i][k][l] + minif_2[i][k][l + 1];
						}
					}
					//cout << f[j][k][l] << " ";
					if (f[j][k][l] > ans) {
						ans = f[j][k][l];
					}
				}
				//cout << "	";
			}
			//cout << endl;
		}
		//cout << endl << endl;
	}
	cout << ans << endl;
	return 0;
}