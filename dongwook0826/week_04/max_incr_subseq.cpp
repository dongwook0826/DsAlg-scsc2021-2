#include <iostream>
using namespace std;

// Problem 12015

void update_arr(int*, int&, int);

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;
    int arr[N];
    cin >> arr[0];
    int maxl = 1;
    for (int i = 1, elem; i < N; i++) {
        cin >> elem;
        update_arr(arr, maxl, elem);
    }
    cout << maxl << '\n';
}

void update_arr(int* arr, int &maxl, int elem) {
    // TODO add
    int hp = maxl - 1;
    if (arr[hp] < elem) {
        arr[maxl++] = elem;
        return;
    } else if (arr[0] > elem) {
        arr[0] = elem;
        return;
    }
    int lp = 0, mp;
    while (lp <= hp) {
        mp = (lp + hp) / 2;
        if (arr[mp] == elem)
            return;
        else if (arr[mp] < elem)
            lp = mp + 1;
        else
            hp = mp - 1;
    }
    arr[lp] = elem;
}
