#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem 18870

typedef struct _INT_PAIR {
    int first;
    int second;
} int_pair;

int main() {
    int N;
    cin >> N;
    vector<int_pair> coords(N);
    for (int i = 0; i < N; i++) {
        cin >> coords[i].first;
        coords[i].second = i;
    }
    sort(coords.begin(), coords.end(),
        [](int_pair &co1, int_pair &co2) { return co1.first < co2.first; });
    for (int i = 0, cur = coords[0].first, cmp = 0; i < N; i++) {
        if (coords[i].first == cur) {
            coords[i].first = cmp;
        } else {
            cur = coords[i].first;
            coords[i].first = ++cmp;
        }
    }
    int comp_coords[N];
    for (int i = 0; i < N; i++)
        comp_coords[coords[i].second] = coords[i].first;
    cout << comp_coords[0];
    for (int i = 1; i < N; i++)
        cout << ' ' << comp_coords[i];
    cout << '\n';
}
