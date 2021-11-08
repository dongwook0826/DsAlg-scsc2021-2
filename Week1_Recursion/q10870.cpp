#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAX_N 30

int memo[MAX_N] = {-1, };

int fibonacci(int n){
    if(memo[n] != -1)
        return memo[n];
    
    //if (n == 0 || n == 1)
    //    return n;

    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill_n(memo, MAX_N, -1);
    int n; cin >> n;
    cout << fibonacci(n);

    return 0;
}