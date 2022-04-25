# C++ Tips

## 遍历map

```c++
// 题目: 给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过。

// 实例: 
// 输入：nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
// 输出：[3,4]
// 解释：
// nums[0] = [3,1,2,4,5]，nums[1] = [1,2,3,4]，nums[2] = [3,4,5,6]，在 nums 中每个数组中都出现的数字是 3 和 4 ，所以返回 [3,4]

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mp;
        for (auto &v : nums) for (int x : v) mp[x]++;
        vector<int> ans;

        // 遍历map
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            if (it->second == nums.size()) ans.push_back(it->first);
        }
        return ans;
    }
};
```

## sort() 匿名函数

```c++
// 升序排序
sort(id.begin(), id.end(), [&](int i, int j) { return persons[i] < persons[j]; });
```

## sort() 排序, 但保存索引idx

```c++
int n = persons.size();
vector<int> id(n);
// 给整个vector赋值, 从0开始(这个值就是对应的索引)
iota(id.begin(), id.end(), 0);
// 然后按照某种规则排序
// 但, 这个vector里存的值, 还是它本来应该的索引
sort(id.begin(), id.end(), [&](int i, int j) { return persons[i] < persons[j]; });
```

## 优先队列 priority_queue
