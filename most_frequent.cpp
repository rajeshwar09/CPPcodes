#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

int findTopMostFrequent(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
    int topFrequency = 0;
    int topElement = 0;

    for (int num : nums) frequencyMap[num]++;

    for (const auto& pair: frequencyMap) {
        if (pair.second > topFrequency) {
            topFrequency = pair.second;
            topElement = pair.first;
        }
    }

    return topElement;
}


int main(int argc, char const *argv[]) {
    
    int arr[] = {1, 2, 3, 4, 2, 2, 3, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);

    int topMostFrequent = findTopMostFrequent(nums);

    cout << "Top most frequent element : " << topMostFrequent << endl;
    
    return 0;
}
