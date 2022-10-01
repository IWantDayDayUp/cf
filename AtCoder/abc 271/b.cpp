#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            int cur;
            cin >> cur;

            mp[i].emplace_back(cur);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;

        cout << mp[s - 1][t - 1] << endl;
    }

    return 0;
}