#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if (n > a * b)
    {
        cout << -1 << endl;
    } else {
        vector<vector<int>> grid(a, vector<int>(b, 0));
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (i * b + j + 1 <= n)
                {
                    grid[i][j] = i * b + j + 1;
                } else {
                    break;
                }
            }
            if (b % 2 == 0 && i % 2 == 1 && grid[i][0] > 0)
            {
                for (int j = 0; j < b - 1; j++)
                {
                    swap(grid[i][j], grid[i][j + 1]);
                }
            }
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout << grid[i][j] << " \n"[j == b - 1];
            }
        }
    }

    return 0;
}