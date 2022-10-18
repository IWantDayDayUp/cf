#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;

        st.insert(cur);
    }

    int left = 10 - st.size();

    cout << left * (left - 1) * 6 / 2 << endl;
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