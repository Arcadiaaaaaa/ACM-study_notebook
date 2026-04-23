#include <bits/stdc++.h>
using namespace std;

/*
    BFS 网格最短路模板

    作用：
    - 求网格中从 S 到 E 的最短步数
    - '#' 表示障碍，不能走
    - 每次只能上下左右走一格

    核心思想：
    - 把每个格子看成图上的一个点
    - BFS 一层一层扩展
    - 第一次到达终点时就是最短路

    适用场景：
    - 迷宫最短路
    - 网格最少步数
    - 四联通最短路
*/

struct Node {
    int x, y;
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    /*
        最小使用示例：
        输入 n, m
        接下来 n 行网格
        字符含义：
        - 'S'：起点
        - 'E'：终点
        - '.'：空地
        - '#'：障碍

        输出从 S 到 E 的最短步数
        如果不可达，输出 -1
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    Node start{-1, -1}, target{-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'E') target = {i, j};
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Node> q;
    dist[start.x][start.y] = 0;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[target.x][target.y] << '\n';

    return 0;
}
