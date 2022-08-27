#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;
    while (l < s.size() && s[l] == 'z')
    {
        l += 1;
    }
    if (l == s.size())
    {
        cout << 0 << endl;
        return 0;
    }

    while (r >= 0 && s[r] == 'z')
    {
        r -= 1;
    }
    if (r == -1)
    {
        cout << 0 << endl;
        return 0;
    }

    if (l == r)
    {
        cout << 0 << endl;
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    long long ans = 0;
    int temp = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == 'Z')
        {
            if (temp > 0)
            {
                q.emplace(temp);
                temp = 0;
            }
        } else {
            temp += 1;
        }

        if (i > 0 && s[i] == 'Z' && s[i - 1] == 'Z')
        {
            ans += 4;
        }
    }

    while (!q.empty())
    {
        int cur = q.top();
        q.pop();

        if (k >= cur)
        {
            k -= cur;
            ans += 4;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}