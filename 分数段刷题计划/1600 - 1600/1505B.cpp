#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (true)
    {
        int temp = 0;
        while (n > 0)
        {
            temp += n % 10;
            n /= 10;
        }

        n = temp;
        if (n < 10)
        {
            break;
        }
    }

    cout << n << endl;

    return 0;
}