#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n = 0;
    cin >> n;

    if (n > 19){
        cout << 'NO'<< endl;
    } else {
        cout << 'YES' << endl;
        for (int i = 0; i < n; i++){
            cout << pow(3, i) << ' ';
        }
    }

    // i64 ans = (1 << n) - 1;
    // cout << ans << endl;
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