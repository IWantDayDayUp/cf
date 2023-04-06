#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    set<long long> st;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        st.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (st.find(a[i] + k) != st.end())
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}