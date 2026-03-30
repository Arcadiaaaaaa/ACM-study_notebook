#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    vector<int> A, B, C;

    // 倒序存储，每一位单独放进数组
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    int t = 0; // 进位
    for (int i = 0; i < (int)max(A.size(), B.size()) || t; i++) {
        if (i < (int)A.size()) t += A[i];
        if (i < (int)B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    // 倒着输出结果
    string ans;
    for (int i = C.size() - 1; i >= 0; i--) ans += char(C[i] + '0');
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << '\n';
    return 0;
}