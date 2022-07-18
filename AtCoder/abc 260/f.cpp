#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int S, T, M;
    cin >> S >> T >> M;

    vector<vector<int>> adj(S);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - S - 1);
    }

    vector dp(T, vector(T, -1));
    for (int i = 0; i < S; i++) {
        for (auto& u : adj[i]) {
            for (auto& v : adj[i]) {
                if (u == v) continue;

                if (dp[u][v] != -1) {
                    cout << i + 1 << " " << dp[u][v] + 1 << " ";
                    cout << u + S + 1 << " " << v + S + 1 << endl;
                    exit(0);
                }
                dp[u][v] = i;
            }
        }
    }
    cout << "-1" << endl;

    return 0;
}