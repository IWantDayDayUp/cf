#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    auto cmp = [](pair<int, int> &left, pair<int, int> &right)
    { return left.first > right.first; };
    for (int idx = 0; idx < t; ++idx)
    {
        int r;
        cin >> r;
        vector<int> input(r);
        for (int i = 0; i < r; ++i)
            cin >> input[i];
        // process
        int res = input[0];
        int cur = 1, L = 0, R = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>, decltype(cmp)>> pq(cmp);
        for (int right = 0; right < r; ++right)
        {
            pq.push()
        }
        for (int left = 0; left < r; ++left)
        {
        }
        cout << res << L << R;
    }
    return 0;
}