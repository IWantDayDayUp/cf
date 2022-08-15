#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if (s == "atcoder")
    {
        cout << 0 << endl;
        return 0;
    }

    set<string> st;
    st.insert(s);

    queue<string> q;
    q.emplace(s);

    int ans = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int k = 0; k < len; k++)
        {
            // cout << cur << endl;
            string cur = q.front();
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                string temp = cur;
                swap(temp[i], temp[i + 1]);

                // cout << temp << endl;

                if (temp == "atcoder")
                {
                    cout << ans + 1 << endl;
                    return 0;
                }

                if (!st.count(temp))
                {
                    q.emplace(temp);
                    st.insert(temp);
                }
            }
        }

        ans += 1;
    }

    return 0;
}