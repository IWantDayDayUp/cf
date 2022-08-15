#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }

    int ans = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] > a[i + 1])
        {
            int mx = -1;
            for (int j = 1; j <= i; j++)
            {
                mx = max(mx, mp[a[j]]);
            }

            set<int> st;
            for (int j = 1; j <= mx; j++)
            {
                st.insert(a[j]);
            }

            cout << st.size() << endl;
            return;
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
        slove();
    }

    return 0;
}