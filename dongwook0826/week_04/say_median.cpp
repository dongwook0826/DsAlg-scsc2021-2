#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Problem 1655

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    for (int i = 0, input; i < N; i++) {
        cin >> input;
        if (i & 1) {
            if (lower.top() >= input) {
                lower.push(input);
                upper.push(lower.top());
                lower.pop();
            } else {
                upper.push(input);
            }
        } else {
            if (lower.empty() || lower.top() >= input) {
                lower.push(input);
            } else {
                upper.push(input);
                lower.push(upper.top());
                upper.pop();
            }
        }
        cout << lower.top() << '\n';
    }
}
