# map离散化 + 差分 + 前缀和

```c++
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> mp;
        for (auto &it: flowers) mp[it[0]]++, mp[it[1] + 1]--;
        for (auto x: persons) mp[x];

        int tot = 0;
        for (auto &[x, y]: mp)
            y = (tot += y);

        for (auto &x: persons)
            x = mp[x];
        return persons;
    }
};
```
