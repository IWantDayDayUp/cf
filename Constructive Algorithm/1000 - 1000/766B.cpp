#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    bool ok = false;
    for (int i = 2; i < n; i++)
    {
        if (nums[i - 2] + nums[i - 1] > nums[i])
        {
            // cout << "YES" << endl;
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}