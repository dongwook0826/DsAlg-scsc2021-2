#include <iostream>
using namespace std;

// Problem 1654

typedef long long ll;

int main() {
    cin.sync_with_stdio();
    cin.tie(0);

    int K, N;
    cin >> K >> N;
    int cables[K];
    ll sum = 0;
    ll min = 0x7fffffff;
    for (int i = 0; i < K; i++) {
        cin >> cables[i];
        sum += cables[i];
        if (min > cables[i])
            min = cables[i];
    }
    min *= K;

    ll lowl = min / N;
    if (lowl <= 0) lowl = 1;
    ll uppl = sum / N;
    ll midl;
    int N_midl;
    while (lowl <= uppl && uppl > 0) {
        midl = (lowl + uppl) / 2;
        N_midl = 0;
        for (int i = 0; i < K; i++)
            N_midl += cables[i] / midl;
        if (N_midl >= N)
            lowl = midl + 1;
        else
            uppl = midl - 1;
    }
    cout << (uppl <= 0 ? lowl : uppl) << '\n';
}
