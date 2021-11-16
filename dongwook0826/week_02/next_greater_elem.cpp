#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem 17298

int main() {
    string s;
    cin >> s;
    int N = stoi(s);
    stack<int> nge_stk;
    vector<int> nge(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> s;
        nge[i] = stoi(s);
    }
    for (int i = N-1; i >= 0; i--) {
        while (!nge_stk.empty() && nge[i] >= nge_stk.top())
            nge_stk.pop();
        if (nge_stk.empty()) {
            nge_stk.push(nge[i]);
            nge[i] = -1;
        } else {
            int tmp = nge[i];
            nge[i] = nge_stk.top();
            nge_stk.push(tmp);
        }
    }
    cout << nge[0];
    for (int i = 1; i < N; i++)
        cout << ' ' << nge[i];
    cout << '\n';
    return 0;
}