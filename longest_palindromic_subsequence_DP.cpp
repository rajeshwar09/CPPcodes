#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printDPmatrix(const vector<vector<int>>& dp) {
    cout << "Matrix :" << endl;
    for (const auto& row : dp) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
}

pair<string, int> longestPalindromicSubsequence(const string& str) {
    int strlen = str.length();
    string longestSubsequence;
    vector<vector<int>> dp(strlen, vector<int>(strlen, 0));

    for (int len = 2; len <= strlen; len++) {
        for (int i = 0; i < strlen - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) dp[i][j] = 2;
            else if (str[i] == str[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);

            printDPmatrix(dp);
        }
    }

    int i  = 0, j = strlen - 1;
    while (i < j) {
        if (str[i] == str[j]) {
            longestSubsequence += str[i];
            i++;
            j--;
        }
        else {
            if (dp[i][j-1] > dp[i+1][j]) j--;
            else i++;
        }
    }

    string secondHalf = longestSubsequence;
    reverse(secondHalf.begin(), secondHalf.end());
    if (i == j) longestSubsequence += str[i];
    longestSubsequence += secondHalf;

    return make_pair(longestSubsequence, dp[0][strlen-1]);
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    pair<string, int> result = longestPalindromicSubsequence(str);
    cout << "Length of the longest palindromic subsequence is: " << result.second << endl;
    cout << "Longest palindromic subsequence: " << result.first << endl;
    return 0;
}
