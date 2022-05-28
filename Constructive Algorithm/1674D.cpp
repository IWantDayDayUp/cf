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

    for (int i = n - 2; i >= 0; i -= 2)
    {
        if (nums[i] > nums[i + 1])
        {
            swap(nums[i], nums[i + 1]);
        }
    }

    cout << (is_sorted(nums.begin(), nums.end()) ? "Yes" : "NO") << endl;

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