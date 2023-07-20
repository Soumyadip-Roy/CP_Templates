#include <bits/stdc++.h>
using namespace std;

void PrintMap(map<pair<string, string>, vector<int>> &m)
{
    for (auto &i : m)
    {
        cout << i.first.first << " " << i.first.second << " ";
        for (auto &e : i.second)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{

    map<pair<int, int>, int> m1; // key s can be any data structure which can be compared
    pair<int, int> p1, p2;
    p1 = {2, 3};
    p2 = {2, 3};
    cout << (p1 == p2);

    map<set<int>, int> m2;
    set<int> s1 = {1, 2, 3, 4};
    set<int> s2 = {3, 4};
    cout << (s1 == s2);

    map<pair<string, string>, vector<int>> m3;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string fn, ln;
        cin >> fn >> ln;
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            int x;
            cin >> x;
            m3[{fn, ln}].push_back(x);
        }
    }

    PrintMap(m3);
    return 0;
}