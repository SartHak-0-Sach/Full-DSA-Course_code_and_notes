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
    cout << endl;

    // after clearing the array
    for (auto i : v)
        cout << i << " ";

    int m = 3;
    int n = 2;

    cout << "\n";

    vector<int> v2(m, n);

    for (auto i : v2)
        cout << i << " ";

    vector<int> v3(v2); // can also copy vectors like this as directly equating 2 arrays is not possible

    cout << "\nVector V3 is:-\n";
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

    cout << endl;

    d.pop_front();
    d.pop_back();

    d.push_back(3);
    d.push_front(2);
    d.push_back(5);
    d.push_front(1);

    cout << "Print index of element 1:- " << d.at(1) << endl;

    cout << "front element:- " << d.front() << "\n";
    cout << "back element:- " << d.back() << "\n";

    cout << "Empty or not:- " << d.empty() << endl;

    cout << "Size of deque:- " << d.size() << endl;

    // d.emplace_back();
    // d.emplace_front();
    // d.emplace(3, 4);

    for (auto i : d)
        cout << i << " ";

    d.erase(d.begin(), d.begin() + 2);

    for (auto i : d)
        cout << i << " ";

    cout << "\nErasing elements from deque:-\n";
    d.clear();
}

void listImplementation()
{
    list<int> demoList;

    // Add elements to the List
    demoList.push_back(10);
    demoList.push_back(20);
    demoList.push_back(30);
    demoList.push_back(40);
    demoList.push_back(50);

    // Printing elements of list before deleting
    // first element
    cout << "List before deleting first element: ";
    for (auto itr = demoList.begin(); itr != demoList.end(); itr++)
        cout << *itr << " ";

    // Creating iterator to point to first
    // element in the list
    list<int>::iterator itr = demoList.begin();

    // deleting the first element
    demoList.erase(itr);

    // Printing elements of list after deleting
    // first element
    cout << "\nList after deleting first element:";
    for (auto itr = demoList.begin(); itr != demoList.end(); itr++)
        cout << *itr << " ";

    list<int> l;
    list<int> n(5, 100);

    cout << "Printing n:- " << endl;
    for (auto i : n)
        cout << i << " ";
    cout << endl;

    l.push_back(3);
    l.push_front(2);
    l.push_back(5);
    l.push_front(1);

    for (int i : l)
        cout << i << " ";
    cout << endl;

    l.erase(l.begin());
    cout << "Elements after erase:- " << endl;
    for (int i : l)
        cout << i << " ";

    cout << "Size of list:- " << l.size() << endl;
}

void stackImplementation()
{
    stack<string> s;
    s.push("love");
    s.push("babbar");
    s.push("course");

    cout << "Topmost element:- " << s.top() << endl;

    // for (auto i : s)
    //     cout << i << " "; // will give error
    // cout << endl;

    s.pop();
    cout << "Topmost element:- " << s.top() << endl;

    // for (auto i : s)
    //     cout << i << " "; // will give error
    // cout << endl;

    cout << "Size of stack:- " << s.size() << endl;

    cout << "Empty or not:- " << s.empty() << endl;
}

void queueImplementation()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Front element:- " << q.front() << endl;
    cout << "Back element:- " << q.back() << endl;

    // for (auto i : q)
    //     cout << i << " "; // will give error
    // cout << endl;

    q.pop();
    cout << "Front element:- " << q.front() << endl;
    cout << "Back element:- " << q.back() << endl;

    // for (auto i : q)
    //     cout << i << " "; // will give error, reason mentioned at the end of code
    // cout << endl;

    cout << "Size of queue:- " << q.size() << endl;
    cout << "Empty or not:- " << q.empty() << endl;
}

void priority_queueImplementation()
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(5);
    maxi.push(1);
    maxi.push(10);
    maxi.push(30);
    maxi.push(20);

    cout << "Size of priority queue:- " << maxi.size() << endl;
    cout << "Topmost element:- " << maxi.top() << endl;

    maxi.pop();
    cout << "Topmost element after pop:- " << maxi.top() << endl;

    cout << "Size of priority queue:- " << maxi.size() << endl;

    int n = maxi.size();

    // for (int i = 0; i < maxi.size(); i++) // this condition looks right but is wrong for traversal as we are popping so size is changing
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    mini.push(0);
    mini.push(2);
    mini.push(1);
    mini.push(5);
    mini.push(8);

    int m = mini.size();

    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "Empty or not? " << mini.empty() << endl;
}

void setImplementation()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(3);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << "Is -5 present or not? " << s.count(-5) << endl;

    set<int>::iterator itr = s.find(5);

    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void mapImplementation()
{
    map<int, string> m;

    m[1] = "love";
    m[2] = "babbar";
    m[3] = "course";

    m.insert({5, "bheem"});

    string myName = "Sarthak";

    m.insert({7, myName});

    cout << "Elements before erase:- " << endl;

    for (auto i : m)
        cout << i.first << " " << i.second << endl;
    cout << endl
         << endl;

    auto it = m.find(5);

    for (auto i = it; i != m.end(); i++)
        cout << (*i).first << endl;
    // can also be done by declaring iterator as done in set
}

void algoImplementation()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(8);
    v.push_back(4);

    cout << "Finding 6-> " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "Lower bound of 4:- " << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl;
    cout << "Upper bound of 4:- " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;

    int a = 3;
    int b = 5;

    cout << "max element out of a and b is:- " << max(a, b) << endl;
    cout << "min element out of a and b is:- " << min(a, b) << endl;

    swap(a, b);

    cout << endl
         << "a-> " << a << endl;

    string sample = "abcddcbaabcddcba";

    reverse(v.begin(), v.begin() + 8);

    cout << sample << endl;

    rotate(v.begin(), v.end() - 3, v.end());

    cout << "Vector after rotating:- " << endl;

    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

struct A
{
    std::string s;

    A(std::string str) : s(std::move(str)) { std::cout << " constructed\n"; }

    A(const A &o) : s(o.s) { std::cout << " copy constructed\n"; }

    A(A &&o) : s(std::move(o.s)) { std::cout << " move constructed\n"; } // understand this code also

    A &operator=(const A &other)
    {
        s = other.s;
        std::cout << " copy assigned\n";
        return *this;
    }

    A &operator=(A &&other)
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
    A two{"two"};
    A three{"three"};

    std::cout << "emplace:\n";
    container.emplace(container.end(), "one");

    std::cout << "emplace with A&:\n";
    container.emplace(container.end(), two);

    std::cout << "emplace with A&&:\n";
    container.emplace(container.end(), std::move(three));

    std::cout << "content:\n";
    for (const auto &obj : container)
        std::cout << ' ' << obj.s;
    std::cout << '\n';
}

/*
Reason is:-

In C++, the Standard Template Library (STL) provides containers like stacks and queues for managing data. However, these containers do not support direct iteration using a range-based for loop like arrays or vectors do. The reason for this limitation lies in the design and purpose of these containers.

Starting with stacks, they are designed to follow the Last In, First Out (LIFO) principle, meaning the element most recently added is the first one to be removed. The standard stack container does not provide iterators that allow traversal from the top to the bottom like a range-based for loop would require. Instead, stack operations are typically limited to pushing elements onto the top of the stack and popping elements off from the top. This design simplifies the interface and ensures efficient stack operations but doesn't align with the expectations of a range-based for loop.

On the other hand, queues adhere to the First In, First Out (FIFO) principle, where elements are inserted at the back and removed from the front. While queues do support iterators, the standard queue container's iterators are designed for specific purposes like enqueueing and dequeueing elements rather than arbitrary traversal. Therefore, attempting to use a range-based for loop directly with a queue might not produce the desired behavior due to the way its iterators are implemented.

To iterate through a stack or queue, you would typically resort to traditional methods such as using loops with specific operations like popping elements from the stack or dequeuing elements from the queue until they are empty. Alternatively, you could copy the contents of the stack or queue into a different container like a vector, which does support range-based for loops, and then iterate over that container instead. This approach allows you to achieve the desired iteration behavior while working within the constraints of the STL containers.
*/

// So we do it this way
void iterateContainers()
{
    // Stack
    std::stack<int> myStack;
    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Stack: ";
    // To iterate through the stack, you need to pop elements until it's empty
    while (!myStack.empty())
    {
        int element = myStack.top(); // Access the top element
        // Process the element as needed
        std::cout << element << " ";
        myStack.pop(); // Remove the top element
    }
    std::cout << std::endl;

    // Queue
    std::queue<int> myQueue;
    // Enqueue some elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Queue: ";
    // To iterate through the queue, you dequeue elements until it's empty
    while (!myQueue.empty())
    {
        int element = myQueue.front(); // Access the front element
        // Process the element as needed
        std::cout << element << " ";
        myQueue.pop(); // Remove the front element
    }
    std::cout << std::endl;

    // Priority Queue
    std::priority_queue<int> myPriorityQueue;
    // Insert some elements into the priority queue
    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(2);

    std::cout << "Priority Queue: ";
    // To iterate through the priority queue, you can't directly access elements in sorted order
    // Instead, you need to dequeue elements until it's empty
    while (!myPriorityQueue.empty())
    {
        int element = myPriorityQueue.top(); // Access the top (highest priority) element
        // Process the element as needed
        std::cout << element << " ";
        myPriorityQueue.pop(); // Remove the top element
    }
    std::cout << std::endl;
}