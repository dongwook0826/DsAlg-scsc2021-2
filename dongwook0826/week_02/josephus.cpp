#include <iostream>
#include <queue>
using namespace std;

// Problem 11866

int main() {
    string s;
    cin >> s;
    int N = stoi(s);
    cin >> s;
    int K = stoi(s);
    queue<int> jq;
    for (int n = 1; n <= N; n++)
        jq.push(n);
    cout << '<';
    while (1) {
        for (int i = 1; i < K; i++) {
            jq.push(jq.front());
            jq.pop();
        }
        cout << jq.front();
        jq.pop();
        if (jq.empty()) {
            cout << ">\n";
            break;
        } else {
            cout << ", ";
        }
    }
    return 0;
}