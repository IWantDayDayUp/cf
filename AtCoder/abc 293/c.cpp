#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> grid(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    string s = string(h - 1, '1') + string(w - 1, '2');

    int ans = 0;

    do {
        int x = 0, y = 0;

        set<int> st;
        st.insert(grid[x][y]);

        for (auto c : s)
        {
            if (c == '1')
            {
                x += 1;
            } else {
                y += 1;
            }

            st.insert(grid[x][y]);
        }

        ans += st.size() == h + w - 1;

        // cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;

    return 0;
}