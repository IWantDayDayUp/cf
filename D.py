class BIT {
private:
    int n;
    vector<int> tree;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }
    
    void update(int x, int val) {
        while (x <= n) {
            // ++tree[x];
            tree[x] += val;
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = 0;
        for (auto f : flowers)
        {
            n = max(n, f[1]);
        }
        BIT bit(n + 1);
        for (auto f : flowers){
            int a = f[0];
            int b = f[1];
            
            bit.update(a, 1);
            bit.update(b + 1, -1);
        }
        
        vector<int> ans;
        for (auto t : persons)
        {
            int num = 0;
            if (t <= n){
                num = bit.query(t);
            }
            ans.push_back(num);
        }
        
        return ans;
    }
};