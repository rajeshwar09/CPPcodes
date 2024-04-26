#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);

    int length = longestIncreasingSubsequence(nums);

    cout << "Length of the longest incresing subsequence: " << length << endl;
    return 0;
}
