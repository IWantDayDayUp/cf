#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    auto calc = [&](string s)
    {
        int ans = count(s.begin(), s.end(), '0');
        bool zero = false, one = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                zero = true;
            }
            if (s[i] == '1')
            {
                one = true;
            }
            if (zero && one)
            {
                ans += 1;
                zero = false;
                one = false;
            }
        }

        return ans;
    };

    string temp = "";
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            ans += 2 + calc(temp);
            temp = "";
        } else {
            temp += s1[i];
        }
    }

    cout << ans + calc(temp) << endl;
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