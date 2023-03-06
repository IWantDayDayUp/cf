#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    if (n <= 5)
    {
        set<string> st;
        st.insert(s);

        queue<string> q;
        q.push(s);

        auto add = [&](string &ss, int i, int j)
        {
            if (i >= 0 && i < j && j < n)
            {
                swap(ss[i], ss[j]);
                if (!st.count(ss))
                {
                    st.insert(ss);
                    q.push(ss);
                }                
                swap(ss[i], ss[j]);                
            }
        };

        while (!q.empty())
        {
            string cur = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                add(cur, i, i + k);
                add(cur, i, i + k + 1);
                add(cur, i - k, i);
                add(cur, i - k - 1, i);
            }
        }

        cout << (st.count(t) ? "YES" : "NO") << endl;
    } else {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        cout << (s == t ? "YES" : "NO") << endl;
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