#include <bits/stdc++.h>
using namespace std;

/*
    二维差分模板

    作用：
    - 多次给某个子矩阵整体加上一个值
    - 把每次 O(nm) 的矩形修改降到 O(1)
    - 所有修改做完后，再 O(nm) 还原最终矩阵

    核心思想：
    - 对矩形 (x1, y1) ~ (x2, y2) 加 c 时，只改四个角
    - 最后对差分数组做一次二维前缀和，还原最终矩阵

    公式：
    - diff[x1][y1] += c
    - diff[x2 + 1][y1] -= c
    - diff[x1][y2 + 1] -= c
    - diff[x2 + 1][y2 + 1] += c

    习惯：
    - 统一用 1 下标
    - diff 多开一圈，避免访问 x2 + 1 / y2 + 1 越界
*/

void insert_rect(vector<vector<long long>> &diff, int x1, int y1, int x2, int y2, long long c) {
    diff[x1][y1] += c;
    diff[x2 + 1][y1] -= c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y2 + 1] += c;
}

vector<vector<long long>> restore_matrix(vector<vector<long long>> diff) {
    int n = (int)diff.size() - 2;
    int m = (int)diff[0].size() - 2;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            a[i][j] = diff[i][j];
        }
    }

    return a;
}

int main() {
    /*
        最小使用示例：
        输入 n, m, q
        输入原矩阵
        再输入 q 次操作，每次给出 x1, y1, x2, y2, c
        表示给子矩阵全部加 c
        输出最终矩阵

        如果以后只想保留模板函数：
        - 保留 insert_rect / restore_matrix
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> diff(n + 2, vector<long long>(m + 2, 0));

    // 先把原矩阵加入差分数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long x;
            cin >> x;
            insert_rect(diff, i, j, i, j, x);
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        long long c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert_rect(diff, x1, y1, x2, y2, c);
    }

    vector<vector<long long>> ans = restore_matrix(diff);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > 1) cout << ' ';
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
