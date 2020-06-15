#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
const double inf = 0x3f3f3f3f;
double minn = inf;              //最小圆排列长度
int n;
double x[maxn], r[maxn];             //分别为每个圆心横坐标，每个圆半径
double arr[maxn];                //最小圆排列的半径顺序

double Getc(int t) {         //计算第t个圆的圆心坐标
    double temp = 0;
    for (int j = 1; j < t; ++j) {
        double val = x[j] + 2.0 * sqrt(r[t] * r[j]);  //判断与他之前的所有圆相切的情况
        temp=max(temp,val);
    }
    return temp;
}
void compute() {
    double L = inf, R = 0;   //L是左边界，R是有边界
    for (int i = 1; i <= n; ++i) {
        if (x[i] - r[i] < L)
            L = x[i] - r[i];
        if (x[i] + r[i] > R)
            R = x[i] + r[i];
    }
    if (R - L < minn) {
        minn = R - L;
        for (int i = 1; i <= n; ++i)
            arr[i] = r[i];
    }
}
void dfs(int t) {
    if (t == n + 1) {
        compute();
    }
    else {
        for (int j = t; j <= n; ++j) {
            swap(r[t], r[j]);
            double val = Getc(t);
            if (val + r[t] + r[1] < minn) {
                x[t] = val;
                dfs(t + 1);
            }
            swap(r[t], r[j]);     //还原
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)scanf("%lf", &r[i]);
    dfs(1);
    printf("最小圆排列长度为：%.4f\n", minn);
    printf("最小圆排列的顺序对应的半径分别为：\n");
    for (int i = 1; i <= n; ++i) {
        printf("%.4f%c", arr[i],i==n?'\n':' ');
    }
    return 0;
}
