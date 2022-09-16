#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(n, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        int num = (p - i + n) % n;
        num = min(num, n - num);

        cnt[num] += 1;

        ans += num;
    }

    vector<int> pre(n, 0);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + cnt[i - 1];
    }

    for (int i = 1; i < n; i++)
    {
        ans = min(ans, ans + pre[i] - cnt[i] - (n - pre[i] - cnt[i]));
    }

    cout << ans << endl;

    return 0;
}