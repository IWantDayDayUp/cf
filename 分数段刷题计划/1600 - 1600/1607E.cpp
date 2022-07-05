#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    auto inside = [&](int u, int d, int l, int r)
    {
        return u + d < n && l + r < m;
    };

    int up = 0, down = 0, left = 0, right = 0;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'U')
        {
            x -= 1;
            up = max(up, -x);
        } else if (s[i] == 'D')
        {
            x += 1;
            down = max(down, x);        
        } else if (s[i] == 'L')
        {
            y -= 1;
            left = max(left, -y);
        } else {
            y += 1;
            right = max(right, y);
        }
        if (!inside(up, down, left, right)) 
        {
            up -= s[i] == 'U' ? 1 : 0;
            down -= s[i] == 'D' ? 1 : 0;
            left -= s[i] == 'L' ? 1 : 0;
            right -= s[i] == 'R' ? 1 : 0;
            break;
        }
    }

    cout << up + 1 << ' ' << left + 1 << endl;
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