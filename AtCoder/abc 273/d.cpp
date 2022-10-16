#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, r, c;
    cin >> h >> w >> r >> c;
    r--;
    c--;
    
    int n;
    cin >> n;
    map<int, set<int>> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        mp1[x].insert(y);
        mp2[y].insert(x);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char dir;
        int l;
        cin >> dir >> l;

        if (dir == 'U')
        {
            auto it = mp2[c].upper_bound(r);
            if (it == mp2[c].begin())
            {
                r = max(0, r - l);
            } else {
                // cout << temp << endl;
                r = max(*prev(it) + 1, r - l);
            }
        } else if (dir == 'D')
        {
            auto it = mp2[c].upper_bound(r);
            // cout << it << endl;
            if (it == mp2[c].end())
            {
                r = min(h - 1, r + l);
            } else {
                // cout << temp << endl;
                r = min(*it - 1, r + l);
            }
        } else if (dir == 'L')
        {
            auto it = mp1[r].upper_bound(c);
            // cout << it << endl;
            if (it == mp1[r].begin())
            {
                c = max(0, c - l);
            } else {
                // cout << temp << endl;
                c = max(*prev(it) + 1, c - l);
            }
        } else if (dir == 'R')
        {
            auto it = mp1[r].upper_bound(c);
            // cout << it << endl;
            if (it == mp1[r].end())
            {
                c = min(w - 1, c + l);
            } else {
                // cout << temp << endl;
                c = min(*it - 1, c + l);
            }
        }

        cout << r + 1 << ' ' << c + 1 << endl;
    }

    return 0;
}