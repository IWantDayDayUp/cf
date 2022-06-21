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

    for (int i = 0; i + 1 < n; i += 2)
    {
        swap(nums[i], nums[i + 1]);
    }

    cout << (n - 1) / 2 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " \n"[i == n - 1];
    }

    return 0;
}