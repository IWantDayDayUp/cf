#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;

    if (n % 2 == m % 2)
    {
        cout << "Tonya" << endl;
    } else {
        cout << "Burenka" << endl;
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