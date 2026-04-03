# STL 容器与常用算法

## 1. `stack`

头文件：

```cpp
#include <stack>
```

定义：

```cpp
stack<int> st;
```

常用操作：

```cpp
st.push(x);   // 入栈
st.pop();     // 出栈，无返回值
st.top();     // 访问栈顶
st.empty();   // 是否为空
st.size();    // 元素个数
```

注意：
- `stack` 是后进先出（LIFO）。
- 没有普通遍历接口。
- 调用 `top()` 和 `pop()` 前要先判空。

## 2. `deque`

头文件：

```cpp
#include <deque>
```

定义：

```cpp
deque<int> q;
```

常用操作：

```cpp
q.push_back(x);
q.pop_back();
q.push_front(x);
q.pop_front();
q.front();
q.back();
q.empty();
```

适用场景：
- 双端操作
- 单调队列
- 滑动窗口维护候选下标

## 3. `set` 与 `unordered_set`

头文件：

```cpp
#include <set>
#include <unordered_set>
```

定义：

```cpp
set<int> s1;              // 有序、自动去重
unordered_set<int> s2;    // 无序、自动去重
```

常用操作：

```cpp
s.insert(x);
s.erase(x);
s.find(x);
s.count(x);
s.empty();
s.size();
s.clear();
```

区别：
- `set`：底层通常为红黑树，时间复杂度 `O(log n)`，元素有序。
- `unordered_set`：底层通常为哈希表，平均 `O(1)`，元素无序，最坏 `O(n)`。

注意：
- `set` 不支持随机访问。
- `set` 中元素值不能直接修改。
- `unordered_set` 存自定义类型时通常需要自定义哈希。

## 4. `map` 与 `unordered_map`

头文件：

```cpp
#include <map>
#include <unordered_map>
```

定义：

```cpp
map<string, int> mp1;
unordered_map<string, int> mp2;
```

常用操作：

```cpp
mp[key] = value;      // 插入或更新
mp.erase(key);        // 删除
mp.find(key);         // 查找
mp.count(key);        // 是否存在
mp.empty();           // 是否为空
mp.size();            // 元素个数
```

遍历：

```cpp
for (auto &p : mp) {
    cout << p.first << ' ' << p.second << '\n';
}
```

区别：
- `map`：有序，`O(log n)`
- `unordered_map`：无序，平均 `O(1)`，最坏 `O(n)`

重要注意：
- `mp[key]` 在 `key` 不存在时会自动插入默认值。
- 如果只是判断是否存在，优先用 `find` 或 `count`。

## 5. `vector` 插入

在向量 `v` 中某一位置 `i` 之前插入变量 `x`：

```cpp
v.insert(v.begin() + i, x);
```

注意：
- 插入后后面的元素会整体后移。
- 如果频繁在中间插入，`vector` 可能不合适。

## 6. `lower_bound` 与 `upper_bound`

头文件：

```cpp
#include <algorithm>
```

要求：
- 使用前序列必须有序。

含义：
- `lower_bound(begin, end, x)`：返回第一个 `>= x` 的位置。
- `upper_bound(begin, end, x)`：返回第一个 `> x` 的位置。

统计某个值出现次数：

```cpp
int cnt = upper_bound(a, a + n, x) - lower_bound(a, a + n, x);
```

这是做计数类二分题时非常常用的写法。

## 7. `sort` 自定义排序

头文件：

```cpp
#include <algorithm>
```

基本写法：

```cpp
sort(a.begin(), a.end());          // 默认升序
sort(a.begin(), a.end(), cmp);     // 按自定义规则排序
```

### 7.1 比较函数写法

例如：按从大到小排序

```cpp
bool cmp(int a, int b) {
    return a > b;
}
```

使用：

```cpp
sort(a.begin(), a.end(), cmp);
```

含义：
- 如果 `cmp(a, b)` 返回 `true`，表示排序后 `a` 应该排在 `b` 前面。

### 7.2 `lambda` 写法

比赛里更常用的是直接写在 `sort` 里面：

```cpp
sort(a.begin(), a.end(), [](int x, int y) {
    return x > y;
});
```

优点：
- 不用额外写单独的比较函数
- 排序规则离调用位置更近，读起来更直接

### 7.3 结构体多关键字排序

例如有：

```cpp
struct Node {
    int a, b;
};
```

希望按：
- 第一关键字 `a` 升序
- 如果 `a` 相等，再按 `b` 降序

可以写成：

```cpp
bool cmp(const Node &x, const Node &y) {
    if (x.a != y.a) return x.a < y.a;
    return x.b > y.b;
}
```

然后：

```cpp
sort(v.begin(), v.end(), cmp);
```

### 7.4 常见错误

1. 相等时不要乱返回

错误想法：

```cpp
return a <= b;
```

原因：
- 比较器要求的是“谁应该排前面”
- 不是“谁小于等于谁”
- 如果写成 `<=`，相等时 `cmp(a, b)` 和 `cmp(b, a)` 都可能为 `true`，会破坏排序规则

正确写法：

```cpp
return a < b;
```

2. 多关键字排序时要先判第一关键字是否相等

```cpp
if (x.a != y.a) return x.a < y.a;
return x.b > y.b;
```

3. 比较器里不要写会改变外部数据的逻辑

原因：
- 比较函数应该只负责比较
- 不要在里面修改数组、计数器、容器内容

### 7.5 常见场景

- 整数从大到小排序
- `pair` 按第一关键字升序、第二关键字降序
- 结构体按多个条件排序
- 先按分数排，再按编号排

例如 `pair<int, int>`：

```cpp
sort(v.begin(), v.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
});
```

记忆方式：
- `return true`：左边这个元素应该更靠前
- 先写第一关键字
- 再写相等时的第二关键字

### 7.6 `stable_sort`

作用：
- 稳定排序
- 如果两个元素比较结果“相等”，那么排序后它们原本的先后顺序不会变

写法：

```cpp
stable_sort(a.begin(), a.end());
stable_sort(a.begin(), a.end(), cmp);
```

和 `sort` 的区别：
- `sort`：通常更常用，速度快，但不保证稳定
- `stable_sort`：保证稳定，但常数通常更大一些

什么时候用：
- 当“相等时原顺序也有意义”
- 先按第二关键字排，再按第一关键字做稳定排序
- 题目要求“分数相同保持输入顺序”

例子：

```cpp
vector<pair<int, char>> v = {{2, 'A'}, {1, 'B'}, {2, 'C'}, {1, 'D'}};

stable_sort(v.begin(), v.end(), [](const pair<int, char> &x, const pair<int, char> &y) {
    return x.first < y.first;
});
```

排序后：
- `first = 1` 的仍然是 `B` 在前，`D` 在后
- `first = 2` 的仍然是 `A` 在前，`C` 在后

### 7.7 其他常用排序相关函数

1. `reverse`

作用：
- 把一个区间直接翻转

```cpp
sort(a.begin(), a.end());
reverse(a.begin(), a.end());   // 升序排完再翻成降序
```

2. `partial_sort`

作用：
- 只关心前 `k` 小或前 `k` 大时使用
- 排完后，前 `k` 个位置是正确的，且这部分内部有序

```cpp
partial_sort(a.begin(), a.begin() + k, a.end());
```

3. `nth_element`

作用：
- 只关心第 `k` 小元素时使用
- 会把“应该排在第 k 个位置的元素”放到对应位置
- 左边都不大于它，右边都不小于它，但左右内部不保证有序

```cpp
nth_element(a.begin(), a.begin() + k, a.end());
```

例如：
- `k = 0`：最小值
- `k = n / 2`：中位数位置

做题提醒：
- 需要完整有序：`sort` 或 `stable_sort`
- 只要前 `k` 个最小值：`partial_sort`
- 只要第 `k` 小：`nth_element`
