#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
        {
            if (i == 0)
            {
                if (s[i + 1] == 'a')
                {
                    s[i] = 'b';
                } else {
                    s[i] = 'a';
                }
            } else if (i == s.size() - 1)
            {
                if (s[i - 1] == 'a')
                {
                    s[i] = 'b';
                } else {
                    s[i] = 'a';
                }
            } else {
                if (s[i - 1] == 'a')
                {
                    if (s[i + 1] == 'b')
                    {
                        s[i] = 'c';
                    } else {
                        s[i] = 'b';
                    }
                } else {
                    if (s[i + 1] == 'a')
                    {
                        if (s[i - 1] == 'b')
                        {
                            s[i] = 'c';
                        } else {
                            s[i] = 'b';
                        }
                    } else {
                        s[i] = 'a';
                    }
                }
            }
        }
    }

    bool ok = true;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == s[i])
        {
            ok = false;
        }
    }

    if (ok)
    {
        cout << s << endl;
    } else {
        cout << -1 << endl;
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