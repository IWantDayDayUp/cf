#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.insert(num);
    }

    cout << (st.size() == n ? "NO" : "YES") << endl;
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