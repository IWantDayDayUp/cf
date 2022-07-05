#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n, 0), p(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> nums[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int a, int b){
        return nums[a] > nums[b];
    });

    vector<int> ans(n + 1, 0);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << p[i] << endl;
        ans[p[i] + 1] = (i % 2 == 0 ? 1 : -1) * (i / 2 + 1);
        total += 2ll * abs(ans[p[i] + 1] - 0) * nums[p[i]];
    }

    cout << total << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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