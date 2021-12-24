#include <iostream>
#include <vector>
using namespace std;

// Problem 5639

void pre_to_post(vector<int>&, int, int);

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int input;
    vector<int> pre_result;
    while (cin >> input) {
        if (input == EOF)
            break;
        pre_result.push_back(input);
    }
    pre_to_post(pre_result, 0, pre_result.size());
}

void pre_to_post(vector<int> &pre, int begin, int end) {
    if (begin >= end) return;
    int lo = begin + 1, hi = end - 1;
    int md;
    while (lo <= hi) {
        md = (lo + hi) / 2;
        if (pre[md] < pre[begin])
            lo = md + 1;
        else
            hi = md - 1;
    }
    pre_to_post(pre, begin + 1, lo);
    pre_to_post(pre, lo, end);
    cout << pre[begin] << '\n';
}
