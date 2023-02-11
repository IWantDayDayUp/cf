#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt;
    cin >> n >> cnt;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.begin() + cnt);

    for (int i = 0; i < cnt; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}