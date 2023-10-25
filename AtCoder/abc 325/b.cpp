#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> num(24);
    for (int i = 0; i < n; i++)
    {
        long long w, x;
        cin >> w >> x;

        num[x] += w;
    }

    long long ans = -1;

    for (int i = 0; i < 24; i++)
    {
        long long temp = 0;
        for (int j = 0; j < 9; j++)
        {
            temp += num[(i + j) % 24];
        }

        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}