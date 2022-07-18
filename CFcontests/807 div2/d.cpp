#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    long long ans = n + 1;
    function<void(string, int, long long)> bfs = [&](string s, int p, long long cur)
    {
        if (s[p] == '0')
        {
            s[p] = '1';
        } else {
            s[p] = '0';
        }

        if (s == s2)
        {
            ans = min(ans, cur);
            return ;
        }

        int temp = p + 1;
        while (temp < n - 1)
        {
            if (s[temp - 1] != s[temp + 1])
            {
                bfs(s, temp, cur + 1);
            }
            temp += 1;
        }

        temp = p - 1;
        while (temp >= 1)
        {
            if (s[temp - 1] != s[temp + 1])
            {
                bfs(s, temp, cur + 1);
            }
            temp -= 1;
        }
    };

    for (int i = 1; i < n - 1; i++)
    {
        if (s1[i - 1] != s1[i + 1])
        {
            bfs(s1, i, 1);
        }
    }

    cout << (ans == n + 1 ? -1 : ans) << endl;
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