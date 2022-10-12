#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    auto calc = [&](string temp)
    {
        long long ans = 0;
        int n = temp.size();
        reverse(temp.begin(), temp.end());
        long long pre = 1;

        for (auto & c : temp)
        {
            if (c == 'S')
            {
                pre = -1;
                ans += -1;
            } else if (c == 'M')
            {
                ans += 1000;
                pre = 1000;
            } else if (c == 'L')
            {
                ans += 1e6;
                pre = 1e6;
            } else if (c == 'X')
            {
                ans += pre;
            }
        }

        return ans;
    };

    long long a = calc(s);
    long long b = calc(t);
    // cout << a << ' ' << b << endl;

    if (a == b)
    {
        cout << "=" << endl;
    } else if (a > b)
    {
        cout << ">" << endl;
    } else {
        cout << "<" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}