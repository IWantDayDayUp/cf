#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h, k;
    cin >> n >> m >> h >> k;

    string s;
    cin >> s;

    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        st.insert(make_pair(x, y));
    }

    int x = 0, y = 0;
    for (auto & c : s)
    {
        if (c == 'R')
        {
            x += 1;
        } else if (c == 'L')
        {
            x -= 1;
        } else if(c == 'U')
        {
            y += 1;
        } else {
            y -= 1;
        }

        h -= 1;

        if (h == -1)
        {
            cout << "No" << endl;
            return 0;
        }

        if (st.count(make_pair(x, y)))
        {
            if (h < k)
            {
                st.erase(make_pair(x, y));
            }
            h = max(k, h);
        }
    }

    cout << "Yes" << endl;

    return 0;
}