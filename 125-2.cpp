/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.length() - 1;
        while(beg < end) {
            while(beg < end && !isalpha(s[beg]) && !isdigit(s[beg])) {
                beg++;
            }
            while(beg < end && !isalpha(s[end]) && !isdigit(s[end])) {
                end--;
            }
            if(tolower(s[beg]) != tolower(s[end])) {
                return false;
            }
            beg++;
            end--;
        }
        return true;
    }
};
