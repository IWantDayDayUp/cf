#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long x = 0, y = 0;
    long long prex = 0, prey = 0;
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long nx = x;
        long long ny = y;

        if (s[i] == 'U')
        {
            nx += 1;
        } else if (s[i] == 'D')
        {
            nx -= 1;
        } else if (s[i] == 'L')
        {
            ny -= 1;
        } else if (s[i] == 'R')
        {
            ny += 1;
        }

        cnt += 1;

        if (abs(nx - prex) + abs(ny - prey) < cnt)
        {
            ans += 1;
            prex = x;
            prey = y;
            cnt = 1;
        }

        if (i == n - 1)
        {
            ans += 1;
        }

        // cout << nx << ' ' << ny << ' ' << cnt << endl;
        x = nx;
        y = ny;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}