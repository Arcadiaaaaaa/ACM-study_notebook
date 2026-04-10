#include <bits/stdc++.h>
using namespace std;

/*
    一维差分模板

    作用：
    - 多次给区间 [l, r] 整体加上一个值
    - 把每次 O(n) 的区间修改降到 O(1)
    - 所有修改做完后，再 O(n) 还原最终数组

    核心思想：
    - diff[i] 记录 a[i] 与前一个位置的变化量
    - 给区间 [l, r] 加 c 时：
      diff[l] += c
      diff[r + 1] -= c
    - 最后对 diff 做一次前缀和，就能还原最终数组

    公式：
    - diff[1] = a[1]
    - diff[i] = a[i] - a[i - 1]
    - a[i] = a[i - 1] + diff[i]
*/

void range_add(vector<long long> &diff, int l, int r, long long c) {
    diff[l] += c;
    diff[r + 1] -= c;
}

vector<long long> restore_array(const vector<long long> &diff) {
    int n = (int)diff.size() - 2;
    vector<long long> a(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + diff[i];
    }

    return a;
}

int main() {
    /*
        最小使用示例：
        输入 n, m
        输入原数组 a
        再输入 m 次操作，每次给出 l, r, c
        表示给区间 [l, r] 全部加 c
        输出所有操作后的最终数组

        如果以后只想保留模板函数：
        - 保留 range_add / restore_array
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1), diff(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    diff[1] = a[1];
    for (int i = 2; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    while (m--) {
        int l, r;
        long long c;
        cin >> l >> r >> c;
        range_add(diff, l, r, c);
    }

    vector<long long> ans = restore_array(diff);
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
