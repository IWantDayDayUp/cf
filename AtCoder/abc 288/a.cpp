#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> ans(n);
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;

        ans[i] = a + b;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}