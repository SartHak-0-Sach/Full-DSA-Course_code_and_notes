#include <iostream>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <list>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void arrayImplementation()
{
    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    cout << "element at 2nd index:- " << a.at(2) << endl; // 0 indexed property

    cout << "Empty or not? " << a.empty() << endl;

    cout << "First element:- " << a.front() << endl;
    cout << "Last Element :- " << a.back() << endl;
}

void vectorImplementation()
{
    vector<int> v;
    cout << "Capacity of vector:- " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity of vector:- " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity of vector:- " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "New capacity:- " << v.capacity() << endl;
    cout << "Size of vector:- " << v.size() << endl;

    v.push_back(3);
    cout << "Capacity of vector:- " << v.capacity() << "\n"; //since we did shrink to fit above, a new array will be allocated to fit these variables of larger size and old array will be deleted

    
}