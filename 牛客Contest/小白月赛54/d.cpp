#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<string> words;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        words.insert(temp);
    }

    string s, t;
    cin >> s >> t;

    queue<pair<string, vector<string>>> q;
    vector<string> ans;
    q.emplace(make_pair(s, ans));

    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            pair<string, vector<string>> p = q.front();
            string cur = q.front().first;
            // vector<string> temp = q.front().second;
            q.pop();

            for (int j = 0; j < m; j++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    string word = cur;
                    word[j] = c;


                    if (word == t)
                    {
                        // cout the ans
                        vector<string> temp = p.second;
                        cout << temp.size() << endl;
                        cout << s << endl;
                        for (auto & w : temp)
                        {
                            cout << w << endl;
                        }
                        cout << t << endl;

                        return 0;
                    }

                    if (words.count(word))
                    {
                        vector<string> temp = p.second;
                        temp.emplace_back(word);
                        q.emplace(make_pair(word, temp));

                        words.erase(word);
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}