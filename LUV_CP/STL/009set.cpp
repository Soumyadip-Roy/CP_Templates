#include <bits/stdc++.h>
using namespace std;

void printSet(set<string> &m)
{
    cout << "size : " << m.size() << endl;
    for (auto &i : m)
    {
        cout << i << endl;
    }
}

int main()
{

    set<string> s; //unique elements and sorted
    s.insert("abc");
    s.insert("abcdsc"); // O(log n )
    s.insert("asdf");
    s.insert("aadcc");

    printSet(s);

    auto it = s.find("abc"); // O(log n )
    if (it != s.end())
    {
        cout << *it;
        s.erase(*it);
    }
    printSet(s);
    return 0;
}