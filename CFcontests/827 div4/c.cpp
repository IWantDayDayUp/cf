#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<string> grid(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < 8; i++)
    {
        if (grid[i] == string(8, 'R'))
        {
            cout << "R" << endl;
            return ;
        }
    }

    cout << "B" << endl;
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