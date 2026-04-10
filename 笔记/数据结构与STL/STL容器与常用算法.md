# STL 容器与常用算法

## 0. 常用容器怎么选

做题时不要先想“这个容器会不会用”，而要先想“我要维护什么关系”：

- 只需要顺序存一批数，并且经常按下标访问：`vector`
- 后进先出：`stack`
- 两端都要插删：`deque`
- 需要反复取当前最大值或最小值：`priority_queue`
- 需要自动去重，只关心某个值是否出现过：`unordered_set`
- 需要自动去重，而且还要有序：`set`
- 需要维护“键 -> 值”的映射：`unordered_map` 或 `map`
- 需要按键有序遍历，或者找最小的 `>= x` 的键：`map`

一个很实用的判断方式：
- 关心顺序、下标、批量存储：优先想 `vector`
- 关心“每次拿当前最值”：优先想 `priority_queue`
- 关心“是否存在”：优先想 `set` / `unordered_set`
- 关心“某个键对应什么值 / 次数”：优先想 `map` / `unordered_map`
- 关心“只操作一端还是两端”：想 `stack` / `deque`

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

什么时候用：
- 当前操作永远只关心“最新加入的那个元素”
- 需要“撤销上一步”“括号匹配”“表达式处理”
- 需要自己维护递归过程，或者做单调栈

例子：
- 括号匹配：遇到左括号入栈，遇到右括号就和栈顶匹配
- 浏览器回退 / 撤销操作：最后一次操作最先被撤销
- 单调栈题：维护“左边第一个更大 / 更小元素”

什么时候不优先用：
- 需要遍历所有元素时，`stack` 不方便
- 需要访问中间元素时，`stack` 不合适

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

什么时候用：
- 既可能从头删，也可能从尾删
- 需要维护一个窗口里的候选答案
- 需要队头、队尾都高频操作

例子：
- 滑动窗口最小值 / 最大值
- 维护某段区间里可能成为最优解的下标
- 某些模拟题里，元素会从两头进出

什么时候不优先用：
- 只在尾部插入、遍历、排序时，通常 `vector` 更常用
- 只需要普通先进先出队列时，`queue` 语义更直接

## 3. `priority_queue`

头文件：

```cpp
#include <queue>
```

定义：

```cpp
priority_queue<int> q1;   // 默认大根堆，堆顶是最大值
priority_queue<int, vector<int>, greater<int>> q2;   // 小根堆，堆顶是最小值
```

常用操作：

```cpp
q.push(x);
q.pop();
q.top();
q.empty();
q.size();
```

默认规则：
- `priority_queue<int>` 默认是大根堆
- 也就是每次 `top()` 取到的是当前最大值

小根堆写法：

```cpp
priority_queue<int, vector<int>, greater<int>> q;
```

存 `pair` 时也很常用：

```cpp
priority_queue<pair<int, int>> q1;   // 先按 first 大，再按 second 大
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
```

什么时候用：
- 需要反复取当前最大值或最小值
- 每次插入新元素后，还要快速得到“当前最优”的那个
- 元素集合在动态变化，但不需要有序遍历全部元素

例子：
- 每次取当前最小边权 / 最小距离：Dijkstra
- 每次取当前最大值或最小值做贪心
- 合并若干有序序列时，每次取最小头元素
- 维护前 `k` 大或前 `k` 小

为什么适合：
- `push` 和 `pop` 都是 `O(log n)`
- `top` 是 `O(1)`
- 比每次都重新排序或线性找最值高效得多

什么时候不优先用：
- 需要删除中间某个指定元素时，不方便
- 需要遍历时按完整有序顺序输出，`sort` / `set` 往往更直接
- 需要修改堆中某个旧元素的值，普通 `priority_queue` 不支持原地改

常见坑点：
- 默认是大根堆，不是小根堆
- `pop()` 没有返回值，要先 `top()` 再 `pop()`
- 不能像 `vector` 一样随机访问中间元素
- Dijkstra 里常会把同一个点多次入堆，再用判重 / 松弛条件过滤旧状态

记忆方式：
- `stack` 是“只看最后放进去的”
- `queue` 是“只看最早进去的”
- `priority_queue` 是“只看当前最优先的”

## 4. `set` 与 `unordered_set`

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

什么时候用：
- 需要自动去重
- 需要动态插入 / 删除 / 查询某个值是否存在
- 不想自己手写判重逻辑

怎么选：
- 只关心“有没有”，不关心顺序：优先 `unordered_set`
- 还要有序、还要找前驱后继、还要找第一个 `>= x`：用 `set`

例子：
- 统计输入里有多少个不同数字
- 判断某个单词之前是否出现过
- 维护当前所有可选值，并随时取最小值或找离 `x` 最近的有序元素

什么时候不优先用：
- 如果数据不会动态变化，只是最后统一去重，常常“排序 + unique”更直接
- 如果需要记录出现次数，而不只是是否存在，应该考虑 `map` / `unordered_map`

## 5. `map` 与 `unordered_map`

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

什么时候用：
- 需要维护“键 -> 值”的对应关系
- 需要统计频率、编号映射、分类计数
- 键不适合直接当数组下标，或者值域太大

怎么选：
- 只关心查找和计数速度，不关心键顺序：优先 `unordered_map`
- 需要按键从小到大遍历，或者找某个键附近的位置：用 `map`

例子：
- 统计每个单词出现次数：`unordered_map<string, int>`
- 给离散的大整数编号：`map<int, int>` 或 `unordered_map<int, int>`
- 记录每个颜色出现了多少次、每个名字对应多少分

什么时候不优先用：
- 如果键是连续的小整数，例如 `1 ~ n`，直接开数组通常更快更简单
- 如果只关心“是否存在”，不需要附带值，优先 `set` / `unordered_set`

## 6. `vector`

定义：

```cpp
vector<int> v;
```

常用操作：

```cpp
v.push_back(x);
v.pop_back();
v[i];
v.size();
v.empty();
v.begin();
v.end();
```

什么时候用：
- 需要顺序存储一批元素
- 需要按下标随机访问
- 需要经常尾插
- 需要配合排序、二分、前缀和等常见算法

例子：
- 存输入的整个数组
- 存图的邻接表：`vector<int> g[N]`
- 存所有答案、所有候选点、所有区间
- 排序题里先把数据存进 `vector` 再 `sort`

为什么比赛里最常用：
- 写法直接
- 支持随机访问
- 和 `sort`、`lower_bound`、`reverse` 这些算法配合最好

什么时候不优先用：
- 频繁在中间插入删除，不合适
- 需要头部插入删除很多次，也不如 `deque` 直接

### 6.1 `vector` 插入

在向量 `v` 中某一位置 `i` 之前插入变量 `x`：

```cpp
v.insert(v.begin() + i, x);
```

注意：
- 插入后后面的元素会整体后移。
- 如果频繁在中间插入，`vector` 可能不合适。

## 7. `lower_bound` 与 `upper_bound`

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

## 8. `sort` 自定义排序

头文件：

```cpp
#include <algorithm>
```

基本写法：

```cpp
sort(a.begin(), a.end());          // 默认升序
sort(a.begin(), a.end(), cmp);     // 按自定义规则排序
```

### 8.1 比较函数写法

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

### 8.2 `lambda` 写法

比赛里更常用的是直接写在 `sort` 里面：

```cpp
sort(a.begin(), a.end(), [](int x, int y) {
    return x > y;
});
```

优点：
- 不用额外写单独的比较函数
- 排序规则离调用位置更近，读起来更直接

### 8.3 结构体多关键字排序

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

### 8.4 常见错误

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

### 8.5 常见场景

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

### 8.6 `stable_sort`

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

### 8.7 其他常用排序相关函数

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

## 9. 数组模拟双向链表

适用场景：
- 需要频繁在中间插入、删除
- 题目给的是“在某个点左边 / 右边插入”
- 只要求顺序维护，不要求随机访问
- 想避免 `vector` 中间插入删除带来的整体移动

核心思想：
- 不用真正的指针
- 用数组下标充当“节点地址”
- `e[i]` 存节点值，`l[i]` 存左指针，`r[i]` 存右指针
- 每新建一个点，就分配一个新的下标 `idx`

最常见写法是加两个哨兵节点：
- `0` 表示头结点
- `1` 表示尾结点
- 初始时 `r[0] = 1`，`l[1] = 0`

这样做的好处：
- 插到最左边，本质上是插到 `0` 的右边
- 插到最右边，本质上是插到 `1` 的左边
- 不用反复特判“链表为空”“插在头部”“插在尾部”

### 9.1 基本定义

```cpp
int e[N], l[N], r[N], idx;
```

含义：
- `e[i]`：编号为 `i` 的节点存的值
- `l[i]`：编号为 `i` 的节点左边是谁
- `r[i]`：编号为 `i` 的节点右边是谁
- `idx`：下一个可用节点编号

初始化：

```cpp
void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
```

### 9.2 插入操作

把值为 `x` 的新节点插到编号 `k` 的节点右边：

```cpp
void insert_right(int k, int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
```

顺序要记住：
- 先连新点和左右邻居
- 再改左右邻居指向它
- 最后 `idx++`

把值为 `x` 的新节点插到编号 `k` 的节点左边：

```cpp
void insert_left(int k, int x) {
    insert_right(l[k], x);
}
```

常见特例：
- 插到最左边：`insert_right(0, x)`
- 插到最右边：`insert_left(1, x)`

### 9.3 删除操作

删除编号 `k` 的节点：

```cpp
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
```

本质：
- 让 `k` 左边的点直接连到 `k` 右边
- 再让 `k` 右边的点直接连到 `k` 左边
- 节点 `k` 本身不用真的擦掉，只是从链表里断开了

### 9.4 查找操作

如果题目是“按编号删 / 按编号插”，那么查找通常不需要。

如果题目要求“按值找第一个等于 `x` 的节点”，就只能线性扫：

```cpp
int find_first(int x) {
    for (int i = r[0]; i != 1; i = r[i]) {
        if (e[i] == x) return i;
    }
    return -1;
}
```

要记住：
- 数组模拟链表的优势是已知节点编号时插删是 `O(1)`
- 如果按值找节点，复杂度仍然是 `O(n)`

### 9.5 遍历链表

从左到右输出：

```cpp
for (int i = r[0]; i != 1; i = r[i]) {
    cout << e[i] << ' ';
}
```

从右到左输出：

```cpp
for (int i = l[1]; i != 0; i = l[i]) {
    cout << e[i] << ' ';
}
```

### 9.6 适合什么题

- 模拟链表操作
- 在某个位置左插、右插、删除
- 维护一个序列，但不能接受 `vector` 的整体搬移
- 某些需要 `O(1)` 删除指定位置的题

### 9.7 和 `vector` / `list` 的区别

- `vector`：
  - 支持随机访问
  - 中间插入删除通常要移动一段元素
- `list`：
  - 真正的双向链表
  - STL 写起来方便，但比赛里不一定最好调
- 数组模拟双向链表：
  - 插删逻辑最清楚
  - 常数小
  - 适合题目明确要求模拟链表

### 9.8 常见坑点

- 忘了开头尾哨兵，导致边界特判很多
- `insert_right` 时修改顺序写乱
- 把节点编号和节点值混了
- 题目给的 `k` 可能是“第 k 次插入的节点编号”，不一定是当前第 `k` 个位置
- 删除后如果还拿这个节点继续操作，容易出错

记忆方式：
- 插入：新点先记左右，再改左右邻居
- 删除：左右邻居直接跨过当前点连起来
