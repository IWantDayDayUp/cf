#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
    int m;
    cin >> m;
    vector<i64> shuffle(m);
    i64 s = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> shuffle[i];
        s += shuffle[i];
    }

    s = s % n;
    cout << cards[s] << endl;
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