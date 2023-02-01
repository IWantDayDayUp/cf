#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        if (a.empty() || *(a.end() - 1) != num)
        {
            a.emplace_back(num);
        }
    }

    bool ok = false;
    n = a.size();
    // cout << n << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " \n"[i == n - 1];
    // }

    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] < a[i + 1])
            {
                if (ok)
                {
                    cout << "NO" << endl;
                    return;
                } else {
                    ok = true;
                }
            }
        } else if (i == n - 1){
            if (a[i - 1] > a[i])
            {
                if (ok)
                {
                    cout << "NO" << endl;
                    return;
                } else {
                    ok = true;
                }
            }
        } else {
            if (a[i - 1] > a[i] && a[i] < a[i + 1])
            {
                if (ok)
                {
                    cout << "NO" << endl;
                    return;
                } else {
                    ok = true;
                }
            }
        }
    }

    if (ok) 
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}