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

    if (n % 2 == 0)
    {
        for (int i = 0; i + 1 < n; i+=2)
        {
            swap(ans[i], ans[i + 1]);
        }
    } else {
        for (int i = 1; i + 1 < n; i+=2)
        {
            swap(ans[i], ans[i + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
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