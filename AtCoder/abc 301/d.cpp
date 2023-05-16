#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    long long N;
    cin >> s >> N;

    int n = s.size();

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans += 1ll << (n - i - 1);
        }
    }

    if (ans > N)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?')
        {
            continue;
        }

        if (ans + (1ll << (n - i - 1)) <= N)
        {
            ans += 1ll << (n - i - 1);
        }
    }

    cout << ans << endl;

    return 0;
}