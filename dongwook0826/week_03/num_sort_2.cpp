#include <iostream>
using namespace std;

void alt_merge_sort(int*, int*, int, int);
void alt_merge(int*, int*, int, int, int);

// Problem 2751

int main() {
    int N;
    cin >> N;
    int arr[N], aux[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        aux[i] = arr[i];
    }
    alt_merge_sort(arr, aux, 0, N-1);
    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}

void alt_merge_sort(int* arr, int* aux, int lo, int hi) {
    if (lo >= hi) return;
    int md = (lo + hi) / 2;
    alt_merge_sort(aux, arr, lo, md);
    alt_merge_sort(aux, arr, md+1, hi);
    alt_merge(arr, aux, lo, md, hi);
}

void alt_merge(int* arr, int* aux, int lo, int md, int hi) {
    int i = lo;
    int lp = lo, hp = md + 1;
    while (lp <= md && hp <= hi) {
        if (aux[lp] <= aux[hp])
            arr[i++] = aux[lp++];
        else
            arr[i++] = aux[hp++];
    }
    while (lp <= md)
        arr[i++] = aux[lp++];
    while (hp <= hi)
        arr[i++] = aux[hp++];
}
