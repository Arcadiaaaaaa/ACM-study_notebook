#include <bits/stdc++.h>
using namespace std;

/*
    欧拉筛模板（线性筛）

    作用：
    - 求出 1 ~ n 之间的所有素数
    - 同时得到一个合数标记表

    核心思想：
    1. 从小到大枚举每个数 i
    2. 如果 i 没被标记，说明 i 是素数，把它放进 primes
    3. 用当前的 i 去乘已经找到的素数 p，得到合数 i * p
    4. 每个合数只会被它的最小质因子筛掉一次，所以叫线性筛

    为什么是线性的：
    - 对每个合数，只会在“最小质因子”这一层被标记一次
    - 因此总标记次数与 n 同阶

    时间复杂度：
    - O(n)

    适用场景：
    - 数据范围更大，需要更高效地筛素数
    - 需要在线性筛基础上扩展最小质因子、欧拉函数等信息
*/

const int N = 1000005;

vector<int> pri;
bool not_prime[N];

void pre(int n) {
    // 如果一个测试点中会重复调用筛法，
    // 要先把之前留下的数据清空
    pri.clear();
    fill(not_prime, not_prime + n + 1, false);

    // 从 2 开始枚举到 n
    for (int i = 2; i <= n; i++) {
        // 没有被标记为合数，说明 i 是素数
        if (!not_prime[i]) {
            pri.push_back(i);
        }

        // 用当前 i 去乘之前已经找到的每个素数
        for (int pri_j : pri) {
            // 乘积超出筛的范围，就没有必要继续了
            if (1LL * i * pri_j > n) break;

            // i * pri_j 一定是合数
            not_prime[i * pri_j] = true;

            // 如果 i 能被 pri_j 整除，说明 pri_j 是 i 的最小质因子
            if (i % pri_j == 0) {
                /*
                    i % pri_j == 0
                    换言之，i 之前已经被 pri_j 筛过了

                    由于 pri 里面的质数是从小到大枚举的，
                    那么 i 再乘上后面的质数得到的合数，
                    一定会在别的位置由“更小的最小质因子”负责筛掉

                    所以这里直接 break，
                    就能保证每个合数只被它的最小质因子筛一次
                */
                break;
            }
        }
    }
}

int main() {
    /*
        最小使用示例：
        输入一个 n，输出 1 ~ n 内所有素数。

        如果以后只想保留模板函数，
        可以删除 main，只留下常量、全局数组和 pre。
    */

    int n;
    cin >> n;

    pre(n);

    for (int i = 0; i < (int)pri.size(); i++) {
        if (i) cout << ' ';
        cout << pri[i];
    }
    cout << '\n';

    return 0;
}
