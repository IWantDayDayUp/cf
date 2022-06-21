#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool ans = false;
vector<int> nums, a, b;
vector<int> res;

void dfs(int i)
{
    if (i == nums.size())
    {
        int cnt1 = 0, cnt2 = 0;
        for (auto & num : a)
        {
            cnt1 += nums[num];
        }
        for (auto & num : b)
        {
            cnt2 += nums[num];
        }

        if (cnt1 != cnt2 and cnt1 >0 and cnt2 > 0)
        {
            ans = true;
            res.clear();
            for (auto & num : a)
            {
                res.emplace_back(num);
            }
        }
        return ;
    } else {
        a.emplace_back(i);
        dfs(i + 1);
        a.pop_back();

        b.emplace_back(i);
        dfs(i + 1);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    nums.clear();
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (n == 1) 
    {
        cout << -1 << endl;
        return 0;
    }

    ans = false;
    a.clear();
    b.clear();
    dfs(0);

    if (ans == true)
    {
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] + 1 << " \n"[i == res.size() - 1];
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}