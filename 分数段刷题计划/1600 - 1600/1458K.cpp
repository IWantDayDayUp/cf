#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    set<pair<int, int>> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            y -= 1;
        } else if (s[i] == 'R')
        {
            y += 1;
        } else if (s[i] == 'U')
        {
            x += 1;
        } else {
            x -= 1;
        }

        st.insert(make_pair(x, y));
    }

    for (auto & p : st)
    {
        int nx = p.first;
        int ny = p.second;

        if (nx == 0 && ny == 0) continue;

        x = 0, y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int xx = x, yy = y;

            if (s[i] == 'L')
            {
                yy -= 1;
            } else if (s[i] == 'R')
            {
                yy += 1;
            } else if (s[i] == 'U')
            {
                xx += 1;
            } else {
                xx -= 1;
            }

            if (xx == nx && yy == ny)
            {
                continue;
            } else {
                x = xx;
                y = yy;
            }
        }

        if (x == 0 && y == 0)
        {
            cout << ny << ' ' << nx << endl;
            return ;
        }
    }

    cout << 0 << ' ' << 0 << endl;
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