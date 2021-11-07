#include <iostream>
int factorial_rec(int);
using namespace std;

int main() {
    int num, result;
    cin >> num;
    result = factorial_rec(num);
    cout << result << endl;
    return 0;
}

int factorial_rec(int n){
    if(n==0){
        return 1;
    }
    else {
        return n*factorial_rec(n-1);
    }
}
