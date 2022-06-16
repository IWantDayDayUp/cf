#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        st.insert(temp);
    }

    int ans = 0;
    if ((n - st.size()) % 2 == 0)
    {
        ans = st.size();
    } else {
        ans = st.size() - 1;
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