#include <bits/stdc++.h>
using namespace std;

/*
    BFS 图最短路模板

    作用：
    - 求无权图中起点到所有点的最短步数

    核心思想：
    - BFS 按层扩展
    - 第一次到达某个点时，走的就是最短路
    - dist[v] = dist[u] + 1

    适用场景：
    - 无权图最短路
    - 最少边数问题
    - 从一个起点做层序扩展
*/

vector<vector<int>> g;
vector<int> distv;

void bfs(int s) {
    queue<int> q;
    distv[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (distv[v] != -1) continue;
            distv[v] = distv[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    /*
        最小使用示例：
        输入 n, m, s
        接下来 m 条无向边 u, v
        输出起点 s 到 1..n 的最短距离
        不可达输出 -1

        如果以后只想保留模板函数：
        - 保留 g / distv / bfs
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    g.assign(n + 1, vector<int>());
    distv.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(s);

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << distv[i];
    }
    cout << '\n';

    return 0;
}
