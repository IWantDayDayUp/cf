#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        q.emplace(make_pair(num, i));
    }

    while (q.size() > 1)
    {
        int a = q.top().first, x = q.top().second;
        q.pop();

        int b = q.top().first, y = q.top().second;
        q.pop();

        a -= 1;
        b -= 1;

        if (a > 0) q.emplace(make_pair(a, x));
        if (b > 0) q.emplace(make_pair(b, y));
    }

    cout << q.top().second << endl;
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