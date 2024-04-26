#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, string> longestCommonSubsequence(const string& text1, const string& text2) {
    int size1 = text1.size();
    int size2 = text2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    // DP table
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Reconstruct longest subsequence
    int length = dp[size1][size2];
    string subsequence;
    int i = size1, j = size2;

    while (i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            subsequence = text1[i-1] + subsequence;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return {length, subsequence};
}

int main(int argc, char const *argv[])
{
    string text1 = "abcde";
    string text2 = "ace";

    auto result = longestCommonSubsequence(text1, text2);

    cout << "Length of longest common subsequence : " << result.first << endl;
    cout << "Longest common subsequence : " << result.second << endl;

    return 0;
}
