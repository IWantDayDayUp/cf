#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    vector<int> ans;

    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        if (st.count(i))
        {
            continue;
        }

        while (cur <= n && !st.count(cur))
        {
            st.insert(cur);

            ans.emplace_back(cur);
            cur *= 2;
        }

        // cout << temp << endl;
    }
    
    cout << 2 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
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