#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1000005], n, k, lh = 1, lt = 0, p[1000005];
int main()
{
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {//������������, �����ҽ����ڵ�λ��
        while (lh <= lt/*�Ӳ���*/ && a[p[lt]] >= a[i]/*��β���ڵ�ǰ�ڵ�,�ʶ�β֮�󲻿�����С*/) {
            lt--;//�ʵ�����β
        }
        p[++lt] = i;//��Ϊ����Ԫ��δ֪, ���ּ���a[i];
        while (p[lh] <= i - k) {//�������, �Ѿ�����
            lh++;
        }
        if (i >= k) {//��һ�������ҽ���k,�ڴ�֮ǰ�����
            printf("%d ", a[p[lh]]);//��������, ���Զ�����С
        }
    }
    cout << endl;
    lh = 1;
    lt = 0;//��ն���
    for (int i = 1; i <= n; ++i) {//�ݼ�����
        while (lh <= lt && a[p[lt]] <= a[i]/*������Ԫ�ظ���, ��ô��β�����������*/) {
            lt--;//������β
        }
        p[++lt] = i;//������Ԫ��
        while (p[lh] <= i - k) {
            lh++;
        }
        if (i >= k) {
            printf("%d ", a[p[lh]]);//�����ݼ�, ���׾���Ҫ�ҵ����ֵ
        }
    }
    cout << endl;
    return 0;
}