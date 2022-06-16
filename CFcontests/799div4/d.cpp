#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    int x;
    cin >> s;
    cin >> x;
    x = std::gcd(x, 1440);

    int total = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    total %= x;

    int ans = 0;
    while (total < 1440)
    {
        int a = total /600;
        int b = total / 60 % 10;
        int c = total / 10 % 6;
        int d = total % 10;

        if (a == d && b == c)
        {
            ans += 1;
        }

        total += x;
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