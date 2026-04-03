#include <bits/stdc++.h>
using namespace std;

/*
    常用排序函数模板

    这一份模板总结竞赛里最常用的排序相关函数：
    1. sort
    2. stable_sort
    3. partial_sort
    4. nth_element
    5. 自定义比较器（普通函数 / lambda / 多关键字）

    记忆重点：
    - sort：普通排序，速度快，默认不稳定
    - stable_sort：稳定排序，值相等时保持原相对顺序
    - partial_sort：只关心前 k 小 / 前 k 大时使用
    - nth_element：只关心第 k 小位置时使用

    比较器规则：
    - 如果 cmp(a, b) 返回 true，表示 a 应该排在 b 前面
    - 比较器不要写成 <= 或 >=
    - 相等时要保证规则一致
*/

struct Node {
    int score;
    int id;
    string name;
};

// 整数从大到小排序
bool cmp_desc(int a, int b) {
    return a > b;
}

// 多关键字排序：
// 先按 score 降序，再按 id 升序
bool cmp_node(const Node &a, const Node &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    /*
        这一份 main 只是演示写法，保证模板文件可直接编译运行。
        真正比赛时，通常只保留需要的那几行写法即可。
    */

    vector<int> a = {5, 1, 4, 1, 3};

    // 1. sort：默认升序
    sort(a.begin(), a.end());

    // 2. sort + 自定义比较函数：降序
    sort(a.begin(), a.end(), cmp_desc);

    // 3. sort + lambda：按绝对值升序
    sort(a.begin(), a.end(), [](int x, int y) {
        if (abs(x) != abs(y)) return abs(x) < abs(y);
        return x < y;
    });

    vector<pair<int, int>> vp = {{1, 3}, {1, 2}, {2, 1}, {2, 5}};

    // 4. pair 多关键字排序：
    // first 升序，first 相等时 second 降序
    sort(vp.begin(), vp.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    vector<Node> students = {
        {90, 2, "Alice"},
        {90, 1, "Bob"},
        {85, 3, "Carol"}
    };

    // 5. 结构体多关键字排序
    sort(students.begin(), students.end(), cmp_node);

    vector<pair<int, char>> stable_demo = {
        {2, 'A'},
        {1, 'B'},
        {2, 'C'},
        {1, 'D'}
    };

    // 6. stable_sort：
    // 按 first 升序，但 first 相等时保留原本顺序
    // 结果中 (1, 'B') 仍会排在 (1, 'D') 前面
    stable_sort(stable_demo.begin(), stable_demo.end(),
        [](const pair<int, char> &x, const pair<int, char> &y) {
            return x.first < y.first;
        }
    );

    vector<int> b = {7, 2, 9, 1, 5, 3, 8};

    // 7. partial_sort：
    // 排完后，前 3 个位置一定是最小的 3 个数，并且这 3 个数内部有序
    partial_sort(b.begin(), b.begin() + 3, b.end());

    vector<int> c = {7, 2, 9, 1, 5, 3, 8};

    // 8. nth_element：
    // 让第 3 小的元素放到下标 2 位置
    // 这个位置左边都 <= 它，右边都 >= 它，但左右两边内部不保证有序
    nth_element(c.begin(), c.begin() + 2, c.end());

    cout << "sort template ready\n";
    return 0;
}
