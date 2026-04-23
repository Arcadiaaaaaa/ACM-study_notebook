#include <bits/stdc++.h>
using namespace std;

/*
    高精度加法模板

    适用：
    - 非负大整数 + 非负大整数
    - 数字长度超过 long long 范围

    核心思想：
    - 从低位到高位逐位相加
    - 用 carry 维护进位
*/

string strip_leading_zeros(string s) {
    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}

string add_big(string a, string b) {
    a = strip_leading_zeros(a);
    b = strip_leading_zeros(b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans;
    int carry = 0;
    int n = max(a.size(), b.size());

    for (int i = 0; i < n || carry; i++) {
        int sum = carry;
        if (i < (int)a.size()) sum += a[i] - '0';
        if (i < (int)b.size()) sum += b[i] - '0';

        ans.push_back(char(sum % 10 + '0'));
        carry = sum / 10;
    }

    reverse(ans.begin(), ans.end());
    return strip_leading_zeros(ans);
}

int main() {
    /*
        输入两个非负大整数 a, b
        输出 a + b

        如果以后只想保留模板函数，可以删除 main。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << add_big(a, b) << '\n';

    return 0;
}
