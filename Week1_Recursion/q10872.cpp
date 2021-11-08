#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    
    return n * factorial(n-1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    cout << factorial(n);

    return 0;
}