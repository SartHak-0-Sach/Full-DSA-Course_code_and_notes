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
    cout << "Size of vector:- " << v.size() << endl;
    cout << "Capacity of vector:- " << v.capacity() << "\n"; // since we did shrink to fit above, a new array will be allocated to fit these variables of larger size and old array will be deleted

    cout << "front element of vector:-" << v.front() << endl;
    cout << "back element of vector:-" << v.back() << endl;

    // before pop
    for (auto i : v)
        cout << i << " ";

    v.pop_back();

    // after pop
    for (auto i : v)
        cout << i << " ";

    v.clear();
    cout<<endl;

    // after clearing the array
    for (auto i : v)
        cout << i << " ";

    int m = 3;
    int n = 2;

    cout<<"\n";

    vector<int> v2(m, n);

    for (auto i : v2)
        cout << i << " ";

    vector<int> v3 (v2); // can also copy vectors like this as directly equating 2 arrays is not possible

    cout<<"\nVector V3 is:-\n";
    for (auto i : v3)
        cout << i << " ";
}

void dequeImplementation()
{
    deque<int> d;

    d.push_back(2);
    d.push_front(1);

    for (auto i : d)
        cout << i << " ";

    cout<<endl;

    d.pop_front();
    d.pop_back();

    d.push_back(3);
    d.push_front(2);
    d.push_back(5);
    d.push_front(1);

    cout<<"Print index of element 1:- "<<d.at(1)<<endl;

    cout<<"front element:- "<<d.front()<<"\n";
    cout<<"back element:- "<<d.back()<<"\n";

    cout<<"Empty or not:- "<<d.empty()<<endl;

    cout<<"Size of "

    // d.emplace_back();
    // d.emplace_front();
    // d.emplace(3, 4);


}

void listImplementation()
{

}



// add meaning of this below mentioned code also

/*
#include <iostream>
#include <string>
#include <deque>
 
struct A
{
    std::string s;
 
    A(std::string str) : s(std::move(str)) { std::cout << " constructed\n"; }
 
    A(const A& o) : s(o.s) { std::cout << " copy constructed\n"; }
 
    A(A&& o) : s(std::move(o.s)) { std::cout << " move constructed\n"; }
 
    A& operator=(const A& other)
    {
        s = other.s;
        std::cout << " copy assigned\n";
        return *this;
    }
 
    A& operator=(A&& other)
    {
        s = std::move(other.s);
        std::cout << " move assigned\n";
        return *this;
    }
};
 
int main()
{
    std::deque<A> container;
 
    std::cout << "construct 2 times A:\n";
    A two { "two" };
    A three { "three" };
 
    std::cout << "emplace:\n";
    container.emplace(container.end(), "one");
 
    std::cout << "emplace with A&:\n";
    container.emplace(container.end(), two);
 
    std::cout << "emplace with A&&:\n";
    container.emplace(container.end(), std::move(three));
 
    std::cout << "content:\n";
    for (const auto& obj : container)
        std::cout << ' ' << obj.s;
    std::cout << '\n';
}
*/