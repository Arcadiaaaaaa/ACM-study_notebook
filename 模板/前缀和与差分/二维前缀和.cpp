#include <bits/stdc++.h>
using namespace std;

/*
    二维前缀和模板

    作用：
    - 快速求任意子矩阵的元素和
    - 矩阵不变、查询很多时非常常用
    - 把每次 O(nm) 的区域求和降到 O(1)

    核心思想：
    - s[i][j] 表示从左上角 (1, 1) 到 (i, j) 的矩形和

    公式：
    - s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]
    - sum(x1, y1, x2, y2)
      = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]

    习惯：
    - 统一用 1 下标
    - s 多开一行一列，方便处理第 0 行和第 0 列
*/

vector<vector<long long>> build_prefix_sum_2d(const vector<vector<long long>> &a) {
    int n = (int)a.size() - 1;
    int m = (int)a[0].size() - 1;

    vector<vector<long long>> s(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    return s;
}

long long rect_sum(const vector<vector<long long>> &s, int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main() {
    /*
        最小使用示例：
        输入 n, m, q
        输入 n 行 m 列矩阵
        再输入 q 次查询，每次给出 x1, y1, x2, y2
        输出每个子矩阵的元素和

        如果以后只想保留模板函数：
        - 保留 build_prefix_sum_2d / rect_sum
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> s = build_prefix_sum_2d(a);

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << rect_sum(s, x1, y1, x2, y2) << '\n';
    }

    return 0;
}
