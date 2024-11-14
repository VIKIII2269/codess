#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                a.push(s[i]);
            } else {
                if (a.empty()) {
                    return false;
                }
                char c = a.top();
                a.pop();
                if (!((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))) {
                    return false;
                }
            }
        }
        return a.empty();
    }
};
