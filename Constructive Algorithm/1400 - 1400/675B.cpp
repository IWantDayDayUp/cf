#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        int y = x + b - c;
        int z = x + a - d;
        int w = a + y - d;
        if (1 <= y && y <= n && 1 <= z && z <= n && 1 <= w && w <= n)
        {
            ans++;
        }
    }
    ans *= n;

    cout << ans << endl;

    return 0;
}