#include <bits/stdc++.h>
using namespace std;

/*
    手写进制转换模板

    这一份模板总结竞赛里最常用的两类进制转换：
    1. 十进制 -> k 进制
    2. k 进制 -> 十进制

    常见范围：
    - 二进制：base = 2
    - 八进制：base = 8
    - 十进制：base = 10
    - 十六进制：base = 16

    扩展：
    - 下面的字符映射支持 2 ~ 36 进制
    - 10 ~ 35 分别用 A ~ Z 表示

    核心思路：
    - 十进制转 k 进制：不断除以 base，记录余数，最后翻转
    - k 进制转十进制：从左到右扫，res = res * base + 当前位
*/

char valToChar(int x) {
    if (0 <= x && x <= 9) return char('0' + x);
    return char('A' + (x - 10));
}

int charToVal(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return -1;
}

string decimalToBase(long long n, int base) {
    // 这里只处理 2 ~ 36 进制
    if (base < 2 || base > 36) return "";

    // 0 要单独处理
    if (n == 0) return "0";

    bool neg = false;
    if (n < 0) {
        neg = true;
        n = -n;
    }

    string s;
    while (n > 0) {
        int rem = int(n % base);
        s += valToChar(rem);
        n /= base;
    }

    // 余数是从低位到高位得到的，所以最后要翻转
    reverse(s.begin(), s.end());

    if (neg) s = "-" + s;
    return s;
}

long long baseToDecimal(const string &s, int base) {
    // 这里只处理 2 ~ 36 进制
    if (base < 2 || base > 36) return -1;
    if (s.empty()) return -1;

    int start = 0;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }

    long long res = 0;
    for (int i = start; i < (int)s.size(); i++) {
        int val = charToVal(s[i]);

        // 当前字符不合法，或者该位已经超出 base
        if (val < 0 || val >= base) return -1;

        res = res * base + val;
    }

    return neg ? -res : res;
}

vector<int> decimalToDigits(long long n, int base) {
    /*
        返回从高位到低位的每一位数字
        例如：
        decimalToDigits(13, 2) -> {1, 1, 0, 1}
    */

    vector<int> digits;
    if (base < 2) return digits;

    if (n == 0) {
        digits.push_back(0);
        return digits;
    }

    while (n > 0) {
        digits.push_back(int(n % base));
        n /= base;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int main() {
    /*
        最小使用示例：
        输入一个十进制整数 n 和进制 base
        输出：
        1. n 转成 base 进制后的字符串
        2. 再转回十进制的结果

        如果以后只想保留模板函数，
        可以删除 main，只留下这些转换函数。
    */

    long long n;
    int base;
    cin >> n >> base;

    string converted = decimalToBase(n, base);
    cout << converted << '\n';
    cout << baseToDecimal(converted, base) << '\n';

    return 0;
}
