#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string ans = "";
    for (int i = 0; i < n / 4; i++)
    {
        ans += "aabb";
    }

    int left = n % 4;
    for (int i = 0; i < min(left, 2); i++)
    {
        ans += 'a';
    }
    left -= 2;
    if (left > 0)
    {
        ans += 'b';
    }

    cout << ans << endl;

    return 0;
}