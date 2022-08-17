#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dq.emplace_back(i);
    }

    vector<vector<int>> p(n);
    for (int i = 1; i <= n; i++)
    {
        int l = dq.front();
        dq.pop_front();

        int r = dq.front();
        dq.pop_front();

        if (a[l] < a[r])
        {
            swap(l, r);
        }

        dq.emplace_front(l);
        dq.emplace_back(r);

        p[l].emplace_back(i);
    }

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;

        int ans = upper_bound(p[x].begin(), p[x].end(), k) - p[x].begin();

        if (a[x] == n)
        {
            ans += max(0, k - n);
        }

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