#include <bits/stdc++.h>
using namespace std;

/*
    哈希表模板：动态统计是否出现、出现次数、第一次位置、最后一次位置

    适用场景：
    - 需要动态记录某个值有没有出现过
    - 需要统计某个值出现了几次
    - 需要记录某个值第一次 / 最后一次出现的位置
    - 值本身不是连续的小范围整数，不能直接拿来当数组下标

    核心结构：
    - 用 unordered_map<Key, Info> 做哈希表
    - Key 是值本身
    - Info 记录这个值的统计信息

    复杂度：
    - 插入 / 查询：平均 O(1)
    - 最坏情况理论上可能退化，但竞赛里通常够用

    使用提醒：
    - 如果键是 long long / string，这份模板可以直接改
    - 如果键是 pair、自定义结构体，需要自己补哈希函数
    - 如果还需要按键有序遍历，应该改用 map
*/

using Key = long long;  // 如果题目里值是 string，可以改成 using Key = string;

struct Info {
    int cnt = 0;
    int first_pos = -1;
    int last_pos = -1;
};

unordered_map<Key, Info> mp;

void init_hash_table(int expected_size = 0) {
    mp.clear();

    // 预留空间能减少 rehash 次数，数据量较大时更稳一些
    if (expected_size > 0) {
        mp.reserve(expected_size * 2);
    }
    mp.max_load_factor(0.7f);
}

void add_value(const Key &x, int pos) {
    auto it = mp.find(x);
    if (it == mp.end()) {
        mp[x] = {1, pos, pos};
    } else {
        it->second.cnt++;
        it->second.last_pos = pos;
    }
}

bool has_value(const Key &x) {
    return mp.find(x) != mp.end();
}

int get_count(const Key &x) {
    auto it = mp.find(x);
    if (it == mp.end()) return 0;
    return it->second.cnt;
}

int get_first_pos(const Key &x) {
    auto it = mp.find(x);
    if (it == mp.end()) return -1;
    return it->second.first_pos;
}

int get_last_pos(const Key &x) {
    auto it = mp.find(x);
    if (it == mp.end()) return -1;
    return it->second.last_pos;
}

Info get_info(const Key &x) {
    auto it = mp.find(x);
    if (it == mp.end()) return Info{};
    return it->second;
}

int main() {
    /*
        最小使用示例：
        输入 n
        输入 n 个数，按下标 1 ~ n 依次加入哈希表
        再输入 q
        接下来 q 次查询，每次给一个值 x

        对每次查询输出：
        - 是否出现过
        - 出现次数
        - 第一次出现位置
        - 最后一次出现位置

        如果以后只想保留模板函数：
        - 保留 Info / mp / init_hash_table / add_value / has_value
        - 保留 get_count / get_first_pos / get_last_pos / get_info
        - main 可以删除
    */

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    init_hash_table(n);

    for (int i = 1; i <= n; i++) {
        Key x;
        cin >> x;
        add_value(x, i);
    }

    int q;
    cin >> q;

    while (q--) {
        Key x;
        cin >> x;

        if (!has_value(x)) {
            cout << "NO 0 -1 -1\n";
        } else {
            cout << "YES "
                 << get_count(x) << ' '
                 << get_first_pos(x) << ' '
                 << get_last_pos(x) << '\n';
        }
    }

    return 0;
}
