# C++竞赛语法与 STL 速查

这一页只做赛前快速回看，不代替详细笔记。

更完整的内容：
- 输入输出与基础语法：[`输入输出与语法`](./输入输出与语法.md)
- 容器与常用算法：[`STL 容器与常用算法`](../数据结构与STL/STL容器与常用算法.md)
- 数学常识与位运算：[`数学基础`](../数学/数学基础.md)
- 字符串：[`字符串`](../字符串/字符串.md)

## 1. 输入输出

竞赛 IO 加速：

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

小数位数：

```cpp
cout << fixed << setprecision(2) << x;
```

整行输入：

```cpp
getline(cin, s);
```

注意：
- `cin >> s` 读到空格就停。
- 前面如果刚读完数字，再 `getline` 前要处理残留换行。
- 开了流加速后，尽量不要和 `scanf/printf` 混用。

## 2. 常用语法

二维 `vector`：

```cpp
vector<vector<int>> a(n, vector<int>(m));
```

范围 `for`：

```cpp
for (char c : s) { }        // 副本
for (char &c : s) { }       // 引用，可修改原串
for (const auto &x : a) { } // 只读，不拷贝
```

三目运算符：

```cpp
cout << (cond ? x : y);
```

常用函数：

```cpp
abs(x);
sqrt(x);
reverse(a.begin(), a.end());
sort(a.begin(), a.end());
tolower(c);
toupper(c);
```

## 3. STL 容器怎么想

- 顺序存储、按下标访问：`vector`
- 后进先出：`stack`
- 两端操作：`deque`
- 反复取当前最值：`priority_queue`
- 只关心值是否出现：`set` / `unordered_set`
- 需要“键 -> 值”映射：`map` / `unordered_map`

最常见定义：

```cpp
vector<int> v;
stack<int> st;
deque<int> q;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
set<int> s;
unordered_set<int> us;
map<string, int> mp;
unordered_map<string, int> ump;
```

提醒：
- `priority_queue<int>` 默认是大根堆。
- `mp[key]` 在 `key` 不存在时会自动插入默认值。
- `unordered_*` 平均更快，但无序，最坏可能退化。

## 4. 常用算法速查

排序：

```cpp
sort(a.begin(), a.end());
sort(a.begin(), a.end(), cmp);
stable_sort(a.begin(), a.end(), cmp);
```

二分：

```cpp
lower_bound(a.begin(), a.end(), x); // 第一个 >= x
upper_bound(a.begin(), a.end(), x); // 第一个 > x
```

计数出现次数：

```cpp
int cnt = upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);
```

最大公约数：

```cpp
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

整数反转：

```cpp
long long t = x, b = 0;
while (t) {
    b = b * 10 + (t % 10);
    t /= 10;
}
```

## 5. 数学与字符串最常错的点

模运算：

```cpp
(a + b) % mod
(a - b + mod) % mod
(a * b) % mod
```

注意：
- 加、减、乘可以边算边取模。
- 除法不能直接照搬，模意义下做除法通常要逆元，而且有前提。

负数取模修正：

```cpp
(x % m + m) % m
```

字符串：

```cpp
s.find("abc");
s.substr(pos, len);
```

注意：
- `find` 查的是子串，不是完整单词。
- 找不到返回 `string::npos`。
- 文本题如果要忽略大小写，先统一转大小写再比较。

## 6. 最后一分钟检查

- 会不会爆 `int`
- 二分查的是下标、值，还是答案
- `find` 查的是子串还是完整匹配
- `mp[key]` 会不会误插入
- 题目需要的是最左、最右、次数，还是是否存在
