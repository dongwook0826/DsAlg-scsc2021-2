#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem 1874

int main() {
    string s;
    getline(cin, s);
    int N = stoi(s);
    stack<int> num_stack;
    vector<bool> pp_seq(N*2, false);
    for (int i = 0, nx = 1, pp = 0; i < N; i++) {
        getline(cin, s);
        int n = stoi(s);
        if (num_stack.empty() || num_stack.top() < n) {
            while (nx <= n) {
                num_stack.push(nx++);
                pp_seq.at(pp++) = true;
            }
            num_stack.pop();
            pp_seq.at(pp++) = false;
        } else if (num_stack.top() == n) {
            num_stack.pop();
            pp_seq.at(pp++) = false;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    for (vector<bool>::iterator b = pp_seq.begin(); b != pp_seq.end(); b++) {
        cout << (*b ? '+' : '-') << '\n';
    }
    return 0;
}