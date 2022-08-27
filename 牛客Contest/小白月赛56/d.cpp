#include <bits/stdc++.h>

using namespace std;

// C++ Version
bool isPrime(int a) {
    if (a < 2) return 0;

    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0) return 0;

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    set<int> st;
    for (int i = 1; i <= 1e9; i++)
    {
        if (isPrime(i))
        {
            st.insert(i);
        }
    }

    vector<int> a(n);
    set<int> st1;
    vector<int> cnt(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (isPrime(a[i]))
        {
            st1.insert(a[i]);
        }

        if (st1.size() == 0)
        {
            cnt[i] = *st.begin();
        } else {
            while (st1.count(*st.begin()))
            {
                st.erase(st.begin());
            }

            cnt[i] = *st.begin();
        }
    }

    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        ans[i] = cnt[x - 1];
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}