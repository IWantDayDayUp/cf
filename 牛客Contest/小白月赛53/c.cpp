#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n;
    cin >> n;

    map<int, vector<string>> mp;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;

        if (s.size() != t.size())
        {
            mp[0].emplace_back(t);
            mx = max(mx, 0);
        } else {
            int k = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == t[j])
                {
                    k += 1;
                }
            }
            mp[k].emplace_back(t);

            mx = max(mx, k);
        }
    }

    vector<string> ans = mp[mx];
    sort(ans.begin(), ans.end());

    for (auto & p : ans)
    {
        cout << p << endl;
    }

    return 0;
}