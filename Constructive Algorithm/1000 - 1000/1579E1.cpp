#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    deque<int> q;
    for (auto & num : p)
    {
        if (q.empty() || num < q.front())
        {
            q.emplace_front(num);
        } else {
            q.emplace_back(num);
        }
    }

    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop_front();
        cout << " \n"[q.empty()];
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