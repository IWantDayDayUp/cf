#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    set<char> st;
    for (auto & c : s)
    {
        st.insert(c);
    }

    sort(s.begin(), s.end());

    if (st.size() == 1)
    {
        cout << -1 << endl;
    } else if (st.size() == 2 && s[1] == s[2])
    {
        cout << 6 << endl;
    } else {
        cout << 4 << endl;
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