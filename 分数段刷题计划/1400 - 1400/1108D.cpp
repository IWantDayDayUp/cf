#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            ans += 1;

            if (i == n - 1)
            {
                // 不用考虑后面
                if (s[i - 1] == 'R')
                {
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            } else {
                // 考虑后面
                if (s[i - 1] == s[i + 1])
                {
                    if (s[i - 1] == 'R')
                    {
                        s[i] = 'B';
                    } else {
                        s[i] = 'R';
                    }
                } else {
                    if (s[i - 1] == 'R')
                    {
                        if (s[i + 1] == 'B')
                        {
                            s[i] = 'G';
                        } else {
                            s[i] = 'B';
                        }
                    } else if (s[i - 1] == 'G'){
                        if (s[i + 1] == 'B')
                        {
                            s[i] = 'R';
                        } else {
                            s[i] = 'B';
                        }
                    } else {
                        if (s[i + 1] == 'G')
                        {
                            s[i] = 'R';
                        } else {
                            s[i] = 'G';
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    cout << s << endl;

    return 0;
}