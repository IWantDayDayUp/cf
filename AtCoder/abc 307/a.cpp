#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            long long step;
            cin >> step;

            ans[i] += step;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}