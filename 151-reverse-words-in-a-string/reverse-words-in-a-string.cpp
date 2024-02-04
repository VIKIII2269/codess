#include <iostream>

class Solution {
public:
    string reverseWords(string s) {
        string result = "", word = "";
        
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            
            if (!word.empty()) {
                result = (result.empty() ? word : word + " " + result);
                word = "";
            }
        }

        return result;
    }
};
