#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string cur;
        cin >> cur;

        if (mp.empty() || !mp.count(cur))
        {
            cout << cur << endl;
        } else {
            cout << cur << '(' << mp[cur] << ')' << endl;
        }

        mp[cur] += 1;
    }

    return 0;
}