#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        long long temp = i;
        while (temp % 2 == 0)
        {
            nums[i] += 1;
            temp /= 2;
        }
    }

    vector<long long> a(n);
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] <= n) 
        {
            cnt += nums[a[i]];
            continue;
        }

        while (a[i] % 2 == 0)
        {
            cnt += 1;
            a[i] /= 2;

            if (a[i] <= n)
            {
                cnt += nums[a[i]];
                break;
            }
        }
    }

    sort(nums.rbegin(), nums.rend());

    long long need = n - cnt;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (need <= 0)
        {
            break;
        }
        need -= nums[i];
        ans += 1;
    }

    cout << (need <= 0 ? ans : -1) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}