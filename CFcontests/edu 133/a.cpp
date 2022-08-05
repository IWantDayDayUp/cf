#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n;
    cin >> n;

    long long ans = 0;
    if (n == 1)
    {
        ans = 2;
    } else if (n % 3 == 0)
    {
        ans = n / 3;
    } else {
        ans = (n + 2) / 3;
    }

    cout << ans << endl;
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