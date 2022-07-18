#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i ++)
    {
        if (nums[i] > nums[i - 1] + nums[i + 1])
        {
            ans += 1;
        }
    }

    if (k == 1)
    {
        cout << (n - 1) / 2 << endl;
    } else {
        cout << ans << endl;
    }

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