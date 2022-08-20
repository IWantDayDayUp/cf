#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    long long ans = 9223372036854775807;

    ans ^= (a ^ b);

    cout << ans << endl;

    return 0;
}