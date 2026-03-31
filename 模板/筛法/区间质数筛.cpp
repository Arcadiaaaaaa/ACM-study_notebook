#include <bits/stdc++.h>
using namespace std;

/*
    区间质数筛模板（Segmented Sieve）

    作用：
    - 求出区间 [L, R] 内的所有质数
    - 当 R 很大、但区间长度 R - L 不大时非常好用

    核心思想：
    1. 先用普通筛法筛出 1 ~ sqrt(R) 内的所有质数
    2. 用这些质数去筛区间 [L, R] 中的合数
    3. 区间里没有被标记的位置，就是质数

    为什么只筛到 sqrt(R)？
    - 如果一个合数 x 不是质数，那么它一定存在一个不超过 sqrt(x) 的质因子
    - 因为 x <= R，所以筛出 sqrt(R) 以内的质数就够了

    每个质数 p 从哪里开始筛？
    - 起点至少要是区间内第一个 p 的倍数，也就是 ceil(L / p) * p
    - 但还要保证起点不小于 p * p
    - 因为如果一个 p 的倍数小于 p * p，那么它可以写成 p * k，且 k < p
    - 这说明这个数还含有一个更小的因子，所以它更早就会被更小的质数筛掉
    - 因此起点应取 max(p * p, ceil(L / p) * p)
    - 这样既不会漏筛，也不会把质数 p 自己误标成合数

    时间复杂度：
    - 预处理小质数：O(sqrt(R) log log sqrt(R))
    - 筛区间：[L, R] 长度为 len 时，大约是 O(len log log R)

    适用场景：
    - L, R 很大，但 R - L 不大
    - 例如：1 <= L <= R < 2^31，且 R - L <= 10^6
*/

// sqrt(R) 以内的质数
vector<int> base_primes;
// 小范围普通筛时的合数标记
vector<bool> is_composite_small;
// 区间 [L, R] 上的合数标记
vector<bool> is_composite_range;

int get_sqrt_limit(long long r) {
    int limit = (int)sqrt((long double)r);

    // 修正浮点误差，保证 limit = floor(sqrt(r))
    while (1LL * (limit + 1) * (limit + 1) <= r) limit++;
    while (1LL * limit * limit > r) limit--;

    return limit;
}

void eratosthenes(int n) {
    is_composite_small.assign(n + 1, false);
    if (n >= 0) is_composite_small[0] = true;
    if (n >= 1) is_composite_small[1] = true;
    base_primes.clear();

    for (int i = 2; i <= n; i++) {
        if (!is_composite_small[i]) {
            base_primes.push_back(i);

            if (1LL * i * i > n) continue;
            for (long long j = 1LL * i * i; j <= n; j += i) {
                is_composite_small[(int)j] = true;
            }
        }
    }
}

vector<long long> segmented_sieve(long long L, long long R) {
    int len = (int)(R - L + 1);
    is_composite_range.assign(len, false);

    int limit = get_sqrt_limit(R);
    eratosthenes(limit);

    for (int p : base_primes) {
        // 从 max(p * p, ceil(L / p) * p) 开始筛，避免漏筛和误筛 p 自己
        long long start = max(1LL * p * p, (L + p - 1) / p * 1LL * p);

        for (long long x = start; x <= R; x += p) {
            is_composite_range[(int)(x - L)] = true;
        }
    }

    // 0 和 1 不是质数，落在区间里时要单独处理
    for (long long x = max(L, 0LL); x <= min(R, 1LL); x++) {
        is_composite_range[(int)(x - L)] = true;
    }

    vector<long long> primes_in_range;
    for (int i = 0; i < len; i++) {
        if (!is_composite_range[i]) {
            primes_in_range.push_back(L + i);
        }
    }

    return primes_in_range;
}

int main() {
    /*
        P1835 素数密度的直接用法：
        输入 L, R，输出区间 [L, R] 内质数个数

        如果以后只想保留模板函数：
        - 保留 get_sqrt_limit / eratosthenes / segmented_sieve
        - main 可以直接删掉
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R;
    cin >> L >> R;

    vector<long long> primes_in_range = segmented_sieve(L, R);
    cout << primes_in_range.size() << '\n';

    return 0;
}
