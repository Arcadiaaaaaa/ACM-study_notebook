1.cpp输入输出格式化
2️⃣ 控制小数位数

需要头文件：
#include <iomanip>

示例：
cout << fixed << setprecision(2) << x;

说明：
fixed 固定小数格式
setprecision(n) 保留 n 位小数

3️⃣ 控制宽度与对齐

cout << setw(5) << x; // 默认右对齐
cout << left << setw(5) << x; // 左对齐

说明：
setw(n) 设置字段宽度

4️⃣ 填充字符

cout << setfill('0') << setw(5) << x;

示例输出：
00012

5️⃣ 进制输出

cout << dec << x; // 十进制
cout << hex << x; // 十六进制
cout << oct << x; // 八进制

6️⃣ C 风格格式化

需要头文件：
#include <cstdio>

printf("%d %.2f\n", a, b);

常用格式符：
%d int
%lld long long
%.2f 保留2位小数
%c char
%s 字符串

7️⃣ 竞赛 IO 加速

ios::sync_with_stdio(false);
cin.tie(nullptr);
2.整数反转数学模板 t为原数字，b为反转后 
            while (t) {
                b = b * 10 + (t % 10);
                t /= 10;
            }
3.递归gcd模板
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
4.cpp函数
绝对值abs()
开平方sqrt()
读取整行（包含空格）getline(cin, s);   // 读取整行
大小写转换toupper(c),tolower(c);
翻转字符串reverse(ans.begin(), ans.end());
开二维n*m的vector：vector<vector<int>> a(n, vector<int>(m));


5.三角形
判断：任意两边和大于第三边

6.代数
对于任意整数运算，在任何步骤对 MOD 取余，不会影响最终结果

7.数据结构stl
stack
===== 基础准备 =====
1. 头文件：#include <stack>
2. 命名空间：using namespace std; （或使用 std::stack 限定）

===== 创建栈对象 =====
语法：stack<数据类型> 栈名;

===== 核心操作（成员函数） =====
1. 入栈：st.push(值);
2. 出栈：st.pop(); （无返回值，空栈调用会导致未定义行为）
3. 取栈顶：st.top(); （返回栈顶元素，不删除）
4. 判空：st.empty(); （栈空返回true，非空返回false）
5. 查大小：st.size(); （返回栈内元素个数）

===== 注意事项 =====
1. stack是“后进先出（LIFO）”容器，仅支持操作栈顶元素
2. 无迭代器，无法直接遍历栈内所有元素
3. 调用top()/pop()前必须用empty()判空，避免越界崩溃

set
===== 基础准备 =====
1. 有序set：#include <set>
2. 无序set（unordered_set）：#include <unordered_set>
3. 命名空间：using namespace std; （或使用 std:: 限定）

===== 创建容器对象 =====
1. 有序set：set<数据类型> 容器名; （默认升序、无重复）
2. 无序set：unordered_set<数据类型> 容器名; （无序、无重复）

===== 核心操作（成员函数，两者通用/差异标注） =====
【通用操作】
1. 插入元素：容器名.insert(值); （均自动去重）
2. 删除元素：
   - 容器名.erase(值); （删除指定值的元素）
   - 容器名.erase(迭代器); （删除迭代器指向的元素）
3. 查找元素：容器名.find(值); （返回迭代器，找到则指向该元素，否则指向end()）
4. 判空：容器名.empty(); （空返回true，非空返回false）
5. 查大小：容器名.size(); （返回元素个数）
6. 清空容器：容器名.clear(); （删除所有元素）
7. 统计元素个数：容器名.count(值); （返回0或1，因自动去重）

【差异说明】
- set的insert会自动按升序排序；unordered_set无排序逻辑
- unordered_set额外支持：容器名.rehash(桶数); （设置哈希桶数量，优化性能）

===== 注意事项 =====
【有序set】
1. 基于红黑树实现，插入/删除/查找时间复杂度O(log n)
2. 不支持随机访问，需通过迭代器遍历
3. 无法直接修改元素值，需先删旧值再插新值

【无序set（unordered_set）】
1. 基于哈希表实现，平均插入/删除/查找时间复杂度O(1)，最坏O(n)
2. 无序存储，遍历顺序不固定
3. 不支持排序相关操作（如按序遍历）
4. 存储的类型需支持哈希（基础类型默认支持，自定义类型需手动实现哈希函数）
map
===== 基础准备 =====
1. 头文件：#include <unordered_map> 或 #include <map>
2. 命名空间：using namespace std; （或使用 std::unordered_map / std::map 限定）

===== 创建哈希表对象 =====
语法：
- 无序哈希表：unordered_map<键类型, 值类型> 表名;
- 有序映射表：map<键类型, 值类型> 表名;

===== 核心操作（成员函数） =====
1. 插入/更新：mp[key] = value;  // key 不存在会插入，存在会更新
2. 查找：
   - auto it = mp.find(key);      // 返回迭代器
   - if(it != mp.end()) 表示存在
3. 删除：mp.erase(key);
4. 判断是否存在：mp.count(key);  // 存在返回 1，不存在返回 0
5. 遍历：
   for(auto &p : mp) { 
       p.first  // key
       p.second // value
   }
6. 取大小：mp.size();  // 返回元素个数
7. 判空：mp.empty();   // 空返回 true，非空返回 false

===== 注意事项 =====
1. unordered_map 平均 O(1)，最坏 O(n)（哈希冲突）
2. map 底层红黑树实现，插入、查找、删除 O(log n)
3. key 类型需可哈希（unordered_map）或可比较（map）
4. unordered_map 无序，map key 有序
5. 大对象作为 key 会降低性能，尽量用整数或字符串
8.语法糖
范围for
for (类型 变量 : 容器)
{
循环体;
}

作用：依次取出容器中的每一个元素。可选：值拷贝 引用遍历 常量引用

算法：
约瑟夫问题的关键在于：删除一个人后，
对剩余元素重新编号，把当前问题转化为规模减一的同类问题，由此建立递推关系。
即为下标映射、重编号、规模缩小

语言：主函数里定义的变量不能被别的函数直接访问；把它作为参数传进去，或者定义成全局变量。
cout << (条件 ? 值1 : 值2); 三目运算优先级低

方向数组 把“某个点周围能走到的方向”，预先存进数组里。
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
你原来是一个一个写：

if (isboom(x - 1, y - 1)) cnt++;
if (isboom(x - 1, y)) cnt++;
if (isboom(x - 1, y + 1)) cnt++;
...

用了方向数组后，改成循环：

for (int k = 0; k < 8; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && isboom(nx, ny)) {
        cnt++;
    }
}

范围for及引用范围for
范围 for
for (char c : s)

不用下标，直接遍历每个元素

c 是元素的副本

改 c，原数组/原字符串不会变

引用范围 for
for (char &c : s)

也是直接遍历每个元素

c 是原元素的引用

改 c，原数组/原字符串会变

规则表 / 映射表：
核心：直接把题目的规则写出来。
elephant 吃 tiger
就存成表：
beat["elephant"] = "tiger";
判断时直接查：
if (beat[a] == b)
编号后用取余找关系
核心：先把对象按某种顺序编号，再利用数字规律判断。
elephant = 0
tiger = 1
cat = 2
mouse = 3
因为它们形成一个环：
0 -> 1 -> 2 -> 3 -> 0
所以“x 吃 y”可以写成：
(y == (x + 1) % 4)

string 
find：查找子串第一次出现的位置。
例如：在字符串 aaBOBcc 中查找 BOB，返回的是它第一次出现的下标。
注意：find 区分大小写，所以不能直接用它查找不区分大小写的 Bob，除非先把字符串统一转成全小写或全大写。
如果没找到，会返回 string::npos。

substr：截取子串。
例如：substr(2, 3) 表示从下标 2 开始，截取 3 个字符。
如果字符串是 abcdef，结果就是 cde。

compare：比较子串。
例如：比较字符串从下标 5 开始、长度为 3 的部分，是否等于 Bob。
如果返回值等于 0，说明相等。
注意：compare 也区分大小写。

补充：
size_t 是字符串长度、位置这类值常用的无符号整数类型。
npos 表示“没找到”。

cin >> s 读到空格就停止，getline(cin, s) 可以读整行。


负数取模修正：

在 C++ 里，负数取模后结果可能还是负数。

例如：

-2 % 26 = -2

所以如果直接写：

(c - 'a' - n) % 26

当括号里是负数时，结果就会错。

核心思想

先加上一个足够大的数，把结果拉回非负范围，再取模。

通用写法：

(x % m + m) % m

作用：把 x 映射到 0 ~ m-1 范围内。