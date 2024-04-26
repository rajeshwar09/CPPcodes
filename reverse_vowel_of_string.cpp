#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string reverseVowels(string s) {
    string vowels = "aeiouAEIOU";
    string vowel_list;

    for (int i = 0; i < s.length(); i++) {
        if (vowels.find(s[i]) != string::npos)
            vowel_list += s[i];
    }
    cout << vowel_list << endl;

    for (int i = 0, j = vowel_list.length() - 1; i < s.length(); i++) {
        if (vowels.find(s[i]) != string::npos)
            s[i] = vowel_list[j--];
    }

    return s;
}

// Another method (less time)
string reverseString(string &s){
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            v.push_back(i);
    }
    for(int start=0,end=v.size()-1;start<end;start++, end--){
        swap(s[v[start]],s[v[end]]);
    }
    return s;
}
string reverseVowels(string s) {
    reverseString(s);
    return s;
}

int main(int argc, char const *argv[])
{
    string s = "Aa";
    cout << reverseVowels(s) << endl;
    return 0;
}
