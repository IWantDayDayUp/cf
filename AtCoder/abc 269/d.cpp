#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<long long> st;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;

        x += 1000;
        y += 1000;

        st.insert(x * 2000 + y);
    }

    int dx[6] = {-1, -1, 0, 0, 1, 1};
    int dy[6] = {-1, 0, -1, 1, 0, 1};

    int ans = 0;
    while (st.size() > 0)
    {
        auto p = *st.begin();
        // cout << p.first << ' ' << p.second << endl;
        st.erase(p);

        queue<long long> q;
        q.emplace(p);

        while (!q.empty())
        {
            int x = q.front() / 2000, y = q.front() % 2000;
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                long long cur = nx * 2000 + ny;

                if (st.count(cur))
                {
                    st.erase(cur);
                    q.emplace(cur);
                }
            }
        }

        ans += 1;
    }

    cout << ans << endl;

    return 0;
}