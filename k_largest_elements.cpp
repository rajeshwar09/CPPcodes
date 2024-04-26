#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

vector<int> findTopKLargest(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    vector<int> result;

    for (int num : nums) {
        if (minHeap.size() < k) minHeap.push(num);
        else {
            if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}


int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 6, 8, 2, 5, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    int k = 4;

    vector<int> topK = findTopKLargest(nums, k);

    cout << "Top " << k << " largest elements:" << endl;
    for (int num : topK) {
        cout << " " << num;
    }

    cout << endl;

    return 0;
}
