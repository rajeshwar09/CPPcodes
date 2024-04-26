#include <iostream>

bool is_palindrome (std::string text){
    int i = 0;
    int j = text.size()-1;
    while (i < j) {
        if (text[i] != text[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::string str;
    std::cin >> str;
    std::cout << is_palindrome(str);
    return 0;
}
