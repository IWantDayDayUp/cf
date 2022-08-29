#include <bits/stdc++.h>

using namespace std;

void solve() {
    set<char> st;
    for (int i = 0; i < 4; i++)
    {
        char c;
        cin >> c;

        st.insert(c);
    }

    int n = st.size();
    if (n == 1)
    {
        cout << 0 << endl;
    } else if (n == 2)
    {
        cout << 1 << endl;
    } else if (n == 3)
    {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
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