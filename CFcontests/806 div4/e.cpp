#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int zero = 0, one = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = 0;
                int ny = 0;

                if (k == 0)
                {
                    nx = i;
                    ny = j;
                } else if (k == 1) {
                    nx = n - 1 - j;
                    ny = i;
                } else if (k == 2) {
                    nx = n - 1 - i;
                    ny = n - 1 - j;
                } else {
                    nx = j;
                    ny = n - 1 - i;
                }

                // cout << i << ' ' << j << ' ' << nx << ' ' << ny << endl;

                zero += grid[nx][ny] == '0';
                one += grid[nx][ny] == '1';
            }

            // cout << i << ' ' << j << ' ' << zero << ' ' << one << endl;

            ans += min(zero, one);
        }
    }

    cout << ans << endl;
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