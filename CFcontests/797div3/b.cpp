#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        int temp = a[i] - b[i];
        if (temp < 0)
        {
            cout << "NO" << endl;
            return;
        }
        diff[i] = temp;
    }
    int need = *max_element(diff.begin(), diff.end());
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            if (a[i] - need > 0)
            {
                cout << "NO" << endl;
                return;
            }
        } else {
            if (a[i] - need != b[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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