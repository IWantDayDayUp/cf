#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    if (c > a)
    {
        cout << n / a << endl;
    } else {
        int cnt = min((n - b) / c, (n - c) / b);
        cout << (n - cnt * c) / a + cnt << endl;
    }

    return 0;
}