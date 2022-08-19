#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, cnt01 = 0, gcd = 0, cnt0 = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        gcd = __gcd(gcd, a);
        if(a == 1){
            cnt01++;
        }
        if(a == 0){
            cnt01++;
            cnt0++;
        }
    }
    if(cnt0 == n)
    {
        cout << 0 << endl;
    } else if (cnt01 == n || gcd >= 2)
    {
        cout << 1 << endl;
    } else 
    {
        cout << 2 << endl;
    }

    return 0;
}