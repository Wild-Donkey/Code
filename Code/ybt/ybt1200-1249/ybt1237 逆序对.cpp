#include<iostream>
using namespace std;
int n, i, j, a[100001], tmp[100001];
long long sum = 0;//sum数字结果范围比较大，用int不够，必须long long 
//sum记录逆序对数字 
void guibin(int l, int r) //归并排序 
{
	int mid;
	if (l == r) return;
	mid = (l + r) / 2;
	guibin(l, mid);
	guibin(mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
		{
			sum += mid - i + 1;
			tmp[k++] = a[j++];
		}
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= r)
		tmp[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = tmp[i];
	return;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	guibin(1, n);
	cout << sum << endl;
	return 0;
}