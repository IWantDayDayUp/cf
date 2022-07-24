#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            char c1 = grid[i][j];
            char c2 = grid[j][i];

            if (c1 == 'W')
            {
                if (c2 != 'L')
                {
                    ok = false;
                }
            } else if (c1 == 'L')
            {
                if (c2 != 'W')
                {
                    ok = false;
                }
            } else {
                if (c2 != 'D')
                {
                    ok = false;
                }
            }
        }
    }

    cout << (ok ? "correct" : "incorrect") << endl;

    return 0;
}