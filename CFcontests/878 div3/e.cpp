#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();

    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        bad += s[i] != t[i];
    }

    queue<pair<int, int>> unblock;

    int T, q;
    cin >> T >> q;

    for (int i = 0; i < q; i++)
    {
        while (!unblock.empty() && unblock.front().first == i)
        {
            bad += s[unblock.front().second] != t[unblock.front().second];
            unblock.pop();
        }

        int type;
        cin >> type;

        if (type == 1)
        {
            int pos;
            cin >> pos;
            pos--;

            bad -= s[pos] != t[pos];
            unblock.emplace(i + T, pos);
        } else if (type == 2)
        {
            int num1, pos1, num2, pos2;
            cin >> num1 >> pos1 >> num2 >> pos2;
            num1--;
            pos1--;
            num2--;
            pos2--;

            bad -= s[pos1] != t[pos1];
            bad -= s[pos2] != t[pos2];

            swap((num1 == 0 ? s[pos1] : t[pos1]), (num2 == 0 ? s[pos2] : t[pos2]));

            bad += s[pos1] != t[pos1];
            bad += s[pos2] != t[pos2];
        } else {
            cout << (!bad ? "YES" : "NO") << endl;
        }
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