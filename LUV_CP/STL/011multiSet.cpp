#include <bits/stdc++.h>
using namespace std;

void printSet(multiset<string> &m)
{
    cout << "size : " << m.size() << endl;
    for (auto &i : m)
    {
        cout << i << endl;
    }
}

int main()
{

    multiset<string> s;
    s.insert("abc");
    s.insert("abcdsc"); // O(log n )
    s.insert("asdf");
    s.insert("asdf"); //duplicates allowed
    s.insert("aadcc");

    printSet(s);

    auto it = s.find("asdf"); // O(log n ) , iterator of first element is returned
    if (it != s.end())
    {
        cout << *it;
        //s.erase(it);//only one value is deleted
        s.erase(*it); // if we pass *it then both will be deleted 
    }
    printSet(s);
    return 0;
}