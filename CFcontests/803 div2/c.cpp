#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> pos, neg, nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num > 0)
        {
            pos.emplace_back(num);
        } else if (num < 0)
        {
            neg.emplace_back(num);
        } else  {
            if (nums.size() < 2)
            {
                nums.emplace_back(num);
            }
        }
    }

    if (pos.size() > 2 || neg.size() > 2) 
    {
        cout << "NO" << endl;
        return ;
    }

    map<int, int> mp;
    if (nums.size() > 0) mp[0] = 1;
    for (auto & num : pos)
    {
        nums.emplace_back(num);
        mp[num] = 1;
    }
    for (auto & num : neg)
    {
        nums.emplace_back(num);
        mp[num] = 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (mp[nums[i] + nums[j] + nums[k]] != 1)
                {
                    cout << "NO" << endl;
                    return ;
                }
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}