#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int res = 0;
    set<int> s;
    int tag = 0;
    s.insert(0);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        if (x == 0 || s.count(x ^ tag)) 
        {
            s.clear();
            s.insert(0);
            tag = 0;
        }
        else 
        {
            s.insert(tag);
            tag ^= x;
            res++;
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}