#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++)
    {
        cin >> grid[i];
    }

    int all = 0;
    vector<int> row(r, 0), col(c, 0);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            all += grid[i][j] == 'A';
            row[i] += grid[i][j] == 'A';
            col[j] += grid[i][j] == 'A';
        }
    }

    if (all == 0)
    {
        cout << "MORTAL" << endl;
    } else if (all == r * c)
    {
        cout << 0 << endl;
    } else if (row[0] == c || row[r - 1] == c || col[0] == r || col[c - 1] == r)
    {
        cout << 1 << endl;
    } else if (grid[0][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[r - 1][c - 1] == 'A')
    {
        cout << 2 << endl;
    } 
    else if (*max_element(row.begin(), row.end()) == c || *max_element(col.begin(), col.end()) == r)
    {
        cout << 2 << endl;
    } else if (row[0] || row[r - 1] || col[0] || col[c - 1])
    {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }
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