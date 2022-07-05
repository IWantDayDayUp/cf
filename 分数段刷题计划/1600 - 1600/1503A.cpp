#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = count(s.begin(), s.end(), '1');
    if (s[0] == '0' || s[n - 1] == '0' || count(s.begin(), s.end(), '0') % 2 != 0)
    {
        cout << "NO" << endl;
    } else {
        string s1, s2;
        int k = 0, p = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (k < cnt / 2)
                {
                    s1 += '(';
                    s2 += '(';
                } else {
                    s1 += ')';
                    s2 += ')';
                }
                k += 1;
            } else {
                if (p % 2 == 0)
                {
                    s1 += '(';
                    s2 += ')';
                } else {
                    s1 += ')';
                    s2 += '(';
                }
                p += 1;
            }
        }

        cout << "YES" << endl;
        cout << s1 << endl;
        cout << s2 << endl;
    }
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