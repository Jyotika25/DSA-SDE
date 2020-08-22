/*
APPROACH 1
TIME COMPLEXITY O(N^2)
SPACE COMPLEXITY O(1)
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << " Number of inversions are "
         << getInvCount(arr, n); 
    return 0; 
} 


/*
APPROACH 2
ENHANCED MERGE SORT
TIME COMPLEXITY O(N*LOGN)
SPACE COMPLEXITY O(N)
*/

#include <bits/stdc++.h> 
using namespace std; 
int merge(int arr[], int temp[], int left, 
		int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; 
	j = mid; 
	k = left; 
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 
	while (j <= right) 
		temp[k++] = arr[j++]; 
    
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 

		
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 


int main() 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
  int temp[n];
	int ans = _mergeSort(arr,temp ,0, n-1); 
	cout << " Number of inversions are " << ans; 
	return 0; 
} 

