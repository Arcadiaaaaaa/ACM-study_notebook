#include <bits/stdc++.h>
using namespace std;

/*
    高精度减法模板

    适用：
    - 非负大整数 - 非负大整数
    - 结果可能为负数

    核心思想：
    - 先比较绝对值大小
    - 用大数减小数
    - 从低位到高位逐位相减，不够就向高位借位
*/

string strip_leading_zeros(string s) {
    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}

int compare_abs(string a, string b) {
    a = strip_leading_zeros(a);
    b = strip_leading_zeros(b);

    if (a.size() != b.size()) {
        return a.size() < b.size() ? -1 : 1;
    }
    if (a == b) return 0;
    return a < b ? -1 : 1;
}

string subtract_abs(string a, string b) {
    // 要求 a >= b，返回非负结果 a - b
    a = strip_leading_zeros(a);
    b = strip_leading_zeros(b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans;
    int borrow = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        int x = a[i] - '0' - borrow;
        int y = (i < (int)b.size()) ? b[i] - '0' : 0;

        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans.push_back(char(x - y + '0'));
    }

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

string subtract_big(string a, string b) {
    int cmp = compare_abs(a, b);
    if (cmp == 0) return "0";
    if (cmp > 0) return subtract_abs(a, b);
    return "-" + subtract_abs(b, a);
}

int main() {
    /*
        输入两个非负大整数 a, b
        输出 a - b

        如果以后只想保留模板函数，可以删除 main。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << subtract_big(a, b) << '\n';

    return 0;
}
