#include <bits/stdc++.h>
using namespace std;

/*
    DFS 回溯生成全排列模板

    作用：
    - 枚举 1..n 的所有排列
    - 学习搜索树和回溯的基本写法

    核心思想：
    - path 表示当前已经选了哪些数
    - used[i] 表示数字 i 是否已经被放进排列
    - 选一个数、递归、撤销选择，这就是回溯

    适用场景：
    - 全排列
    - 子集 / 组合 / 排列型搜索
    - 需要枚举所有方案并判断是否合法
*/

int n;
vector<int> path;
vector<int> used;

void dfs() {
    if ((int)path.size() == n) {
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << '\n';
        return;
    }

    for (int x = 1; x <= n; x++) {
        if (used[x]) continue;

        used[x] = 1;
        path.push_back(x);

        dfs();

        path.pop_back();
        used[x] = 0;
    }
}

int main() {
    /*
        最小使用示例：
        输入 n
        输出 1..n 的所有排列

        如果以后只想保留模板函数：
        - 保留 n / path / used / dfs
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    used.assign(n + 1, 0);
    dfs();

    return 0;
}
