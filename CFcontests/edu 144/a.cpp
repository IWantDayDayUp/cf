#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string t = "";
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            t += 'F';
        }
        if (i % 5 == 0)
        {
            t += 'B';
        }
    }

    if (t.find(s) != -1)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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