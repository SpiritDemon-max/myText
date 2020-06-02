#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int n, m, match;
int c[maxn][maxn],col[maxn];
int sum = 0;
bool Same(int t) {
    for (int i = 1; i <= n; ++i) {
        if (c[t][i] == 1 && col[i] == col[t])
            return false;
    }
    return true;
}
void BackTrack(int t) {
    if (t > n) {
        sum++;
        for (int i = 1; i <= n; ++i)
            printf("%d ", col[i]);
        printf("\n");
    }
    else {
        for (int i = 1; i <= m; ++i) {
            col[t] = i;
            if (Same(t))BackTrack(t + 1);
            col[t] = 0;
        }
    }
}
int main() {
    scanf("%d", &m);
    scanf("%d %d", &n, &match);
    for (int i = 1; i <= match; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        c[x][y] = c[y][x] = 1;
    }
    BackTrack(1);
    if (sum == 0) printf("NO\n");
 else printf("%d\n", sum);
}
