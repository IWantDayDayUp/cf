#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> c(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }

    
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