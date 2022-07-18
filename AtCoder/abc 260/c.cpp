#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x, y;
    cin >> n >> x >> y;

    long long ans = 0;

    vector<long long> red(n + 1), blue(n + 1);
    red[n] = 1;

    while (n >= 2)
    {
        red[n - 1] += red[n];
        blue[n] += x * red[n];

        red[n - 1] += blue[n];
        blue[n - 1] += y * blue[n];

        n -= 1;
    }

    cout << blue[1] << endl;
    
    return 0;
}