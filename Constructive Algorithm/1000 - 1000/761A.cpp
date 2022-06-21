#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << (abs(a - b) <= 1 and a + b >= 1 ? "YES" : "NO") << endl;

    return 0;
}