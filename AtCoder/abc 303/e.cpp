#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> deg(n, 0);
    vector<bool> alive(n, true);
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        deg[i] = (int)adj[i].size();
        // st.insert(deg[i], i);
        st.insert(make_pair(deg[i], i));
    }

    vector<int> ans;

    while (!st.empty())
    {
        int u = st.begin() -> second;

        for (auto & v : adj[u])
        {
            if (alive[v])
            {
                u = v;
                break;
            }
        }

        vector<int> rm(1, u);
        for (auto & v : adj[u])
        {
            if (alive[v])
            {
                rm.push_back(v);
            }
        }

        ans.push_back(rm.size() - 1);

        for (auto v : rm)
        {
            alive[v] = false;
            st.erase({deg[v], v});
            for (auto & w : adj[v])
            {
                if (alive[w])
                {
                    st.erase({deg[w], w});
                    deg[w] -= 1;
                    // st.insert(deg[w], w);
                    st.insert(make_pair(deg[w], w));
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << ' ';
    }

    return 0;
}