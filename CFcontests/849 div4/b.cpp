#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int x = 0, y = 0;
    for (auto c : s)
    {
        if (c == 'L')
        {
            x -= 1;
        } else if (c == 'R')
        {
            x += 1;
        } else if (c == 'U')
        {
            y += 1;
        } else {
            y -= 1;
        }

        if (x == 1 && y == 1)
        {
            cout << "YES" << endl;
            return ;
        }
    }

    cout << "NO" << endl;
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