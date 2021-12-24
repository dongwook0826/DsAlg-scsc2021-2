#include <iostream>
#define MAX_LL 0x7fffffffffffffff
using namespace std;
typedef long long ll;

// Problem 1300

ll mat_pos(ll);

ll mat_N;

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    ll K;
    cin >> mat_N >> K;
    
    ll lo_n = 1, hi_n = mat_N * mat_N;
    ll md_n, md_pos;
    while (lo_n <= hi_n) {
        md_n = (lo_n + hi_n) / 2;
        md_pos = mat_pos(md_n);
        if (md_pos < K)
            lo_n = md_n + 1;
        else
            hi_n = md_n - 1;
    }
    cout << lo_n << '\n';
}

ll mat_pos(ll n) {
    if ((n-1) / mat_N >= mat_N) return MAX_LL;
    ll sum = 0;
    for (ll r = mat_N, d; r >= 1; r--) {
        d = n / r;
        if (d >= r) {
            sum <<= 1;
            sum += r * r;
            break;
        }
        sum += d;
    }
    cout << '(' << n << " -> " << sum << ")\n";
    return sum;
}
