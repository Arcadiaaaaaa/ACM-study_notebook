#include <bits/stdc++.h>
using namespace std;

/*
    一维前缀和模板

    作用：
    - 快速求数组任意区间 [l, r] 的元素和
    - 把每次 O(n) 的区间求和降到 O(1)

    核心思想：
    - s[i] 表示前 i 个数的和
    - 那么区间 [l, r] 的和就是 s[r] - s[l - 1]

    公式：
    - s[i] = s[i - 1] + a[i]
    - sum(l, r) = s[r] - s[l - 1]

    习惯：
    - 统一用 1 下标，公式最整齐
    - 如果元素和可能很大，前缀和要开 long long
*/

vector<long long> build_prefix_sum(const vector<long long> &a) {
    int n = (int)a.size() - 1;
    vector<long long> s(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    return s;
}

long long range_sum(const vector<long long> &s, int l, int r) {
    return s[r] - s[l - 1];
}

int main() {
    /*
        最小使用示例：
        输入 n, q
        输入长度为 n 的数组
        再输入 q 次查询，每次给出 l, r
        输出每个区间和

        如果以后只想保留模板函数：
        - 保留 build_prefix_sum / range_sum
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long long> s = build_prefix_sum(a);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << range_sum(s, l, r) << '\n';
    }

    return 0;
}
