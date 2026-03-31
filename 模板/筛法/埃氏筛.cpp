#include <bits/stdc++.h>
using namespace std;

/*
    埃氏筛模板（Eratosthenes Sieve）

    作用：
    - 求出 1 ~ n 之间的所有素数
    - 同时得到一个判定表，方便快速判断某个数是不是合数

    核心思想：
    1. 从小到大枚举每个数 i
    2. 如果 i 还没有被标记，说明 i 是素数
    3. 用 i 去筛掉它的倍数

    为什么可以从 i * i 开始筛：
    - 因为比 i * i 小的倍数，例如 2 * i、3 * i、4 * i
      在更小的质因子那里已经被筛过了
    - 这样可以减少重复标记

    时间复杂度：
    - 大约是 O(n log log n)

    适用场景：
    - 需要快速求出某个范围内所有素数
    - 需要多次判断一个数是否为素数
*/

// 素数
vector<int> primes;
// 合数
vector<bool> is_composite;

void eratosthenes(int n) {
    // 大小开到 n + 1，方便直接用下标表示数字本身
    is_composite.assign(n + 1, false);
    // 0 和 1 不是素数，直接标记为合数
    if (n >= 0) is_composite[0] = true;
    if (n >= 1) is_composite[1] = true;
    primes.clear();

    // 0 和 1 不是素数，这里不加入 primes
    for (int i = 2; i <= n; i++) {
        // 没被标记过，说明 i 是素数
        if (!is_composite[i]) {
            primes.push_back(i);

            // 如果 i * i 已经大于 n，
            // 那么继续标记倍数就没有意义了
            if (1LL * i * i > n) continue;

            // 从 i * i 开始筛掉 i 的倍数
            for (long long j = 1LL * i * i; j <= n; j += i) {
                is_composite[(int)j] = true;
            }
        }
    }
}

int main() {
    /*
        最小使用示例：
        输入一个 n，输出 1 ~ n 内所有素数。

        如果以后只想保留模板函数，
        可以删除 main，只留下全局数组和 eratosthenes。
    */

    int n;
    cin >> n;

    eratosthenes(n);

    for (int i = 0; i < (int)primes.size(); i++) {
        if (i) cout << ' ';
        cout << primes[i];
    }
    cout << '\n';

    return 0;
}
