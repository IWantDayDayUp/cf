#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    vector<string> grid;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        grid.emplace_back(s);
    }

    auto check = [&](int x, int y)
    {
        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, -1, 1};
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            if (grid[x + dx[i]][y + dy[i]] == '#')
            {
                cnt += 1;
            }
        }

        return cnt == 4;
    };

    for (int i = 1; i < 7; i++)
    {
        for (int  j = 1; j < 7; j++)
        {
            if (check(i, j))
            {
                cout << i + 1 << ' ' << j + 1 << endl;
                return ;
            }
        }
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