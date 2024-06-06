#include <iostream>
using namespace std;

void partition(int *arr, int s, int e)
{
	int merge = s + (e-s)/2;
	int len1 = mid-s+1;
	int len2 = e-mid;
	int *first = new int[len1];
	int *second = new int[len2];
	int mainArrayIndex = s;
	for(int i = 0; i<len1; i++)
	first[i]=arr[mainArrayIndex++];

	mainArrayIndex = mid+1;

	for(int i = 0; i<len2; i++)
	second[i]=arr[mainArrayIndex++];

	// merge two sorted arrays
	int index1 = 0;
	int index2 = 0;
	mainArrayIndex = s;

	while(index1<len1 & index2<len2)
	{
		if(first[index1] < second[index2])
		arr[mainArrayIndex++]=first[index1++];

		else
		arr[mainArrayIndex++]=second[index2++];
	}

	while(index1<len1)
	arr[mainArrayIndex++]=first[index1++];

	while(index2<len2)
	arr[mainArrayIndex++]=second[index2++];

	delete []first;
	delete []second;
}

void quickSort(sort *arr, int s, int e)
{
	// base case
	if(s>=e) return;

	// partition karenge
	int p = partition(arr, s, e);

	quickSort(arr, s, mid);
	quickSort(arr, mid+1, e);
}

int main()
{
	int arr[8] = {1,5,6,7,12,34,21,3};

	int n = 8;

	quickSort(arr, 0, n-1);

	for(int i = 0; i<n; i++)
	cout<<arr[i]<<" ";

	return 0;
}