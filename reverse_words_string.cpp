#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

string reverseWords(string s) {
    vector<string> v;
    int start = 0, end = 0;
    char delimiter = ' ';
    string result;

    while ((start = s.find_first_not_of(delimiter, end)) != string::npos) {
        end = s.find(delimiter, start);
        v.push_back(s.substr(start, end - start));
    }

    for (int i = v.size() - 1; i > 0; i--) {
        result += v[i] + " ";
    }

    result += v[0];

    return result;
}

// Other method (fast)

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    string ans;
    while(ss>>word){
        reverse(word.begin(),word.end());
        ans+=word;
        ans+=" ";
    }
    reverse(ans.begin(),ans.end());
    return ans.substr(1,ans.length());
}

int main(int argc, char const *argv[])
{
    cout << reverseWords("  a b    cd     ");
    return 0;
}
