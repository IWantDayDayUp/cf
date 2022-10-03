#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    priority_queue<int> qa(a.begin(), a.end());
    priority_queue<int> qb(b.begin(), b.end());

    int ans = 0;

    while (!qa.empty())
    {
        if (qa.top() == qb.top())
        {
            qa.pop();
            qb.pop();
            continue;
        }

        ans += 1;
        
        if (qa.top() < qb.top())
        {
            int cur = qb.top();
            qb.pop();

            qb.emplace(to_string(cur).size());
        } else {
            int cur = qa.top();
            qa.pop();

            qa.emplace(to_string(cur).size());
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