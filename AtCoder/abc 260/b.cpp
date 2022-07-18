#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i;
    }

    set<int> ans;

    // step 1:
    sort(nums.begin(), nums.end(), [&](int i, int j){
        if (a[i] == a[j])
        {
            return i < j;
        }
        return a[i] > a[j];
    });
    int cnt = 0;
    for (auto & i : nums)
    {
        if (cnt == x)
        {
            break;
        }
        if (!ans.count(i))
        {
            cnt += 1;
            ans.insert(i);
        }
    }
    // cout << "step 1" << ' ' << ans.size() << endl;
    // for (auto & num : ans)
    // {
    //     cout << num + 1<< endl;
    // }

    // setp 2:
    sort(nums.begin(), nums.end(), [&](int i, int j)
    {
        if (b[i] == b[j])
        {
            return i < j;
        }
        return b[i] > b[j];
    });
    cnt = 0;
    for (auto & i : nums)
    {
        if (cnt == y)
        {
            break;
        }
        if (!ans.count(i))
        {
            cnt += 1;
            ans.insert(i);
        }
    }
    // cout << "step 2" << ' ' << ans.size() << endl;
    // for (auto & num : ans)
    // {
    //     cout << num + 1 << endl;
    // }

    // step 3:
    sort(nums.begin(), nums.end(), [&](int i, int j)
    {
        if (a[i] + b[i] == a[j] + b[j])
        {
            return i < j;
        }
        return a[i] + b[i] > a[j] + b[j];
    });
    cnt = 0;
    for (auto & i : nums)
    {
        if (cnt == z)
        {
            break;
        }
        if (!ans.count(i))
        {
            cnt += 1;
            ans.insert(i);
        }
    }
    // cout << "step 3" << ' ' << ans.size() << endl;

    for (auto & num : ans)
    {
        cout << num + 1 << endl;
    }

    return 0;
}