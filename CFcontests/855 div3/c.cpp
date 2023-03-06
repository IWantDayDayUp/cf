#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<long long> q;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        if (num > 0)
        {
            q.emplace(num);
        } else {
            if (!q.empty())
            {
                ans += q.top();
                q.pop();
            }
        }
    }

    cout << ans << endl;
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