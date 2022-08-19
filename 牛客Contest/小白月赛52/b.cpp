#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s = to_string(n);
    s = '0' + s;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= '5')
        {
            for (int j = i; j < s.size(); j++)
            {
                s[j] = '0';
            }

            s[i - 1] += 1;

            while (i - 1 > 0 && s[i - 1] >= '5')
            {
                s[i - 2] += 1;
                s[i - 1] = '0';

                i -= 1;
            }

            break;
        }
    }

    if (s[0] > '0')
    {
        cout << s << endl;
    } else {
        cout << s.substr(1) << endl;
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