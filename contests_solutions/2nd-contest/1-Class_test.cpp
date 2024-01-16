#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int classTest(int n, vector<int> &a, int k) {
    std::sort(a.begin(), a.end());
    return a[n-k];
}