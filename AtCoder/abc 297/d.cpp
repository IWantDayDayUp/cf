#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    while (a != b)
    {
        if (a < b)
        {
            ans += (b - 1) / a;
            b -= (b - 1) / a * a;
        } else {
            ans += (a - 1) / b;
            a -= (a - 1) / b * b;
        }
    }

    cout << ans << endl;

    return 0;
}