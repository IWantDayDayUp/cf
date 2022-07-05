#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    bool one = false;
    bool con = false;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            one = true;
        }
        if (i + 1 < n && nums[i] + 1 == nums[i + 1])
        {
            con = true;
        }
    }

    cout << ((one && con) ? "NO" : "YES") << endl;
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