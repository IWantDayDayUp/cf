#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> st;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.count(a[i]))
        {
            ans = i + 1;
            break;
        } else {
            st.insert(a[i]);
        }
    }

    cout << ans << endl;
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