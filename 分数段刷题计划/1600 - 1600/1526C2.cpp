#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    priority_queue<int> q;
    long long cur = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp >= 0)
        {
            cur += temp;
            ans += 1;
        } else {
            if (cur + temp >= 0)
            {
                ans += 1;
                cur += temp;
                q.emplace(-temp);
            } else if (!q.empty() && -temp < q.top()) {
                cur += temp + q.top();
                q.pop();
                q.emplace(-temp);
            }
        }
    }

    cout << ans << endl;

    return 0;
}