#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int hour, minute;
        cin >> hour >> minute;

        a[i] = hour * 60 + minute;
    }
    sort(a.begin(), a.end());

    int cur = h * 60 + m;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= cur)
        {
            int left = a[i] - cur;
            cout << left / 60 << ' ' << left % 60 << endl;
            return ;
        }
    }

    int ans = 1440 - cur + a[0];
    cout << ans / 60 << ' ' << ans % 60 << endl;
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