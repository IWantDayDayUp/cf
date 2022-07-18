#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    map<int, set<string>> mp;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        words[i] = temp;

        mp[temp.size()].insert(temp);
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        bool ok = false;
        for (int j = 0; j < words[i].size() - 1; j++)
        {
            string s1 = words[i].substr(0, j + 1);
            string s2 = words[i].substr(j + 1);

            // cout << words[i] << ' ' << s1 << ' ' << s2 << endl;

            if (mp[s1.size()].count(s1) && mp[s2.size()].count(s2))
            {
                ok = true;
                // break;
            }
        }

        if (ok)
        {
            ans += '1';
        } else {
            ans += '0';
        }
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