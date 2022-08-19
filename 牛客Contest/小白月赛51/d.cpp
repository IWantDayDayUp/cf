#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;

    vector<pair<int, char>> ans;

    while (n)
    {
        for (int i = 0; i < n % x; i++)
        {
            ans.emplace_back(make_pair(1, 'a'));
        }
        ans.emplace_back(make_pair(2, 'b'));

        n /= x;
    }

    cout << ans.size() << endl;
    for (auto & p : ans)
    {
        cout << p.first << ' ' << p.second << endl;
    }
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