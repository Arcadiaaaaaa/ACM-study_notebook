#include <bits/stdc++.h>
using namespace std;

/*
    高精度乘法模板

    适用：
    - 非负大整数 * 非负大整数
    - 数字长度超过 long long 范围

    核心思想：
    - 模拟竖式乘法
    - a 的第 i 位乘 b 的第 j 位，贡献到结果第 i + j 位
*/

string strip_leading_zeros(string s) {
    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}

string multiply_big(string a, string b) {
    a = strip_leading_zeros(a);
    b = strip_leading_zeros(b);

    if (a == "0" || b == "0") return "0";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> c(a.size() + b.size(), 0);

    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b.size(); j++) {
            c[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = 0; i + 1 < (int)c.size(); i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    while (c.size() > 1 && c.back() == 0) c.pop_back();

    string ans;
    for (int i = (int)c.size() - 1; i >= 0; i--) {
        ans.push_back(char(c[i] + '0'));
    }

    return ans;
}

int main() {
    /*
        输入两个非负大整数 a, b
        输出 a * b

        如果以后只想保留模板函数，可以删除 main。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << multiply_big(a, b) << '\n';

    return 0;
}
