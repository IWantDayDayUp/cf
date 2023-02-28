#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    set<pair<int, int>> st;

    int x = 0, y = 0;

    st.insert(make_pair(x, y));

    for (auto & c : s)
    {
        if (c == 'R')
        {
            x += 1;
        } else if (c == 'L')
        {
            x -= 1;
        } else if (c == 'U')
        {
            y += 1;
        } else {
            y -= 1;
        }

        pair<int, int> p = make_pair(x, y);

        if (st.count(p))
        {
            cout << "Yes" << endl;
            return 0;
        }

        st.insert(make_pair(x, y));
    }

    cout << "No" << endl;

    return 0;
}