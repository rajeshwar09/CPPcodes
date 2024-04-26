#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int maxSumSubarray(const vector<int>& nums, int k) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < k; i++) 
        currentSum += nums[i];
    
    maxSum = currentSum;

    for (int i = k; i < nums.size(); i++) {
        currentSum = currentSum + nums[i] - nums[i-k];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;

}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 6, 8, 2, 0, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    int k = 3;

    int maxSum = maxSumSubarray(nums, k);
    
    cout << "Maximum sum of subarray with length " << k << " : " << maxSum << endl;

    return 0;
}
