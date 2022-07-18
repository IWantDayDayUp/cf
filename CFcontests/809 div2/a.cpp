#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        num = min(num, m + 1 - num);

        if (st.count(num))
        {
            st.insert(m + 1 - num);
        } else {
            st.insert(num);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (st.count(i + 1))
        {
            cout << 'A';
        } else {
            cout << 'B';
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