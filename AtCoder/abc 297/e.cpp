#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<long long> st;
    st.insert(0);

    for (int i = 0; i < k; i++)
    {
        long long cur = *st.begin();
        st.erase(cur);
        
        for (int i = 0; i < n; i++)
        {
            st.insert(cur + a[i]);
        }
    }

    cout << *st.begin() << endl;

    return 0;
}