#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1 || s[n - 1] == 'A')
    {
        cout << "NO" << endl;
        return;
    }
    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            cntA ++;
        } else {
            cntB ++;
        }
        if (cntA < cntB)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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