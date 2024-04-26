#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

using namespace std;

pair<int, string> longestSubstringWithoutRepeat(const string& s) {
    unordered_map<char, int> charIndexMap;
    string longestSubstring;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++) {
        // Check if character is not present in the map
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[end]] + 1);
        }
        charIndexMap[s[end]] = end;
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            longestSubstring = s.substr(start, maxLength);
        }
    }

    return {maxLength, longestSubstring};
}

int main(int argc, char const *argv[])
{
    string s = "abcabcbb";

    auto result = longestSubstringWithoutRepeat(s);

    cout << "Length of longest substring without repeat : " << result.first << endl;
    cout << "Longest substring : " << result.second << endl;
    return 0;
}
