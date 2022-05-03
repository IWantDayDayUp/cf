# priority_queue

## 1. 初始化

```c++
// 存储int的优先队列, greater升序, less降序
priority_queue<int, vector<int>, greater<int>> q;
// 存储pair的优先队列, cmp重载比较规则
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
```

## 2. 重载运算符

案例: 优先队列存储pair, 按照pair.second降序排列

```c++
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
```

## 2. 重载运算符2

存储一个结构体, 分别表示: 值val, 行idx, 列idx

```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        /*
        * 结构体
        */
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        priority_queue<point, vector<point>, greater<point>> que;



        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
    }
};
```
