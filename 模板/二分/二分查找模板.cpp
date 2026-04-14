#include <bits/stdc++.h>
using namespace std;

/*
    二分查找模板

    使用前提：
    - a[1..n] 已经按升序排好

    常见目标：
    - 第一个 >= x
    - 第一个 > x
    - 最后一个 <= x
    - 最后一个 < x
    - 第一个 == x
    - 最后一个 == x

    习惯：
    - 统一用闭区间 [l, r]
    - mid 写成 l + (r - l) / 2 更稳
    - 找左边界时，满足条件后继续向左收
    - 找右边界时，满足条件后继续向右收
*/

int first_ge(const vector<long long> &a, int n, long long x) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int first_gt(const vector<long long> &a, int n, long long x) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int last_le(const vector<long long> &a, int n, long long x) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int last_lt(const vector<long long> &a, int n, long long x) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int first_equal(const vector<long long> &a, int n, long long x) {
    int pos = first_ge(a, n, x);
    if (pos <= n && a[pos] == x) return pos;
    return -1;
}

int last_equal(const vector<long long> &a, int n, long long x) {
    int pos = last_le(a, n, x);
    if (pos >= 1 && a[pos] == x) return pos;
    return -1;
}

int count_equal(const vector<long long> &a, int n, long long x) {
    int left = first_equal(a, n, x);
    if (left == -1) return 0;
    int right = last_equal(a, n, x);
    return right - left + 1;
}

int main() {
    /*
        最小使用示例：
        输入 n, q
        输入一个已经排好序的数组 a[1..n]
        每次查询一个 x，输出：
        - 第一个等于 x 的位置
        - 最后一个等于 x 的位置
        - x 的出现次数

        如果原数组无序，先排序再二分。
        如果以后只想保留模板函数，可以删除 main。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (q--) {
        long long x;
        cin >> x;

        int left = first_equal(a, n, x);
        int right = last_equal(a, n, x);
        int cnt = count_equal(a, n, x);

        cout << left << ' ' << right << ' ' << cnt << '\n';
    }

    return 0;
}
