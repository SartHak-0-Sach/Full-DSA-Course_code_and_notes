#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int findMaxX(int n, vector<vector<int>> &arr, int B)
{
    int size=arr.size();
    int x=1;
    int row=arr.size();
    int sum=0;
    int i=0;
    int j=0;
        for(i=0;i<row;i++)
        {
            sum+=accumulate(arr[i].begin()+1,arr[i].end(),0);
        }
        vector<int>y;
        for(i=0;i<row;i++)
        {
           for(j=1;j<arr[i].size();j++)
           {
               y.push_back(arr[i][j]);
           } 
        }
        sort(y.begin(),y.end());
        i=y.size()-1;
        j=y[y.size()-1];
       while(i>=0)
       {
           if(sum<=B)
           {
               return j;
           }
           else
           {
               sum=sum-y[i];
               j=y[i]-1;
               i--;
           }
       }
    return y[0];
}