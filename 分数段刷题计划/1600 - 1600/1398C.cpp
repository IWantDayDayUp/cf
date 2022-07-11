#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> prefix(n + 1);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + (s[i] - '1');
    }

    long long ans = 0;
    map<int, int> mp;
    for (int i = 0; i <= n; i++)
    {
        ans += mp[prefix[i]]++;
    }

    cout << ans << endl;
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