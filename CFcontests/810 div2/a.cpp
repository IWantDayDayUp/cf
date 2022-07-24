#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<int> ans(n);

    if (n == 1)
    {
        cout << 1 << endl;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i % n + 1 << " \n"[i == n];
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