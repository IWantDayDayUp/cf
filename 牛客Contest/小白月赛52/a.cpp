#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s[0] == '8')
        {
            if (s[2] >= '1' || s[3] > '5')
            {
                cnt2 += 1;
            } else if (s[3] > '0'){
                cnt1 += 1;
            }
        } else if (s[0] == '9')
        {
            cnt2 += 1;
        }
    }

    cout << cnt1 << ' ' << cnt2 << endl;
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