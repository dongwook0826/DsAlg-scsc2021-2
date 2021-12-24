#include <iostream>
using namespace std;

// Problem 11279

void heap_push(int*, int&, int);
int heap_pop(int*, int&);

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;
    int heap[N];
    int size = 0;
    for (int i = 0, input; i < N; i++) {
        cin >> input;
        if (input) {
            heap_push(heap, size, input);
        } else {
            cout << heap_pop(heap, size) << '\n';
        }
    }
}

void heap_push(int *heap, int& size, int elem) {
    heap[size++] = elem;
    for (int ind = size-1, par = (ind-1)/2;
         ind > 0; ind = par, par = (par-1)/2) {
        if (heap[ind] > heap[par])
            swap(heap[ind], heap[par]);
        else break;
    }
}

int heap_pop(int *heap, int& size) {
    if (size <= 0) return 0;
    int max = heap[0];
    heap[0] = heap[--size];
    heap[size] = 0;
    for (int ind = 0, ch1 = 1, ch2 = 2; ch1 < size;) {
        if (ch2 >= size) {
            if (heap[ind] < heap[ch1])
                swap(heap[ind], heap[ch1]);
            break;
        }
        if (heap[ch1] > heap[ch2]) {
            if (heap[ind] < heap[ch1]) {
                swap(heap[ind], heap[ch1]);
                ind = ch1;
            } else break;
        } else {
            if (heap[ind] < heap[ch2]) {
                swap(heap[ind], heap[ch2]);
                ind = ch2;
            } else break;
        }
        ch1 = ind * 2 + 1;
        ch2 = ch1 + 1;
    }
    return max;
}
