#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
        if (i == start || candidates[i] != candidates[i-1]) {
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i+1);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    backtrack(result, combination, candidates, target, 0);
    
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 6, 8, 2, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> candidates(arr, arr + n);
    int target = 12;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << " are:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << " ]\n";
    }

    return 0;
}
