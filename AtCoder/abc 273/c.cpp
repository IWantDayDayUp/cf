#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }

    // vector<int> ans(n, 0);
    map<int, int> mp;
    while (!st.empty())
    {
        int cur = *st.begin();
        st.erase(cur);
        // cout << cur << ' ' << st.size() << endl;
        mp[cur] = st.size();
    }

    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        // cout << mp[a[i]] << endl;
        ans[mp[a[i]]] += 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}