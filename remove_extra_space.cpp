#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// void remove_extra_whitespace(const string &input, string &output) {
//     output.clear();
//     unique_copy(input.begin(), input.end(), back_insert_iterator<string>(output), 
//                     [](char a, char b) {return isspace(a) && isspace(b);});
//     cout << output << endl;
// }

void remove_extra_whitespace(const string &input, string &output)
{
    output.clear();  // unless you want to add at the end of existing sring...
    unique_copy (input.begin(), input.end(), back_insert_iterator<string>(output),
                                     [](char a,char b){ return isspace(a) && isspace(b);});  
    cout << output<<endl; 
}

int main(int argc, char const *argv[])
{
    string s = " a  b    c  ";
    string o;
    remove_extra_whitespace(s, o);
    return 0;
}
