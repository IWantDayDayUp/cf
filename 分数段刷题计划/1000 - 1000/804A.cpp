#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2 - 1 << endl;
    } else {
        cout << n / 2 << endl;
    }

    return 0;
}