#include <iostream>
#include <string>
#include <stack>
using namespace std;

int C;

bool isWellMatched(string& s) {
    stack<char> openStack;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') openStack.push(s[i]);
        else {
            if(openStack.size() == 0) return false;
            char& uppermost_char = openStack.top();
            openStack.pop();
            if(s[i] == ')' && uppermost_char != '(') return false;
            if(s[i] == '}' && uppermost_char != '{') return false;
            if(s[i] == ']' && uppermost_char != '[') return false;
        }
    }
    return openStack.empty();
}

int main(void) {
    cin >> C;
    while(C--) {
        string s;
        cin >> s;
        cout << (isWellMatched(s) == true ? "YES" : "NO") << endl;
    }
    return 0;
}