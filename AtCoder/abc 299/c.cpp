#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    if (s.find('-') == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    s = '-' + s + '-';

    int ans = -1;

    int pre = 0;
    for (int i = 1; i < n + 2; i++)
    {
        if (s[i] == '-')
        {
            ans = max(ans, i - pre - 1);
            pre = i;
        }
    }

    cout << (ans <= 0 ? -1 : ans) << endl;

    return 0;
}