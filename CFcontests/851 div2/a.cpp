#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt += a[i] == 2;
    }

    if (cnt & 1){
        cout << -1 << endl;
    } else {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += a[i] == 2;

            if (temp == cnt / 2)
            {
                cout << i + 1 << endl;
                return ;
            }
        }
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