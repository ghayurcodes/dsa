#include <iostream>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    // Base case: if start crosses end, it means all characters matched
    if (start >= end) {
        return true;
    }
    // If characters at start and end do not match, it's not a palindrome
    if (str[start] != str[end]) {
        return false;
    }
    // Recursive call moving towards the center of the string
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << str << " is a palindrome.\n";
    } else {
        cout << str << " is not a palindrome.\n";
    }

    return 0;
}
