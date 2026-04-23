#include <bits/stdc++.h>
using namespace std;

/*
    DFS 图遍历与连通块模板

    作用：
    - 遍历无向图
    - 统计连通块个数
    - 求每个连通块的大小

    核心思想：
    - 从某个还没访问过的点出发
    - 沿着边一直递归往下搜
    - 一次 DFS 能覆盖整个连通块

    适用场景：
    - 无向图连通性
    - 连通块计数
    - 图上可达点统计
*/

vector<vector<int>> g;
vector<int> vis;
int component_size;

void dfs(int u) {
    vis[u] = 1;
    component_size++;

    for (int v : g[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

int main() {
    /*
        最小使用示例：
        输入 n, m
        接下来 m 条无向边 u, v
        输出：
        - 连通块个数
        - 每个连通块的大小

        如果以后只想保留模板函数：
        - 保留 g / vis / component_size / dfs
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sizes;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        component_size = 0;
        dfs(i);
        sizes.push_back(component_size);
    }

    cout << sizes.size() << '\n';
    for (int x : sizes) {
        cout << x << '\n';
    }

    return 0;
}
