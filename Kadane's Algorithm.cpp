
//Kadane's Algorithm

#include <iostream>
using namespace std;

int maxSumSubArray(int arr[], int n)
{
    // initialize maxValue as first element.
    int maxValue = arr[0];
    int currMax = arr[0];
    
    // Update the  value if we have better subarray.
    for(int i = 1; i < n; i++) {
        currMax = max(currMax + arr[i], arr[i]);
        maxValue = max(maxValue, currMax);
    }
    
    // Retrun max value.
    return maxValue;
}

int main() {
    
    // n = no of element in array.
    int n;
    cin >> n;
    
    //Array to store all emelment of array
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Function calling.
    cout << maxSumSubArray(arr, n) << endl;
    
	return 0;
}
