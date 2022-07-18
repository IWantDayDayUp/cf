#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;

    int ans = 0;

    set<char> st;
    for (auto & c : s)
    {
        if (st.empty() || !st.count(c))
        {
            if (st.size() == 3)
            {
                st.clear();
                ans += 1;
            }

            st.insert(c);
        }
    }

    if (!st.empty())
    {
        ans += 1;
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