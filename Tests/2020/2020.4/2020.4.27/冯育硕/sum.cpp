#include<cstdio>
#include<iostream>
using namespace std;
int n, m, number[100001], color[100001], ans, a[100001][2], sum[100001][2];
int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {//��������
		scanf("%d", &number[i]);
	}
	for (int i = 1; i <= n; i++) {//������ɫ
		scanf("%d", &color[i]);
		a[color[i]][i % 2]++;//ÿ����ɫ, ����ż������, a���������ص�����, ֻҪx,z��ż��һ��, y��һ������
		sum[color[i]][i % 2] += number[i];//��ǰ׺��, ����iǰ������ĺ�
		sum[color[i]][i % 2] %= 10007;//ȡģ
	}
	for (int i = 1; i <= n; i++) {/*������ѧ����, ���Ĵ𰸿��Ի�Ϊ:ÿһ�����ı�ź�((������Ԫ���������ͱ����˻�)����(������������ܺ�))�ĳ˻�*/
		int t = a[color[i]][i % 2] - 2;
		t *= number[i];//���ֳ��������ڵ����Ԫ������-2
		t %= 10007;//ȡģ
		t += sum[color[i]][i % 2];//�����������ܺ�
		t *= i;//������
		ans += t;//�ۼ�
		ans %= 10007;//ȡģ
	}
	cout << ans;//�����
	return 0;
}
