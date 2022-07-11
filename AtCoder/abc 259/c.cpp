#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << "Yes" << endl;
    } else if (s.size() >= t.size())
    {
        cout << "No" << endl;
    } else {
        auto get = [&](string ss)
        {
            vector<pair<char, int>> ans;
            // char pre = ss[0];
            ss += '.';

            int n = ss.size();
            int cnt = 1;
            for (int i = 1; i < n; i++)
            {
                if (ss[i] == ss[i - 1])
                {
                    cnt += 1;
                } else {
                    ans.emplace_back(make_pair(ss[i - 1], cnt));
                    cnt = 1;
                    // pre = ss[i];
                }
            }

            return ans;
        };

        auto a = get(s);
        auto b = get(t);

        if ((int)a.size() != (int)b.size())
        {
            cout << "No" << endl;
        } else {
            for (int i = 0; i < (int)a.size(); i++)
            {
                if (a[i].first != b[i].first || a[i].second > b[i].second || (a[i].second == 1 && b[i].second != 1))
                {
                    cout << "No" << endl;
                    return 0;
                }
            }

            cout << "Yes" << endl;
        }
    }

    return 0;
}