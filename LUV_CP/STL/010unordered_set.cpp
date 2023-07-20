#include <bits/stdc++.h>
using namespace std;

void printSet( unordered_set<string> &m)
{
    cout << "size : " << m.size() << endl;
    for (auto &i : m) 
    {
        cout << i << endl;
    }
}

int main()
{

    unordered_set<string> s; //unique elements and sorted , complex dataStructures cannot be stored
    s.insert("abc");
    s.insert("abcdsc"); // insertion - O(1)
    s.insert("asdf");
    s.insert("aadcc");

    printSet(s);

    auto it = s.find("abc"); // O(1) //returns s.end() if element is not present
    if (it != s.end())
    {
        cout << *it;
        s.erase(*it);
    }
    printSet(s);
    return 0;
}