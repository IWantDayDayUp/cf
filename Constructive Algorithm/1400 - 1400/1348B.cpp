#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.insert(num);
    }

    if (st.size() > k)
    {
        cout << -1 << endl;
        return ;
    }

    cout << n * k << endl;
    for (int i = 0; i < n; i++)
    {
        for (auto & num : st)
        {
            cout << num << ' ';
        }
        for (int i = 0; i < k - (int)st.size(); i++)
        {
            cout << 1 << ' ';
        }
    }
    cout << endl;
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