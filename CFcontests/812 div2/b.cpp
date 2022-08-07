#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        ans += max(0ll, a[i] - (i == 0 ? 0ll : a[i - 1]));
    }

    if (ans == *max_element(a.begin(), a.end()))
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
        slove();
    }

    return 0;
}