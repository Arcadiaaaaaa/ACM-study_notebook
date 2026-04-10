#include <bits/stdc++.h>
using namespace std;

/*
    数组模拟双向链表模板

    作用：
    - 用数组下标模拟节点指针
    - 支持 O(1) 在已知节点编号处插入、删除
    - 支持 O(n) 按值查找

    核心结构：
    - e[i]：节点 i 存的值
    - l[i]：节点 i 左边是谁
    - r[i]：节点 i 右边是谁
    - 0：头哨兵
    - 1：尾哨兵

    复杂度：
    - 左插 / 右插 / 删除：O(1)
    - 按值查找：O(n)

    适用场景：
    - 题目要求模拟链表
    - 频繁中间插入、删除
    - 已知节点编号时需要快速操作
*/

const int N = 200010;  // 按题目需要调整

int e[N], l[N], r[N], idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

int insert_right(int k, int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    return idx++;
}

int insert_left(int k, int x) {
    return insert_right(l[k], x);
}

int push_front(int x) {
    return insert_right(0, x);
}

int push_back(int x) {
    return insert_left(1, x);
}

void remove_node(int k) {
    if (k == 0 || k == 1) return;  // 不删除哨兵
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int find_first(int x) {
    for (int i = r[0]; i != 1; i = r[i]) {
        if (e[i] == x) return i;
    }
    return -1;
}

void print_list() {
    bool first = true;
    for (int i = r[0]; i != 1; i = r[i]) {
        if (!first) cout << ' ';
        cout << e[i];
        first = false;
    }
    cout << '\n';
}

int main() {
    /*
        最小使用示例：
        输入 q，接下来 q 行操作

        支持命令：
        - L x      ：在最左边插入 x
        - R x      ：在最右边插入 x
        - IL k x   ：在编号为 k 的节点左边插入 x
        - IR k x   ：在编号为 k 的节点右边插入 x
        - D k      ：删除编号为 k 的节点
        - F x      ：查找值为 x 的第一个节点编号，不存在输出 -1
        - P        ：输出当前链表

        注意：
        - 这里的 k 是“节点编号”，不是当前位置
        - 如果题目给的是“第 k 次插入的点”，通常可以直接把那个编号当作节点编号使用

        如果以后只想保留模板函数：
        - 保留 init / insert_right / insert_left / remove_node / find_first / print_list
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int q;
    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "L") {
            int x;
            cin >> x;
            push_front(x);
        } else if (op == "R") {
            int x;
            cin >> x;
            push_back(x);
        } else if (op == "IL") {
            int k, x;
            cin >> k >> x;
            insert_left(k, x);
        } else if (op == "IR") {
            int k, x;
            cin >> k >> x;
            insert_right(k, x);
        } else if (op == "D") {
            int k;
            cin >> k;
            remove_node(k);
        } else if (op == "F") {
            int x;
            cin >> x;
            cout << find_first(x) << '\n';
        } else if (op == "P") {
            print_list();
        }
    }

    return 0;
}
