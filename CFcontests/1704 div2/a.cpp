#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if (m == 1)
    {
        if (s.find(t) != -1)
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (s.substr(n - 1 - (m - 1) + 1, m - 1) == t.substr(1, m - 1) && s.substr(0, n - m + 1).find(t[0]) != -1)
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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