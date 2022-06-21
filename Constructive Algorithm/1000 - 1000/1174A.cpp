#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> nums(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += nums[i];
        s2 += nums[i + n];
    }

    if (s1 == s2)
    {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < 2 * n; i++)
        {
            cout << nums[i] << " \n"[i == 2 * n - 1];
        }
    }

    return 0;
}