#include <bits/stdc++.h>
using namespace std;

/*
    高精度除法模板

    适用：
    - 非负大整数 / 非负大整数
    - 返回商和余数

    核心思想：
    - 模拟十进制竖式除法
    - 每次把下一位放到当前余数后面
    - 当前位的商只会是 0 到 9，可以直接试减

    注意：
    - 除数不能为 0
    - 如果只是高精度除以 int，可以写得更短；这个模板更通用
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

pair<string, string> divide_big(string a, string b) {
    a = strip_leading_zeros(a);
    b = strip_leading_zeros(b);

    if (b == "0") {
        throw invalid_argument("division by zero");
    }
    if (compare_abs(a, b) < 0) {
        return {"0", a};
    }

    string quotient;
    string remainder = "0";

    for (char ch : a) {
        if (remainder == "0") {
            remainder = string(1, ch);
        } else {
            remainder.push_back(ch);
        }
        remainder = strip_leading_zeros(remainder);

        int digit = 0;
        while (compare_abs(remainder, b) >= 0) {
            remainder = subtract_abs(remainder, b);
            digit++;
        }

        quotient.push_back(char(digit + '0'));
    }

    return {strip_leading_zeros(quotient), strip_leading_zeros(remainder)};
}

int main() {
    /*
        输入两个非负大整数 a, b
        输出：
        - a / b 的商
        - a / b 的余数

        如果以后只想保留模板函数，可以删除 main。
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (strip_leading_zeros(b) == "0") {
        cout << "division by zero\n";
        return 0;
    }

    auto [quotient, remainder] = divide_big(a, b);
    cout << quotient << '\n';
    cout << remainder << '\n';

    return 0;
}
