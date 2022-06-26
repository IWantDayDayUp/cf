#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto modified = [&](string s, int n, int k)
    {
        string result_prefix = s.substr(k - 1, n - k + 1);
        string result_suffix = s.substr(0, k - 1);
        if (n % 2 == k % 2)
        {
            reverse(result_suffix.begin(), result_suffix.end());
        }

        return result_prefix + result_suffix;
    };

    string best_s = modified(s, n, 1);
    int best_k = 1;
    for (int k = 2; k <= n; ++k) {
        string temp = modified(s, n, k);
        if (temp < best_s) {
            best_s = temp;
            best_k = k;
        }
    }
    cout << best_s << '\n' << best_k << '\n';
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