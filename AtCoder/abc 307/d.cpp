#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> idx;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            idx.emplace_back(i);
            st.emplace(i);
        } else if (s[i] == ')')
        {
            if (!st.empty())
            {
                int temp = st.top();
                st.pop();

                while (!idx.empty() && idx.back() >= temp)
                {
                    idx.pop_back();
                }
            } else {
                idx.emplace_back(i);
            }
        } else {
            idx.emplace_back(i);
        }
    }

    string ans = "";
    for (auto & i : idx)
    {
        ans += s[i];
    }

    cout << ans << endl;

    return 0;
}