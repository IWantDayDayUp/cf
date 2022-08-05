#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            swap(ans[i - 1], ans[i]);
        }

        for (int j = 0; j < n; j++)
        {
            cout << ans[j] << " \n"[j == n - 1];
        }
    }
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