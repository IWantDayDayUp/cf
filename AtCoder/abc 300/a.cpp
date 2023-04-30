#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;

        mp[c] = i;
    }

    cout << mp[a + b] << endl;

    return 0;
}