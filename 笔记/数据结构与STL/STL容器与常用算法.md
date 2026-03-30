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
