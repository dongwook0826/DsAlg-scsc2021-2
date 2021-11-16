#include <iostream>
#include <stack>
using namespace std;

bool is_balanced(string);

// Problem 4949

int main() {
    string s;
    while (1) {
        getline(cin, s);
        if (s == ".") break;
        cout << (is_balanced(s) ? "yes" : "no") << '\n';
    }
    return 0;
}

bool is_balanced(string s) {
    std::stack<char> pb_stack;
    for (string::iterator si = s.begin(); si != s.end(); si++) {
        if (*si == '(' || *si == '[') {
            pb_stack.push(*si);
        } else if (*si == ')') {
            if (!pb_stack.empty() && pb_stack.top() == '(')
                pb_stack.pop();
            else
                return false;
        } else if (*si == ']') {
            if (!pb_stack.empty() && pb_stack.top() == '[')
                pb_stack.pop();
            else
                return false;
        }
    }
    return pb_stack.empty();
}