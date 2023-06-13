#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }

    int maxh = 0, minh = h, maxw = 0, minw = w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                maxh = max(maxh, i);
                minh = min(minh, i);
                maxw = max(maxw, j);
                minw = min(minw, j);
            }
        }
    }

    for (int i = minh; i <= maxh; i++)
    {
        for (int j = minw; j <= maxw; j++)
        {
            if (grid[i][j] == '.')
            {
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}