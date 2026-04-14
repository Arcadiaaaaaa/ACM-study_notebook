#include <bits/stdc++.h>
using namespace std;

/*
    二分答案模板

    核心前提：
    - 答案在区间 [l, r] 内
    - check(mid) 具有单调性

    常见两类：
    1. 求最小可行值
       - 形态通常是：false false false true true true
    2. 求最大可行值
       - 形态通常是：true true true false false false

    注意：
    - 求最小可行值时，mid 取下中位数
    - 求最大可行值时，mid 取上中位数，避免死循环
    - 左右边界、mid、答案通常优先开 long long
*/

template <class Check>
long long binary_search_min(long long l, long long r, Check check) {
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

template <class Check>
long long binary_search_max(long long l, long long r, Check check) {
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    /*
        最小使用示例：
        输入一个非负整数 n
        输出：
        - 最小的 x，使得 x * x >= n
        - 最大的 x，使得 x * x <= n

        真正做题时，通常只保留上面的模板函数，
        然后把 check(mid) 改成题目的可行性判断。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long r = max(1LL, n);

    auto check_min = [&](long long mid) {
        return (__int128)mid * mid >= n;
    };

    auto check_max = [&](long long mid) {
        return (__int128)mid * mid <= n;
    };

    cout << binary_search_min(0, r, check_min) << '\n';
    cout << binary_search_max(0, r, check_max) << '\n';

    return 0;
}
