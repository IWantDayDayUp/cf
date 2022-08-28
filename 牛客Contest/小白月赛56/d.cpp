#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 2e5;

int n, q, a[N];
bool p[N * 20];
int pre[N];
set<int> st;

// 第2e5个质数 2750159
// 至少要第2e5+1个质数

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(p, true, sizeof(p));
    p[1] = false;
    for (int i = 2; i < N * 20; ++i) {
        if (p[i]) {
            for (int j = i + i; j < N * 20; j += i) {
                p[j] = false;
            }
        }
    }

    int now = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < N * 20 && p[a[i]]) st.insert(a[i]);
        while (!p[now] || st.count(now)) ++now;
        pre[i] = now;
    }

    while (q--) {
        int x;
        cin >> x;
        cout << pre[x] << endl;
    }

    return 0;
}