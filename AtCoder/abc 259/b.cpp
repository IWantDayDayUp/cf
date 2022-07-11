#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define PI 3.1415926

void slove() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x, y, d;
    cin >> x >> y >> d;

    const double pi = acos(-1.0);
    d = d / 180.0 * pi;

    double ang = atan2(y, x) + d;
    double len = sqrt(x * x + y * y);

    cout << fixed << setprecision(17) << cos(ang) * len << " " << sin(ang) * len << endl;

    return 0;
}