#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
    }

    cout << 2 * (n - 1) + (n + 1) * (m - 1) << endl;

    string s = string(n - 1, 'U');
    s += string(m - 1, 'L');
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            s += 'D';
        }
        if (i % 2 == 0)
        {
            s += string(m - 1, 'R');
        } else {
            s += string(m - 1, 'L');
        }
    }

    cout << s << endl;


    return 0;
}