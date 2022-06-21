#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    if (n > 26)
    {
        cout << -1 << endl;
    } else {
        set<char> st;
        for (auto & c : s)
        {
            st.insert(c);
        }

        cout << n - st.size() << endl;
    }

    return 0;
}