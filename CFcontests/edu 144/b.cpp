#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    if (a.front() == b.front())
    {
        cout << "YES" << endl;
        cout << a[0] << "*" << endl;
        return ;
    }

    if (a.back() == b.back())
    {
        cout << "YES" << endl;
        cout << "*" << a.back() << endl;
        return ;
    }

    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < b.size() - 1; j++)
        {
            if (a[i] == b[j] && a[i + 1] == b[j + 1])
            {
                cout << "YES" << endl;
                cout << "*" << a[i] << a[i + 1] << "*" << endl;
                return ;
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}