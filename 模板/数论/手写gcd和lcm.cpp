#include <bits/stdc++.h>
using namespace std;

/*
    gcd 和 lcm 竞赛模板

    gcd(a, b)：
    - greatest common divisor
    - 最大公约数

    lcm(a, b)：
    - least common multiple
    - 最小公倍数

    核心关系：
    - gcd(a, b) * lcm(a, b) = |a * b|

    竞赛里最常用的是欧几里得算法：
    gcd(a, b) = gcd(b, a % b)

    当 b == 0 时：
    - gcd(a, 0) = |a|

    注意点：
    1. gcd / lcm 常用 long long
    2. lcm 不要直接写成 a * b / gcd(a, b)
       因为 a * b 可能先溢出
    3. 更稳的写法是 a / gcd(a, b) * b
    4. 如果题目可能出现负数，先取绝对值更稳
*/

long long gcd_ll(long long a, long long b) {
    // 如果题目里可能出现负数，先转成非负
    a = llabs(a);
    b = llabs(b);

    // 递归终点：
    // 当 b 为 0 时，当前的 a 就是最大公约数
    if (b == 0) return a;

    // 欧几里得算法
    return gcd_ll(b, a % b);
}

long long lcm_ll(long long a, long long b) {
    // 只要有一个数是 0，最小公倍数就是 0
    if (a == 0 || b == 0) return 0;

    // 这里先除后乘，减少中间溢出的风险
    return llabs(a / gcd_ll(a, b) * b);
}

int main() {
    /*
        最小使用示例：
        输入两个整数 a, b
        输出它们的 gcd 和 lcm

        如果以后只想保留模板函数，
        可以删除 main，只留下 gcd_ll 和 lcm_ll。
    */

    long long a, b;
    cin >> a >> b;

    cout << "gcd = " << gcd_ll(a, b) << '\n';
    cout << "lcm = " << lcm_ll(a, b) << '\n';

    return 0;
}
